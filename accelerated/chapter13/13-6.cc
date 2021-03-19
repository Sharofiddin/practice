#include "Core.h"

int main()
{
    Credit cr(std::cin);
    std::cout << cr.name() << " | " << cr.grade() << " | " << cr.letter_grade() << std::endl;
}