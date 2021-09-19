/*
** EPITECH PROJECT, 2019
** draw line
** File description:
** my_streetart
*/

#include "include/framebuffer.h"

void drawline(framebuffer_t *framebuffer, int x0, int y0, sfColor color)
{
    int x1 = 1920;
    int y1 = 1080;
    int dx = x1 - x0;
    int dy = y1 - y0;
    int p = 2 * dy - dx;
    int x = x0;
    int y = y0;

    for (; x < x1; x++) {
        my_put_pixel(framebuffer, x, y, color);
        if (p >= 0) {
            y++;
            p += 2 * dy - 2 * dx;
        } else
            p += 2 * dy;
    }
}
