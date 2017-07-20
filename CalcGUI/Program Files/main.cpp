#include <QApplication>

#include "CalculatorDialog.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CalculatorDialog calc;
    calc.show();

    return app.exec();
}
