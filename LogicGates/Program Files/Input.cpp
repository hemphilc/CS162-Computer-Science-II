#include <iostream>
#include <sstream>

#include "Input.h"

using namespace std;

Input::Input()
    : Component("Default"), value(false) {}

Input::Input(const std::string& inputName)
    : Component(inputName), value(false) {
}

Input::Input(const Input& other)
    : Component(other) {
    this->value = other.value;
}

Input& Input::operator=(const Input& other) {
    Component::operator=(other);
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

Input::~Input() {}

void Input::setValue(bool newValue) {
    this->value = newValue;
}

bool Input::getOutput() const {
    return this->value;
}

