/*
** EPITECH PROJECT, 2020
** CoronaStats
** File description:
** CoronaStats
*/

#include "include/CoronaStats.hpp"
#include <math.h>

CoronaStats::CoronaStats()
{

}

void    CoronaStats::setG(int numberOfDays, int i)
{
    i += 1;
    double increaseTempAverage = 0.0;
    int index = i - numberOfDays - 1;
    int j = 0;
    double result = 0.0;

    if (i <= numberOfDays) {
        this->g = 0;
        return;
    }
    while (j <= numberOfDays) {
        if (this->temperatures[index] < this->temperatures[index + 1])
            increaseTempAverage += (this->temperatures[index + 1] - this->temperatures[index]);
        index++;
        j++;
    }
    result = increaseTempAverage / numberOfDays;
    if (result <= 0.0)
        result = 0.0;
    this->g = result;
}

void    CoronaStats::setR(int numberOfDays, int temp_size)
{
    int size = temp_size + 1;
    int  actual = size - 1;
    float calc_diff = this->temperatures[actual - numberOfDays];

    this->prev_r = this->r;
    if (calc_diff == 0)
        this->r = (this->temperatures[actual] - this->temperatures[actual - numberOfDays]) * 100;
    else
        this->r = round(((this->temperatures[actual] - this->temperatures[actual - numberOfDays]) \
        / this->temperatures[actual - numberOfDays]) * 100);
}

void    CoronaStats::setS(int numberOfDays, int i)
{
    double averageTemp = 0;
    double standardDeviation = 0;
    int tmp = 0;

    this->prev_s = this->s;
    int count = 0;
    i += 1;
    if (i < numberOfDays)
        tmp = 0;
    else
        tmp = i - numberOfDays;
    for (int j = i; j > tmp; j--, count++)        
        averageTemp += this->temperatures[j - 1];
    averageTemp /= count;
    for (int j = i; j > tmp; j--)
        standardDeviation += pow((this->temperatures[j - 1] - averageTemp), 2);
    standardDeviation /= count;
    this->s = sqrt(standardDeviation);
}

void    CoronaStats::printAllValues(int numberOfDays, int i)
{
    if (i < (numberOfDays - 1)) {
        std::cout << "\tg=nan\n\tPercentage compared today with one week ago = nan%\n\ts=nan\n\n";
        return;
    }
    else if (i == (numberOfDays - 1)) {
        std::cout << "\tg=nan\n\tPercentage compared today with one week ago = nan%\n\ts=";
        std::cout << std::fixed << std::setprecision(2) << this->s << std::endl;
        std::cout << "\n";
        return;
    } else {
        std::cout << "\tg=" << std::fixed << std::setprecision(2) << this->g << "\n";
        std::cout << "\tPercentage compared today with one week ago = " << std::fixed << std::setprecision(0) << this->r << "%\n";
        std::cout << "\ts=" << std::fixed << std::setprecision(2) << this->s;
    }
    if (this->find_switch() == 0)
        std::cout << "\n\n";
    else if (this->find_switch() == 1)
        std::cout << "\n\tGraph peak almost reached\n\n";
    else
        std::cout << "\n\tGood news! Graph is going low\n\n";
}

void CoronaStats::main_loop()
{
    std::string line;
    static int i = 0;
    int    numberOfDays = 7;
    
    std::cout << "Number of cases in day " << i + 1 << ": ";
    std::getline(std::cin, line);
    if (line.compare("STOP") == 0) {
        if (i < numberOfDays)
            exit(84);
    }
    if (line.empty() || line.find_first_not_of(' ') == std::string::npos)
        exit(84);
    this->temperatures[i] = Errors::string_to_double(line);\
    if (i > 7) {
        this->setR(numberOfDays, i);
        this->setS(numberOfDays, i);
        this->setG(numberOfDays, i);
    }
            this->printAllValues(numberOfDays, i);

    i++;
}
