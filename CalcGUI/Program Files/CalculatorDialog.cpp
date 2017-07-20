#include <iostream>
#include <QApplication>
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QObject>
#include <QVBoxLayout>
#include <QString>
#include <string>
#include "Calculator.h"
#include "CalculatorDialog.h"

using namespace std;

CalculatorDialog::CalculatorDialog(QWidget* parent) :
    QDialog(parent), decimalPressed(false), operatorPressed(false), equalsPressed(false), numberPressed(false)
{
    //Button Grid
    QGridLayout* buttonGrid = new QGridLayout;
    QString buttonChars = "789/√456*%123-C0.←+=";
    int index = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            buttons[i][j] = new QPushButton(buttonChars.at(index));
            buttons[i][j]->setStyleSheet("font-size: 16pt; padding: 0px;");
            buttons[i][j]->setMinimumSize(40, 40);
            buttonGrid->addWidget(buttons[i][j], i, j);
            index += 1;
        }
    }
    buttons[3][4]->setDefault(true);
    /*0*/ connect(buttons[3][0],SIGNAL(clicked()), this, SLOT(numberButtonPressed()));
    /*1*/ connect(buttons[2][0],SIGNAL(clicked()), this, SLOT(numberButtonPressed()));
    /*2*/ connect(buttons[2][1],SIGNAL(clicked()), this, SLOT(numberButtonPressed()));
    /*3*/ connect(buttons[2][2],SIGNAL(clicked()), this, SLOT(numberButtonPressed()));
    /*4*/ connect(buttons[1][0],SIGNAL(clicked()), this, SLOT(numberButtonPressed()));
    /*5*/ connect(buttons[1][1],SIGNAL(clicked()), this, SLOT(numberButtonPressed()));
    /*6*/ connect(buttons[1][2],SIGNAL(clicked()), this, SLOT(numberButtonPressed()));
    /*7*/ connect(buttons[0][0],SIGNAL(clicked()), this, SLOT(numberButtonPressed()));
    /*8*/ connect(buttons[0][1],SIGNAL(clicked()), this, SLOT(numberButtonPressed()));
    /*9*/ connect(buttons[0][2],SIGNAL(clicked()), this, SLOT(numberButtonPressed()));
    /*Divide*/ connect(buttons[0][3],SIGNAL(clicked()), this, SLOT(operatorButtonPressed())); buttons[0][3]->setEnabled(false);
    /*Multiply*/ connect(buttons[1][3],SIGNAL(clicked()), this, SLOT(operatorButtonPressed())); buttons[1][3]->setEnabled(false);
    /*Add*/ connect(buttons[3][3],SIGNAL(clicked()), this, SLOT(operatorButtonPressed())); buttons[3][3]->setEnabled(false);
    /*Subtract*/ connect(buttons[2][3],SIGNAL(clicked()), this, SLOT(operatorButtonPressed())); buttons[2][3]->setEnabled(false);
    /*Square Root*/ connect(buttons[0][4],SIGNAL(clicked()), this, SLOT(operatorButtonPressed())); buttons[0][4]->setEnabled(false);
    /*Percent*/ connect(buttons[1][4],SIGNAL(clicked()), this, SLOT(operatorButtonPressed())); buttons[1][4]->setEnabled(false);
    /*Decimal*/ connect(buttons[3][1],SIGNAL(clicked()), this, SLOT(editButtonPressed()));
    /*Backspace*/ connect(buttons[3][2],SIGNAL(clicked()), this, SLOT(editButtonPressed()));
    /*Clear*/ connect(buttons[2][4],SIGNAL(clicked()), this, SLOT(clearButtonPressed()));
    /*Equals*/ connect(buttons[3][4],SIGNAL(clicked()), this, SLOT(equalsButtonPressed()));

    //Horizontal Layouts
    QHBoxLayout* expressionBox = new QHBoxLayout;
    currentExpression = new QLabel("");
    currentExpression->setAlignment(Qt::AlignRight);
    currentExpression->setStyleSheet("font-size: 10pt; padding: 0px;");
    expressionBox->addWidget(currentExpression);

    QHBoxLayout* hBoxTopRow = new QHBoxLayout;
    calcScreen = new QLineEdit("");
    calcScreen->setPlaceholderText("0");
    calcScreen->setStyleSheet("font-size: 16pt; padding: 0px;");
    calcScreen->setFixedHeight(40);
    calcScreen->setAlignment(Qt::AlignRight);
    calcScreen->setReadOnly(true);
    calcScreen->setMaxLength(16);
    hBoxTopRow->addWidget(calcScreen);

    //Vertical (Main) Layout
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(expressionBox);
    mainLayout->addLayout(hBoxTopRow);
    mainLayout->addLayout(buttonGrid);

    //Display Calculator//
    this->setLayout(mainLayout);
    this->setWindowTitle("Calculator");
    this->setFixedHeight(sizeHint().height());
    this->setFixedWidth(sizeHint().width());
    this->show();
}
//Numbers
void CalculatorDialog::numberButtonPressed() {
    QObject* mySender = QObject::sender();
    QPushButton* pressedButton = dynamic_cast<QPushButton*>(mySender);
    if(calcScreen->text() == "") {
        buttons[0][3]->setEnabled(true);
        buttons[1][3]->setEnabled(true);
        buttons[3][3]->setEnabled(true);
        buttons[2][3]->setEnabled(true);
        buttons[0][4]->setEnabled(true);
        buttons[1][4]->setEnabled(true);
    }

    if(equalsPressed != true) {
        if(operatorPressed == true) {
            calcScreen->clear();
            logic.store(0);
            decimalPressed = false;
            operatorPressed = false;
            equalsPressed = false;
        }
        QString newInput = pressedButton->text();
        calcScreen->setText(calcScreen->text() + newInput);
        double storeValue = calcScreen->text().toDouble();
        logic.store(storeValue);
    }
}
//Edit
void CalculatorDialog::editButtonPressed() {
    QObject* mySender = QObject::sender();
    QPushButton* pressedButton = dynamic_cast<QPushButton*>(mySender);
    QString backButton = "←";
    QString decimalButton = ".";
    if(calcScreen->text() == "") {/*Do Nothing*/}
    else if(equalsPressed != true) {
        if(pressedButton->text() == backButton) {
            calcScreen->backspace();
            double storeValue = calcScreen->text().toDouble();
            logic.store(storeValue);
            if(!calcScreen->text().contains(decimalButton)) {
                decimalPressed = false;
            }
            if(calcScreen->text() == "") {
                buttons[0][3]->setEnabled(false);
                buttons[1][3]->setEnabled(false);
                buttons[3][3]->setEnabled(false);
                buttons[2][3]->setEnabled(false);
                buttons[0][4]->setEnabled(false);
                buttons[1][4]->setEnabled(false);
            }
        }
        else if(pressedButton->text() == decimalButton) {
            if(decimalPressed != true) {
                calcScreen->insert(decimalButton);
                double storeValue = calcScreen->text().toDouble();
                logic.store(storeValue);
                decimalPressed = true;
            }
        }
    }
}
//Operators
void CalculatorDialog::operatorButtonPressed() {
    QObject* mySender = QObject::sender();
    QPushButton* pressedButton = dynamic_cast<QPushButton*>(mySender);

    QString add = "+";
    QString subtract = "-";
    QString multiply = "*";
    QString divide = "/";
    QString percent = "%";
    QString sqroot = "√";
    double returnValue = 0;
    QString returnString = "";

    if(equalsPressed == true) {
        logic.store(0);
        operatorPressed = false;
    }

    if(calcScreen->text() == "") {/*Do Nothing*/}
    else if(operatorPressed == true) {/*Do Nothing*/}
    //Addition
    else if(pressedButton->text() == add) {
        currentExpression->setText(currentExpression->text() + calcScreen->text() + " " + add + " ");
        returnValue = logic.handleOperation(Calculator::ADD);
        returnString = QString::number(returnValue);
        if(equalsPressed == true) {
            calcScreen->setText(returnString);
        }
        operatorPressed = true;
        equalsPressed = false;
    }
    //Subtraction
    else if(pressedButton->text() == subtract) {
        currentExpression->setText(currentExpression->text() + calcScreen->text() + " " + subtract + " ");
        returnValue = logic.handleOperation(Calculator::SUBTRACT);
        returnString = QString::number(returnValue);
        if(equalsPressed == true) {
            calcScreen->setText(returnString);
        }
        operatorPressed = true;
        equalsPressed = false;
    }
    //Multiplication
    else if(pressedButton->text() == multiply) {
        currentExpression->setText(currentExpression->text() + calcScreen->text() + " " + multiply + " ");
        returnValue = logic.handleOperation(Calculator::MULTIPLY);
        returnString = QString::number(returnValue);
        if(equalsPressed == true) {
            calcScreen->setText(returnString);
        }
        operatorPressed = true;
        equalsPressed = false;
    }
    //Division
    else if(pressedButton->text() == divide) {
        currentExpression->setText(currentExpression->text() + calcScreen->text() + " " + divide + " ");
        returnValue = logic.handleOperation(Calculator::DIVIDE);
        returnString = QString::number(returnValue);
        if(equalsPressed == true) {
            calcScreen->setText(returnString);
        }
        operatorPressed = true;
        equalsPressed = false;
    }
    //Percentage
    else if(pressedButton->text() == percent) {
        double outputValue = calcScreen->text().toDouble();
        logic.store(outputValue);
        returnValue = logic.handleOperation(Calculator::PERCENT);
        returnString = QString::number(returnValue);
        calcScreen->clear();
        calcScreen->setText(returnString);
    }
    //Square Root
    else if(pressedButton->text() == sqroot) {
        double outputValue = calcScreen->text().toDouble();
        logic.store(outputValue);
        returnValue = logic.handleOperation(Calculator::SQRT);
        returnString = QString::number(returnValue);
        calcScreen->clear();
        calcScreen->setText(returnString);
    }
}
//Clear
void CalculatorDialog::clearButtonPressed() {
    calcScreen->clear();
    currentExpression->clear();
    logic.clear();
    equalsPressed = false;
    operatorPressed = false;
    decimalPressed = false;
    buttons[0][3]->setEnabled(false);
    buttons[1][3]->setEnabled(false);
    buttons[3][3]->setEnabled(false);
    buttons[2][3]->setEnabled(false);
    buttons[0][4]->setEnabled(false);
    buttons[1][4]->setEnabled(false);
}
//Equals
void CalculatorDialog::equalsButtonPressed() {
    double outputValue = logic.equalsPressed();
    QString valueString = QString::number(outputValue);
    currentExpression->clear();
    equalsPressed = true;
    operatorPressed = true;
    calcScreen->setText(valueString);
}
