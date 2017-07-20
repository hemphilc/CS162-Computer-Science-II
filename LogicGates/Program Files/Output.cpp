#include <iostream>

#include "Output.h"

using namespace std;

Output::Output()
    : ChainableComponent("Default") {
}

Output::Output(const std::string& outputName)
    : ChainableComponent(outputName) {
}

Output::Output(const Output& other)
    : ChainableComponent(other) {
}

Output& Output::operator=(const Output& other) {
    ChainableComponent::operator=(other);
    return *this;
}

Output::~Output() {}

bool Output::getOutput() const {
    return input->getOutput();
}
