#include <iostream>
#include <cassert>

#include "ChainableComponent.h"

using namespace std;

ChainableComponent::ChainableComponent()
    : Component("") {
    input = nullptr;
}

ChainableComponent::ChainableComponent(const std::string& componentLabel)
    : Component(componentLabel) {
    input = nullptr;
}

ChainableComponent::ChainableComponent(const ChainableComponent& other)
    : Component(other) {
    *input = other;
}

ChainableComponent& ChainableComponent::operator=(const ChainableComponent& other) {
    Component::operator=(other);
    if (this != &other) {
        *this = other;
    }
    return *this;
}

ChainableComponent::~ChainableComponent() {}

void ChainableComponent::setInput(Component* inputLink) {
    this->input = inputLink;
}

void ChainableComponent::prettyPrint(string padding) {
    Component::prettyPrint(padding);
    if (input != nullptr) {
        input->prettyPrint(padding + "---");
    }
}
