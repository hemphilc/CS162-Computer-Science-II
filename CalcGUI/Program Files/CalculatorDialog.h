#ifndef CALCULATORDIALOG
#define CALCULATORDIALOG

#include <QDialog>
#include <QLineEdit>
#include <QLabel>

#include "Calculator.h"

class CalculatorDialog : public QDialog {
    Q_OBJECT
public:
    CalculatorDialog(QWidget *parent = 0);

signals:
    void clicked();

public slots:
    void numberButtonPressed();
    void editButtonPressed();
    void operatorButtonPressed();
    void clearButtonPressed();
    void equalsButtonPressed();

private:
    QLineEdit* calcScreen;
    QLabel* currentExpression;
    QString* currentValue;
    QPushButton* buttons[4][5];
    Calculator logic;
    bool decimalPressed;
    bool operatorPressed;
    bool equalsPressed;
    bool numberPressed;
};

#endif // CALCULATORDIALOG
