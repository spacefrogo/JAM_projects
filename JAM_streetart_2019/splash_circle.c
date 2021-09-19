/*
** EPITECH PROJECT, 2019
** splash circle
** File description:
** my_streetart
*/

#include "include/framebuffer.h"

void draw_circle(framebuffer_t *framebuffer, sfVector2i center, int rad, sfColor color)
{
    for (int i = center.y - rad; i <= center.y + rad; i++) {
        for (int j = center.x - rad; j <= center.x + rad; j++) {
            if (pow(j - center.x, 2) + pow(i - center.y, 2) <= pow(rad, 2))
                my_put_pixel(framebuffer, j, i, color);
        }
    }
}

void splash_i(framebuffer_t *framebuffer, int radius, sfColor color)
{
    sfVector2i  center;

    center.x = rand() % 1920;
    center.y = rand() % 1080;
    draw_circle(framebuffer, center, radius, color);
}
