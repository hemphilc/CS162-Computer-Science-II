#ifndef INPUT_H
#define INPUT_H

#include "Component.h"

#include <string>

class Input : public Component {
public:
    Input();
    Input(const std::string& inputName);
    Input(const Input& other);
    Input& operator=(const Input& other);
    ~Input();

    void setValue(bool newValue);
    bool getOutput() const;

private:
    bool value;
};

#endif // INPUT_H
