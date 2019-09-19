#ifndef GUARD_Pharse
#define GUARD_Pharse
#include <iostream>
#include <vector>
#include <string>

struct Pharse
{
	std::vector<std::string> words;
	std::string separator;
};

bool compare(Pharse p1, Pharse p2);
#endif
