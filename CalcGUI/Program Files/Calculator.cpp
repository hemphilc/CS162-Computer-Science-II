#include "Calculator.h"
#include <stdexcept>
#include <cmath>

using namespace std;

Calculator::Calculator() {
    num1 = 0;
    num2 = 0;
    oper = NONE;
}

void Calculator::store(double value) {
    num2 = value;
}

double Calculator::handleOperation(Calculator::opType newOperation) {
    if(newOperation == SQRT) {
        num2 = sqrt(num2);
        return num2;
    }
    else if(newOperation == PERCENT) {
        num2 = num2 / 100.0;
        return num2;
    }
    else if(oper == NONE) {
        num1 = num2;
        oper = newOperation;
        return num1;
    }
    else if(oper == MULTIPLY) {
        num1 = num1 * num2;
        oper = newOperation;
        return num1;
    }
    else if(oper == DIVIDE) {
        num1 = num1 / num2;
        oper = newOperation;
        return num1;
    }
    else if(oper == ADD) {
        num1 = num1 + num2;
        oper = newOperation;
        return num1;
    }
    else if(oper == SUBTRACT) {
        num1 = num1 - num2;
        oper = newOperation;
        return num1;
    }
    return 0;
}

double Calculator::equalsPressed() {
    return handleOperation(oper);
}

void Calculator::clear() {
    num1 = 0;
    num2 = 0;
    oper = NONE;
}
