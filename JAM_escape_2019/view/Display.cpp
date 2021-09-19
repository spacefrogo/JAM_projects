//
// EPITECH PROJECT, 2020
// Cpp rush3
// File description:
// display
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "Display.hpp"

void showGraph()
{
    sf::RenderWindow window(sf::VideoMode(810, 600), "Escape Epitech");
    CoronaStats g;
    int f = 1;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        window.clear(sf::Color::Red);
        sf::Texture texture;
        texture.loadFromFile("./assets/cor.jpg");
        sf::Sprite background(texture);
        window.draw(background);
        show_name(&window);
        show_CPU(&window, f);
        show_name(&window);
        g.main_loop();
       
        for (int i = 0; i < 4; i++)
            showCore(&window, g.g, g.r, g.s, i);
        window.display();
        f++;
    }
}

void show_name(sf::RenderWindow *window)
{
    show_text2(window, "Corona Escape", 70, 70, 40);
}

void show_CPU(sf::RenderWindow *window, int f)
{
    std::ostringstream tmp;
    if (f < 7)
        tmp << "Write 7 values to show the result ";
    else
        tmp << "Day is "<< f;
       
    std::string str(tmp.str());
    show_shapeCpu(window, 0, 145, 50, 400);
    show_text(window, str, 20.0f, 160);
}

void showCore(sf::RenderWindow *window, double g, double r, double s, int i)
{
    int size_g = g * 100 / 50;
    int size_r = r * 100 / 50;
    int size_s = s * 100 / 50;
    std::string g_str = std::to_string((int)g); 
    std::string r_str = std::to_string((int)r); 
    std::string s_str = std::to_string((int)s);
    g_str.append("%");
    r_str.append("%");
    s_str.append("%");
   
    if (size_g > 250)
        size_g = 250;
    show_shapeCpu(window, 0, 210, 50, 300);
    show_shapeCpu(window, 0, 210 + 65, 50, 300);
    show_shapeCpu(window, 0, 210 + 130, 50, 300);
    show_shapeCpu(window, 0, 210 + 195, 50, 300);
    show_title(window, "Percentage raised compared \nwith last week : ", 20.0f, 220);
    show_title(window, "Percentage reduced compared \nwith last week : ", 20.0f, 220 + 65);
    show_title(window, "Increase average of cases : ", 20.0f, 235 + 130);
    show_title(window, "Standart deviation for last week : ", 20.0f, 235 + 195);
    show_text(window, g_str, 245.0f, 238 + 130);
    show_text(window, s_str, 245.0f, 238 + 195);
   
    if (r < 0) {
        r = r * (-1);
        size_r = r * 100 / 50;
        show_text(window, r_str, 245.0f, 238 + 65);
        display_graph(window, 210 + 65, 320 , 50 , size_r, size_r);
    } else { 
        display_graph(window, 210, 320 , 50 , size_r, size_r);
        show_text(window, r_str, 245.0f, 238 + 0);
    }
    display_graph(window, 210 + 130, 320 , 50 , size_g, size_g);
    display_graph(window, 210 + 195, 320 , 50 , size_s, size_s);
}

void display_graph(sf::RenderWindow *window, int _x, int _y, int _sizex,
           int _sizey, int value)
{
    sf::RectangleShape rectangle;

    rectangle.setSize(sf::Vector2f(_sizey, _sizex));
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setOutlineThickness(3);
    rectangle.setPosition(_y, _x);
    window->draw(rectangle);
}

void show_shape(sf::RenderWindow *window, int _x, int _y, int _size)
{
    sf::RectangleShape rect;

    rect.setFillColor(sf::Color::Transparent);
    rect.setPosition(_x, _y);
    rect.setSize(sf::Vector2f(150, _size));
    rect.setOutlineColor(sf::Color::Cyan);
    rect.setOutlineThickness(2);
    window->draw(rect);
}

void show_shapeCpu(sf::RenderWindow *window, int _x, int _y, int _size, int length)
{
    sf::RectangleShape rect;

    rect.setFillColor(sf::Color::White);
    rect.setPosition(_x, _y);
    rect.setSize(sf::Vector2f(length, _size));
    rect.setOutlineColor(sf::Color::Cyan);
    rect.setOutlineThickness(2);
    window->draw(rect);
}

void show_date(sf::RenderWindow *window, int _x, int _y, int _size)
{
    sf::RectangleShape rect;

    rect.setFillColor(sf::Color::Transparent);
    rect.setPosition(_x, _y);
    rect.setSize(sf::Vector2f(250, _size));
    rect.setOutlineColor(sf::Color::Cyan);
    rect.setOutlineThickness(2);
    window->draw(rect);
}

void show_title(sf::RenderWindow *window, std::string _text, int _x, int _y)
{
    sf::Font font;
    sf::Text text;
    sf::FloatRect textRect = text.getLocalBounds();

    text.setFont(font);
    text.setString(_text);
    text.setCharacterSize(14);
    text.setColor(sf::Color::Blue);
    text.setOrigin(textRect.left + textRect.width/2.0f,
            textRect.top  + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(_x, _y - 4));
    font.loadFromFile("assets/font.ttf");
    window->draw(text);
}

void show_text(sf::RenderWindow *window, std::string _text, int _x, int _y)
{
    sf::Font font;
    sf::Text text;
    sf::FloatRect textRect = text.getLocalBounds();

    text.setFont(font);
    text.setString(_text);
    text.setCharacterSize(12);
    text.setColor(sf::Color::Magenta);
    text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(_x, _y - 5));
    font.loadFromFile("assets/font.ttf");
    window->draw(text);
}

void show_text2(sf::RenderWindow *window, std::string _text, int _x, int _y, int size)
{
    sf::Font font;
    sf::Text text;

    text.setFont(font);
    text.setString(_text);
    text.setCharacterSize(size);
    text.setColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(_y, _x);
    font.loadFromFile("assets/font.ttf");
    window->draw(text);
}
