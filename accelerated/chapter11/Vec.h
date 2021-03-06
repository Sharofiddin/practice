#ifndef VEC_H
#define VEC_H

#include <algorithm>
#include <cstddef>
#include <memory>
#include <vector>
#include <iostream>
#ifdef _MSC_VER
#include "../minmax.h"
#else
using std::max;
#endif

template <class T> class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;

	Vec() 
	{
		create();
	}
	explicit Vec(size_type n, const T& t = T()) { create(n, t); }

	Vec(const Vec& v) { create(v.begin(), v.end()); }
	//12-10
	Vec(const_iterator b, const_iterator e)
	{
		create(b,e);
	};
	Vec(iterator &b, iterator &e)
	{
		create(b,e);
	};

	template <class InputIterator>
  	Vec(InputIterator first, InputIterator last)
	{
		create();
		while(first != last)
		{
			push_back(*first);
			++first;
		}
	}

	Vec& operator=(const Vec&);	// as defined in 11.3.2/196
	~Vec() { uncreate(); }

	T& operator[](size_type i) { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }

	void push_back(const T& t, bool doubled=true) {
		if (avail == limit)
			grow(doubled);
		unchecked_append(t);
	}
	template <class InputIterator>
  	void assign (InputIterator first, InputIterator last) //12-12
	  {
		  uncreate();
		  create(first,last);
	  }
	size_type size() const { return avail - data; }  // changed

	iterator begin() { return data; }
	const_iterator cbegin() const { return data; }

	iterator end() { return avail; }                 // changed
	const_iterator cend() const { return avail; }     // changed
	void clear();
	bool empty() const { return data == avail; }
	void erase(iterator);
	void erase(iterator, iterator );
	
	template <typename InputIt>
	void insert(const_iterator pos, InputIt first, InputIt last)
	{
		Vec first_part(cbegin(), pos);
		Vec second_part(pos, cend());
		Vec middle(first, last);
		uncreate();
		create(first_part.begin(), first_part.end());
		std::copy(middle.begin(), middle.end(), std::back_inserter(*this));
		std::copy(second_part.begin(), second_part.end(), std::back_inserter(*this));
	}
private:
	iterator data;	// first element in the `Vec'
	iterator avail;	// (one past) the last element in the `Vec'
	iterator limit;	// (one past) the allocated memory

	// facilities for memory allocation
	std::allocator<T> alloc;	// object to handle memory allocation

	// allocate and initialize the underlying array
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);
	
	// destroy the elements in the array and free the memory
	void uncreate();

	// support functions for `push_back'
	void grow(bool);
	void unchecked_append(const T&);
};

template <class T> void Vec<T>::create()
{
	data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val)
{
#ifdef _MSC_VER
	data = alloc.allocate(n, 0);
#else
	data = alloc.allocate(n);
#endif
	limit = avail = data + n;
	std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
#ifdef _MSC_VER
	data = alloc.allocate(j - i, 0);
#else
	data = alloc.allocate(j - i);
#endif
	limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T> void Vec<T>::uncreate()
{
	if (data) {
		// destroy (in reverse order) the elements that were constructed
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);

		// return all the space that was allocated
		alloc.deallocate(data, limit - data);
	}
	// reset pointers to indicate that the `Vec' is empty again
	data = limit = avail = 0;

}

template <class T> void Vec<T>::grow(bool doubled)
{
	// when growing, allocate twice as much space as currently in use
	size_type new_size = doubled ? max(2 * (limit - data), ptrdiff_t(1)) :max(limit - data + 1, ptrdiff_t(1));

	// allocate new space and copy existing elements to the new space
#ifdef _MSC_VER
	iterator new_data = alloc.allocate(new_size, 0);
#else
	iterator new_data = alloc.allocate(new_size);
#endif
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	// return the old space
	uncreate();

	// reset pointers to point to the newly allocated space
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

// assumes `avail' points at allocated, but uninitialized space
template <class T> void Vec<T>::unchecked_append(const T& val)
{
	alloc.construct(avail++, val);
}

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	// check for self-assignment
	if (&rhs != this) {

		// free the array in the left-hand side
		uncreate();

		// copy elements from the right-hand to the left-hand side
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

template<class T>
void Vec<T>::clear()
{
	uncreate();
}

template<class T>
void Vec<T>::erase(Vec<T>::iterator pos)
{
	while (pos != avail)
	{
		*pos = *(pos+1);
		pos++;
	}

	avail--;
	
}
template<class T>
void Vec<T>::erase(Vec<T>::iterator b, Vec<T>::iterator e)
{
	while(b < e){
		erase(b);
		b++;
	}
}
#endif
