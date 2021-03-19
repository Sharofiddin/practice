#include "Core.h"

int main()
{
    Core c(std::cin);
    Grad *g = new Grad(std::cin);
    std::cout << c.valid() << " | " << g->valid() << std::endl;
    return 0;
}