/*
** EPITECH PROJECT, 2020
** Errors
** File description:
** Erros
*/

#include "include/Errors.hpp"

Errors::Errors()
{

}

int    Errors::argument_handling(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Please follow -h" << std::endl;
        return (84);
    }
    if (strlen(av[1]) == 2 && strcmp(av[1], "-h") == 0) {
        std::cout << "SYNOPSIS\n\t./CoronaStats period\nDESCRIPTION\n\tperiod\tthe number of days defining a period" << std::endl;
        return (0);
    }
    if (string_to_int(av[1]) == -1) {
        std::cerr << "Error: invalid argument given, please give an natural number" << std::endl;
        return (84);
    }
    return -1;
}

int     Errors::string_to_int(char *str)
{
    int i = 0;
    int c = 0;

    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9')
            c = c * 10 + (str[i] - '0');
        else
            return -1;
        i++;
    }
    return c;
}

double  Errors::string_to_double(std::string line)
{
    double result = 0;
    char *str = new char [line.length() + 1];
    std::strcpy(str, line.c_str());
    char *eptr = NULL;

    result = strtod(str, &eptr);
    if (strlen(eptr) != 0) {
        std::cerr << "Error: the waited output must be a number" << std::endl;
        exit(84);
    }
    if (result == 0)
        if (errno == ERANGE) {
            std::cerr << "Error: converting input to double" << std::endl;
            exit(84);
        }
    return result;
}