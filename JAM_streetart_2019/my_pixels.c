/*
** EPITECH PROJECT, 2019
** pixels
** File description:
** my_streetart
*/

#include "include/framebuffer.h"

void draw_pixels(framebuffer_t *framebuffer, sfColor color)
{
    int x = rand() % 1920;
    int y = rand() % 1080;

    my_put_pixel(framebuffer, x, y, color);
}
