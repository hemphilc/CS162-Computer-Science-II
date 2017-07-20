#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component {
public:
    Component();
    Component(const std::string& componentLabel);
    Component(const Component& other);
    Component& operator=(const Component& other);
    virtual ~Component();

    virtual bool getOutput() const = 0;
    virtual void prettyPrint(std::string padding);

private:
    std::string label;
};

#endif // COMPONENT_H
