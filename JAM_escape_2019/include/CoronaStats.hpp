/*
** EPITECH PROJECT, 2020
** Grounhog
** File description:
** CoronaStats
*/

#ifndef CoronaStats_HPP_
#define CoronaStats_HPP_

#include <iostream>
#include <ostream>
#include <iomanip>
#include "Errors.hpp"
class CoronaStats {
    public:
        CoronaStats();
    void main_loop();
    int     find_switch(void);
        void    setG(int numberOfDays, int);
        void    setR(int numberOfDays, int);
        void    setS(int numberOfDays, int i);
        void    printAllValues(int numberOfDays, int i);
        double  temperatures[100];
        double  g = 0.0;
        double  r = 0.0;
        double  s = 0.0;
        double  prev_r = 0.0;
        double  prev_s = 0.0;
        int     switch_value = 0;
};
#endif /* CoronaStats_HPP_ */
