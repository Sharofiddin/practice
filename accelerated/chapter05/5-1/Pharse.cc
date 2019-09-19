#include <string>
#include <vector>
#include "Pharse"
using std::vector;	using std::string;

bool compare( const Pharse& p1, const Pharse& p2 )
{
	return p1.words[0] > p2.words[0];
}
