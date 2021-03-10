#ifndef STR_H
#define STR_H
#include <cstring>
#include <iterator>
#include <memory>
#include <algorithm>
#include <cstring>
#include <iostream>
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
	friend bool operator>(const Str &, const Str &);
	friend bool operator<(const Str &, const Str &);
	friend bool operator>=(const Str &, const Str &);
	friend bool operator<=(const Str &, const Str &);
	friend bool operator==(const Str &, const Str &);
	friend bool operator!=(const Str &, const Str &);
	friend Str operator+(const Str &, const Str &);
	friend Str operator+(const char *, const Str &);
	friend Str operator+( const Str &, const char *);
	friend std::istream& getline(std::istream &, Str &s);
	
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	// default constructor; create an empty Str
	Str();
	// create a Str containing n copies of c
	Str(size_type, char);
	// create a Str from a null-terminated array of char
	Str(const char *);
	Str(const Str &);
	Str& append(const char);
	
	//return type should be reference otherwise different object will be returned
	Str& append(const Str &);
	// create a Str from the range denoted by iterators b and
	Str(const_iterator, const_iterator);
	operator bool() const;
	const char *c_str() const;
	const char *data() const;
	size_type size() const;
	size_type copy(char *dest, size_type count, size_type pos = 0) const;
	Str &operator+=(const Str &);
	Str substr(const size_type,  const size_type) const;
	template <class In>
  	void insert(iterator position, In first, In last)
	  {
		  Str first_part(data_p, position);
		  Str secon_part(position, avail);
		  Str middle(first,last);
		  std::cout << first_part << " "<<middle <<" "<< secon_part << std::endl;
		  *this = first_part + middle + secon_part;
	  }
	bool empty() const;
private:
	iterator data_p;
	iterator avail;
	iterator limit;
	std::allocator<char> alloc;
	void create();
	void create(const_iterator, const_iterator);
	void create(size_type, char);
	void grow();
	void grow(size_type);
	void uncreate();
	void unchecked_append(const char c);
};
#endif