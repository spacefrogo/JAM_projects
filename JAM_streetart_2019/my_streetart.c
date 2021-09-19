
/*
** EPITECH PROJECT, 2019
** streetart
** File description:
** streetart
*/
#include "include/framebuffer.h"

int errors(int ac, char **av)
{
    if (ac != 2)
        exit(84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        h_flag();
        exit(84);
    }
    if (av[1][0] == '-' && av[1][1] == 'd') {
        d_flag();
        exit(84);
    }
    if (av[1][0] < '-' || (av[1][0] > '-' && av[1][0] < '0') || av[1][0] > '6')
        exit(84);
}

int main(int ac, char **av)
{
    errors(ac, av);
    sfVideoMode mode = {1920, 1080, 64};
    sfRenderWindow* window =  sfRenderWindow_create(mode, "", sfResize | sfClose, NULL);
    sfTexture* texture = sfTexture_create(1920, 1080);
    framebuffer_t *framebuffer = framebuffer_create(1920, 1080);
    sfSprite* sprite = sfSprite_create();
    sfEvent event;
    if (!window || !texture)
        return EXIT_FAILURE;
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.key.code == sfKeyEscape || event.type == sfEvtClosed){
                sfRenderWindow_close(window);
                sfRenderWindow_clear(window, sfBlack);
            }

        sfTexture_updateFromPixels(texture, framebuffer->pixels, 1920, 1080, 0, 0);
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfColor random = my_rgba(rand(), rand(), rand(), rand());

        switch (av[1][0]) {
            case '1': my_put_square(framebuffer, random_x(), random_y(), random);
                      break;
            case '2': my_put_circle(framebuffer, random_x(), 300, random);
                      break;
            case '3': drawline(framebuffer, random_x(), random_y(), random);
                      break;
            case '4': splash_i(framebuffer, rand() % 250, random);
                      break;
            case '5': draw_pixels(framebuffer, random);
                      break;
            case '6': my_put_square(framebuffer, 230, 900, random);
                      my_put_square(framebuffer, 1400, 100, random);
                      break;
            default:
                      break;
        }
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }

    framebuffer_destroy(framebuffer);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return 0;
}
