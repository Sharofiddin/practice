#ifndef STR_H
#define STR_H
#include <cstring>
#include <iterator>
#include <memory>
#include <algorithm>

class Str
{
public:
	typedef size_t size_type;
	typedef char *iterator;
	typedef const char *const_iterator;
	char &operator[](size_type i);
	const char &operator[](size_type i) const;
	friend std::istream &operator>>(std::istream &is, Str &str);
	friend std::ostream &operator<<(std::ostream &os, const Str &str);
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	// default constructor; create an empty Str
	Str();
	// create a Str containing n copies of c
	Str(size_type , char );
	// create a Str from a null-terminated array of char
	Str(const char *);
	Str(const Str&);
	void append(const char );
	// create a Str from the range denoted by iterators b and
	Str(const_iterator , const_iterator );

private:
	size_t s;
	iterator data;
	iterator avail;
	iterator limit;
	std::allocator<char> alloc;
	void create();
	void create(const_iterator , const_iterator );
	void create(size_type , char );
	void grow();
	void uncreate();
	void unchecked_append(const char c);
};
#endif