#ifndef GUARD_median_h
#define GUARD_median_h

#include <algorithm>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::sort;
using std::vector;
template <class T, class R>
R median(T begin, T end, const R& initial)
{

	if (begin == end)
		throw domain_error("median of an empty vector");
	vector<T> aux(begin, end);
	typename vector<T>::size_type = aux.size();
	sort(aux.begin() , aux.end());

	size_t mid = size/2;

	return size % 2 == 0 ? ( aux[mid]+ aux[mid-1] )/ 2 : aux[mid];
}
#endif

