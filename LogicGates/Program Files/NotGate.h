#ifndef NOTGATE_H
#define NOTGATE_H

#include "ChainableComponent.h"

class NotGate : public ChainableComponent {
public:
    NotGate();
    NotGate(const NotGate& other);
    NotGate& operator=(const NotGate& other);
    ~NotGate();

    bool getOutput() const;

};

#endif // NOTGATE_H
