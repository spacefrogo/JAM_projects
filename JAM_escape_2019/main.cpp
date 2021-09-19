/*
** EPITECH PROJECT, 2020
** Main
** File description:
** Main
*/

#include "include/Errors.hpp"
#include "include/CoronaStats.hpp"
#include "view/Display.hpp"


int main(int ac, char **av)
{
    if (ac == 2){
        std::string helpFlag(av[1]);
        if (helpFlag.compare("-h") == 0) {
            std::cout << "Write number of cases for each day of the week to see the predicted result for next week\n";
            return 0;
        }
    }
    if (ac != 1)
        return 84;
    showGraph();
    return 0;
}
