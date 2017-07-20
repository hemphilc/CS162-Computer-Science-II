#include <iostream>
#include <cassert>

#include "NotGate.h"

using namespace std;

NotGate::NotGate()
    : ChainableComponent("NOT") {
}

NotGate::NotGate(const NotGate& other)
    : ChainableComponent(other) {
}

NotGate& NotGate::operator=(const NotGate& other) {
    ChainableComponent::operator=(other);
    return *this;
}

NotGate::~NotGate() {}

bool NotGate::getOutput() const {
    assert(input != nullptr);
    return !(input->getOutput());
}
