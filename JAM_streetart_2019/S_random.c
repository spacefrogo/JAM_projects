/*
** EPITECH PROJECT, 2019
** random
** File description:
** streetart
*/

#include "include/framebuffer.h"

sfColor my_rgba(sfUint8 r, sfUint8 g, sfUint8 b, sfUint8 a)
{
    sfColor color = { .r = r, .g = g, .b = b, .a = a};

    return color;
}

int random_x(void)
{
    return rand() % 1920;
}

int random_y(void)
{
    return rand() % 1080;
}

int random_radius(void)
{
    return rand() % 500;
}
