#ifndef TWOINPUTGATE_H
#define TWOINPUTGATE_H

#include "ChainableComponent.h"

#include <string>

enum LogicOperation {OR, AND, XOR};

const std::string LOGIC_LABELS[] = {"OR", "AND", "XOR"};

class TwoInputGate : public ChainableComponent {
public:
    TwoInputGate();
    TwoInputGate(LogicOperation gateOperator);
    TwoInputGate(const TwoInputGate& other);
    TwoInputGate& operator=(const TwoInputGate& other);
    ~TwoInputGate();

    void setInput2(Component* inputLink);
    bool getOutput() const;
    void prettyPrint(std::string padding);

private:
    LogicOperation gateType;
    Component* input2;
};

#endif // TWOINPUTGATE_H
