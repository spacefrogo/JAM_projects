/*
** EPITECH PROJECT, 2020
** jello
** File description:
** jello
*/

#include "include/CoronaStats.hpp"
#include <iostream>
#include <string>

int CoronaStats::find_switch(void)
{
    if (this->r >= 0 && this->prev_r < 0) {
        this->switch_value++;
        return 1;
    } else if (this->r < 0 && this->prev_r >= 0) {
        this->switch_value++;
        return 2;
    }
    return 0;
}
