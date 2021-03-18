#include "Core.h"
int main()
{
    //Core c(std::cin);
    //std::cout <<c.name() << " | " << c.letter_grade() << std::endl;
    Grad g(std::cin);
    std::cout <<g.name() << " | "  << g.letter_grade() << std::endl;
    return 0;
}