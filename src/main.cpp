#include <iostream>
#include "Calculator.h"

int main(int argc, char *argv[])
{
    Calculator calc = Calculator();
    bool isOK = false;

    isOK = calc.add(1, 2);
    if (!isOK)
    {
        std::cout << "Invalid add inputs." << std::endl;
    }
    else
    {
        std::cout << "SUM is " << calc.get_last_result() << std::endl;
    }

    isOK = calc.div(10, 5);
    if (!isOK)
    {
        std::cout << "Invalid div inputs." << std::endl;
    }
    else
    {
        std::cout << "QUOTIENT is " << calc.get_last_result() << std::endl;
    }

    isOK = calc.div(4, 0);
    if (!isOK)
    {
        std::cout << "Invalid div inputs." << std::endl;
    }
    else
    {
        std::cout << "QUOTIENT is " << calc.get_last_result() << std::endl;
    }

    return 0;
}
