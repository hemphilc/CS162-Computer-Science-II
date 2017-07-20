#ifndef OUTPUT_H
#define OUTPUT_H

#include "ChainableComponent.h"

class Output : public ChainableComponent {
public:
    Output();
    Output(const std::string& outputName);
    Output(const Output& other);
    Output& operator=(const Output& other);
    ~Output();

    bool getOutput() const;

};

#endif // OUTPUT_H
