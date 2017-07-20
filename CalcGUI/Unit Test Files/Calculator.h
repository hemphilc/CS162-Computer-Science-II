#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    Calculator();
    enum opType
    {
        ADD,
        SUBTRACT,
        MULTIPLY,
        DIVIDE,
        SQRT,
        PERCENT,
        NONE
    };

    void store(double value);
    double handleOperation(opType newOperation);
    double equalsPressed();
    void clear();

private:
    double num1;
    double num2;
    opType oper;
};

#endif // CALCULATOR_H
