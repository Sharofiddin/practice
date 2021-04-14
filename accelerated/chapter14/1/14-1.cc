#include "../Ptr.h"
#include "../Core.h"
#include <iostream>

bool compare(const Ptr<Core> &p1, const Ptr<Core> &p2){
    return p1->name() > p2->name();
}
int main()
{
 
 return 0;
}