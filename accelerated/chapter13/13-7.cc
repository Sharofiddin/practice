#include "Core.h"

int main()
{
    Core *audit = new Audit(std::cin);
    std::cout << audit->name() << " | " << audit->grade() << std::endl;
    std::cout << audit->letter_grade(); //throws exception
    return 0; 
}