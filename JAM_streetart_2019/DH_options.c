/*
** EPITECH PROJECT, 2019
** options
** File description:
** options
*/

#include "include/framebuffer.h"

void h_flag(void)
{
    printf(
        "Render an animation in a CSFML window"
        "\n\nUSAGE :\n  ./my_streetart animation_id\n"
        "  animation_id ID of the animation to process (1 to 6)"
        "\n\n -d print the description of all the animations and quit\n"
        " -h print the usage and quit\n\n");
}

void d_flag(void)
{
    printf(
        "animation_id list :\n\n"
        "  1 - Retro Square : Print random squares with random location and color\n"
        "  2 - Straight circle : Print multiple circles in a line\n"
        "  3 - Disco lines : Print colorful lines randomly\n"
        "  4 - Bubble : Print circles randomly\n"
        "  5 - Stars : A night sky\n"
        "  6 - Disco squares : Prints squares\n\n");
}
