#include <iostream>

#include "Input.h"
#include "Output.h"
#include "NotGate.h"
#include "TwoInputGate.h"

using namespace std;

int main()
{
    //Sample usage:

    Input a("A");
    a.setValue(true);

//    NotGate n1;
//    n1.setInput(&a);

    Input b("B");
    b.setValue(true);

    Input c("C");
    c.setValue(false);

    TwoInputGate g1(OR);
    g1.setInput(&b);
    g1.setInput2(&c);

    TwoInputGate g2(AND);
    g2.setInput(&a);
    g2.setInput2(&g1);

//    Output x("X");
//    x.setInput(&g2);

    g2.prettyPrint("");

    return 0;
}

