/*
** EPITECH PROJECT, 2019
** the head
** File description:
** my_streetart
*/

#include "include/framebuffer.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *pointer = malloc(sizeof(framebuffer_t));

    pointer->width = width;
    pointer->height = height;
    pointer->pixels = malloc(width * height *4);
    return pointer;
}

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color)
{
    if (x < 1919 && y < 1079 && x >= 0 && y >= 0) {
        x *= 4;
        y *= 4;
        framebuffer->pixels[framebuffer->width * y + x] = color.r;
        framebuffer->pixels[framebuffer->width * y + x + 1] = color.g;
        framebuffer->pixels[framebuffer->width * y + x + 2] = color.b;
        framebuffer->pixels[framebuffer->width * y + x + 3] = color.a;
    }
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}
