/*
** EPITECH PROJECT, 2019
** square
** File description:
** my_streetart.c
*/

#include "include/framebuffer.h"

int fycalc(int y, int fy, int f)
{
    if (f >= 0) {
        y--;
        fy += 2;
        f += fy;
    }
    return (y, fy, f);
}

void my_put_square(framebuffer_t *framebuffer, int x0, int y0, sfColor color)
{
    int radius = random_radius();

    my_put_pixel(framebuffer, x0, y0 + radius, color);
    my_put_pixel(framebuffer, x0, y0 - radius, color);
    my_put_pixel(framebuffer, x0 + radius, y0, color);
    my_put_pixel(framebuffer, x0 - radius, y0, color);

    for (int f = 1,
            fx = 0,
            fy = -2 * radius,
            x = 0,
            y = radius;
            x < y; ) {
        fycalc(y, fy, f);
        x++;
        fx += 2;
        f += fx - 1;

        my_put_pixel(framebuffer, x0 + x, y0 + y, color);
        my_put_pixel(framebuffer, x0 - x, y0 + y, color);
        my_put_pixel(framebuffer, x0 + x, y0 - y, color);
        my_put_pixel(framebuffer, x0 - x, y0 - y, color);
        my_put_pixel(framebuffer, x0 + y, y0 + x, color);
        my_put_pixel(framebuffer, x0 - y, y0 + x, color);
        my_put_pixel(framebuffer, x0 + y, y0 - x, color);
        my_put_pixel(framebuffer, x0 - y, y0 - x, color);
    }
}
