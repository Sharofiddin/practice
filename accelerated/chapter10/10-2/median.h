#ifndef GUARD_median_h
#define GUARD_median_h

#include <algorithm>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::sort;
using std::vector;
template <class T>
T median(T* p, size_t size)
{
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(p , p + size);

	size_t mid = size/2;

	return size % 2 == 0 ? ( *(p+mid)+ *(p+mid-1) )/ 2 : *(p+mid);
}

template <class It, class S>
typename It::value_type median(It b, It e, S size)
{
	if( size == 0 )
		throw domain_error("empty vector");
	sort(b,e);
	S mid = size / 2;
	return size % 2 == 0 ? ((*(b + mid) + *(b + mid  - 1 )) / 2) : *(b + mid);
}
#endif

