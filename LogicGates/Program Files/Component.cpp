#include <iostream>
#include <sstream>

#include "Component.h"

using namespace std;

Component::Component() : label("Default") {}

Component::Component(const std::string& componentLabel) {
    this->label = componentLabel;
}

Component::Component(const Component& other) {
    this->label = other.label;
}

Component& Component::operator=(const Component& other) {
    if (this != &other) {
        this->label = other.label;
    }
    return *this;
}

Component::~Component() {}

void Component::prettyPrint(string padding) {
    cout << padding << this->label << " : " << getOutput() << endl;
}
