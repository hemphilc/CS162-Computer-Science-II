#include <iostream>
#include <cassert>

#include "TwoInputGate.h"

using namespace std;

TwoInputGate::TwoInputGate()
    : ChainableComponent("Default") {
    this->setInput2(nullptr);
    this->gateType = OR;
}

TwoInputGate::TwoInputGate(LogicOperation gateOperator)
    : ChainableComponent(LOGIC_LABELS[gateOperator]) {
    this->setInput2(nullptr);
    this->gateType = gateOperator;
}

TwoInputGate::TwoInputGate(const TwoInputGate& other)
    : ChainableComponent(other) {
    this->setInput2(other.input2);
    this->gateType = other.gateType;
}

TwoInputGate& TwoInputGate::operator=(const TwoInputGate& other) {
    ChainableComponent::operator=(other);
    if (this != &other) {
        this->input2 = other.input2;
        this->gateType = other.gateType;
    }
    return *this;
}

TwoInputGate::~TwoInputGate() {}

void TwoInputGate::setInput2(Component* inputLink) {
    this->input2 = inputLink;
}

bool TwoInputGate::getOutput() const {
    assert(input != nullptr && input2 != nullptr);
    if (gateType == OR) {
        if (input->getOutput() == true || input2->getOutput() == true) {
            return true;
        }
    }
    else if (gateType == AND) {
        if (input->getOutput() == true && input2->getOutput() == true) {
            return true;
        }
    }
    else if (gateType == XOR) {
        if (input->getOutput() == true || input2->getOutput() == true) {
            if (!(input->getOutput() == true && input2->getOutput() == true)) {
                return true;
            }
        }
    }
    return false;
}

void TwoInputGate::prettyPrint(string padding) {
    ChainableComponent::prettyPrint(padding);
    if (input2 != nullptr) {
        input2->prettyPrint(padding + "---");
    }
}
