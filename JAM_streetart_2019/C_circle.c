/*
** EPITECH PROJECT, 2019
** circle
** File description:
** my_streetart
*/

#include "include/framebuffer.h"

void my_put_circle(framebuffer_t *framebuffer, int xm, int radius, sfColor color)
{
    int ym = 600;
    int x = -radius;
    int y = 0;
    int error = 2 - 2 * radius;

    while (x < 0) {
        my_put_pixel(framebuffer, xm - x, ym + y, color);
        my_put_pixel(framebuffer, xm - y, ym - x, color);
        my_put_pixel(framebuffer, xm + x, ym - y, color);
        my_put_pixel(framebuffer, xm + y, ym + x, color);
        radius = error;
        if (radius > x) {
            x++;
            error += x * 2 + 1;
        }
        if (radius <= y) {
            y++;
            error += y * 2 + 1;
        }
    }
}
