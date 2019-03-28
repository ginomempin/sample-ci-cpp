#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
private:
    int m_lastResult;

public:
    Calculator();
    ~Calculator();
    bool add(int addend1, int addend2);
    bool mul(int factor1, int factor2);
    bool div(int dividend, int divisor);
    int get_last_result();
};

#endif // CALCULATOR_H
