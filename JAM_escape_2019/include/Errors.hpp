/*
** EPITECH PROJECT, 2020
** Grounhog
** File description:
** ERRORS
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <iostream>
#include <cstring>
#include <ostream>
#include <string.h>

class Errors
{   
    public:
        static double  string_to_double(std::string line);
        static int string_to_int(char *str);
        static int argument_handling(int ac, char **av);

    private:
        Errors();
};

#endif /* ERRORS_HPP_ */
