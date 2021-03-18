#include "Core.h"

int main()
{
    Core *p1 = new Core;
    Core *p2 = new Grad;
    Core s1;
    Grad s2;
    try{
    p1->grade();
        } catch(std::domain_error ex){
        //ignore
    }
    try{
    p1->name();
        } catch(std::domain_error ex){
        //ignore
    }
    try{
    p2->grade();
        } catch(std::domain_error ex){
        //ignore
    }
    try{
    p2->name();
        } catch(std::domain_error ex){
        //ignore
    }
    try{    
    s1.grade();
        } catch(std::domain_error ex){
        //ignore
    }
    try{
    s1.name();
        } catch(std::domain_error ex){
        //ignore
    }
    try{
    s2.name();
        } catch(std::domain_error ex){
        //ignore
    }
    try{
    s2.grade();
    } catch(std::domain_error ex){
        //ignore
    }
    return 0;
}