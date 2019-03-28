#include "Calculator.h"

Calculator::Calculator()
{
    m_lastResult = 0;
}

Calculator::~Calculator()
{

}

bool Calculator::add(int addend1, int addend2)
{
    m_lastResult = addend1 + addend2;
    return true;
}

// This is for checking that code coverage will not be <100%
bool Calculator::mul(int factor1, int factor2)
{
    m_lastResult = factor1 * factor2;
    return true;
}

bool Calculator::div(int dividend, int divisor)
{
    if (divisor == 0)
    {
        m_lastResult = 0;
        return false;
    }

    m_lastResult = dividend / divisor;
    return true;
}

int Calculator::get_last_result()
{
    return m_lastResult;
}
