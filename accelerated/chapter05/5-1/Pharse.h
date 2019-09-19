#include <iostream>
#include <vector>
#include <string>

struct Pharse
{
	std::vector<std::string> words;
	std::string separator;
};

bool compare(Pharse p1, Pharse p2)
{
	return p1.words[0] > p2.words[0];
}


