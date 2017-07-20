#ifndef CHAINABLECOMPONENT_H
#define CHAINABLECOMPONENT_H

#include "Component.h"

class ChainableComponent : public Component{
public:
    ChainableComponent();
    ChainableComponent(const std::string& componentLabel);
    ChainableComponent(const ChainableComponent& other);
    ChainableComponent& operator=(const ChainableComponent& other);
    ~ChainableComponent();

    void setInput(Component* inputLink);
    void prettyPrint(std::string padding);

protected:
    Component* input;
};

#endif // CHAINABLECOMPONENT_H
