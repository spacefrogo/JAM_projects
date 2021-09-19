//
// EPITECH PROJECT, 2020
// Cpp rush3
// File description:
// display
//

#ifndef ENGINEDISPLAY_HPP_
#define ENGINEDISPLAY_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../include/CoronaStats.hpp"
void show_shapeCpu(sf::RenderWindow *window, int _x, int _y, int _size, int len);
void showGraph();
void display_graph(sf::RenderWindow *window, int _x, int _y, int _sizex,
		    int _sizey, int value);
void showCore(sf::RenderWindow *window, double g, double r, double s, int i);
void show_CPU(sf::RenderWindow *window, int );
void show_name(sf::RenderWindow *);
void show_shape(sf::RenderWindow *, int, int, int);
void show_title(sf::RenderWindow *, std::string, int, int);
void show_text(sf::RenderWindow *, std::string, int, int);
void show_shape2(sf::RenderWindow *, int, int, int, int, int);
void show_title2(sf::RenderWindow *, std::string, int, int);
void show_text2(sf::RenderWindow *, std::string, int, int, int);

#endif /* !ENGINEDISPLAY_HPP_ */
