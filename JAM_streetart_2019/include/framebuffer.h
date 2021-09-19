/*
** EPITECH PROJECT, 2019
** framebuffer
** File description:
** framebuffer
*/

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer_t *framebuffer);
void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color);
int random_x(void);
int random_y(void);
int random_radius(void);
int draw_a_circle(framebuffer_t *framebuffer, sfVector2i center, int rad, sfColor color);
void framebuffer_destroy(framebuffer_t *framebuffer);
sfColor my_rgba(sfUint8 r, sfUint8 g, sfUint8 b, sfUint8 a);
void splash_i(framebuffer_t *framebuffer, int radius, sfColor color);
void my_put_circle(framebuffer_t *framebuffer, int xm, int radius, sfColor color);
void drawline(framebuffer_t *framebuffer, int x0, int y0, sfColor color);
void draw_pixels(framebuffer_t *framebuffer, sfColor color);
int fycalc(int y, int fy, int f);
void my_put_square(framebuffer_t *framebuffer, int x0, int y0, sfColor color);
void d_flag(void);
void h_flag(void);
int my_putstr(char const *str);
void my_putchar(char c);
int errors(int ac, char **av);

#endif    /* FRAMEBUFFER_H_ */
