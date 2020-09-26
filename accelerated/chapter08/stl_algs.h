// This file contains sample implementations of assorted algorithms
// from the standard library.  It is not actually used by any of the
// other code in the book.
#include <algorithm>
#include <iostream>
template <class In, class X> In find(In begin, In end, const X& x)
{
	while (begin != end && *begin != x)
		++begin;
	return begin;
}

template <class In, class Out>
Out copy(In begin, In end, Out dest)
{
	while (begin != end)
		*dest++ = *begin++;
	return dest;
}

template <class For, class X>
void replace(For beg, For end, const X& x, const X& y)
{
	while (beg != end) {
		if (*beg == x)
			*beg = y;
		++beg;
	}
}

template <class Bi> void reverse_v(Bi begin, Bi end)
{
	while (begin != end) {
		--end;
		if (begin != end)
			std::swap(*begin++, *end);
	}
}

//does not work 
template <class Bi> void reverse_without_swap(Bi begin, Bi end)
{
	while (begin != end) {
		--end;
		if (begin != end){
			std::cout << "1. " << &(*begin) <<" " << &(*end) <<"\n";
			Bi temp = begin;
			begin = end;
			end = temp;
			begin++;
			std::cout <<"2. "<< &(*begin) <<" " << &(*end) <<"\n";
		}
	}
}

template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
	while (begin < end) {
		// find the midpoint of the range
		Ran mid = begin + (end - begin) / 2;

		// see which part of the range contains `x'; keep looking only in that part
		if (x < *mid)
			end = mid;
		else if (*mid < x)
			begin = mid + 1;
		// if we got here, then `*mid == x' so we're done
		else return true;
	}
	return false;
}

