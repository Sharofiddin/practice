#ifndef GUARD_Str_h
#define GUARD_Str_h

#include <algorithm>
#include <iostream>
#include <cstring>
#include "../Ptr.h"
#include "../Vec.h"
#include <cstring>
template<>
Vec<char>* clone(const Vec<char>*);

// does this version work?
class Str {
	friend std::istream& operator>>(std::istream&, Str&);
	friend std::istream& getline(std::istream&, Str&);

public:
	Str& operator+=(const Str& s) {
		data.make_unique();
		std::copy(s.data->begin(), s.data->end(),
		          std::back_inserter(*data));
		return *this;
	}

	// interface as before
	typedef Vec<char>::size_type size_type;

	// reimplement constructors to create `Ptr's
	Str(): data(new Vec<char>) { }
	Str(const char* cp): data(new Vec<char>)  {
#ifdef _MSC_VER
		std::copy(cp, cp + strlen(cp),
#else
		std::copy(cp, cp + std::strlen(cp),
#endif
		          std::back_inserter(*data));
	}

	Str(size_type n, char c): data(new Vec<char>(n, c)) { }
	template <class In> Str(In i, In j): data(new Vec<char>) {
		std::copy(i, j, std::back_inserter(*data));
	}

	// call `make_unique' as necessary
	char& operator[](size_type i) {
		data.make_unique();
		return (*data)[i];
	}
	const char& operator[](size_type i) const { return (*data)[i]; }
	size_type size() const { return data->size(); }

	typedef Ptr<char> iterator;
	typedef const Ptr<char> const_iterator;

	iterator begin() { return data->begin(); }
	const_iterator begin() const { return data->begin(); }

	iterator end() { return data->end(); }
	const_iterator end() const { return data->end(); }

private:
	// store a `Ptr' to a `vector'
	Ptr< Vec<char> > data;
};
// as implemented in 12.3.2/216 and 12.3.3/219 
std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);
bool operator<(const Str& lhs, const Str& rhs)
{
        return strcmp(lhs.c_str(), rhs);
}
inline bool operator>(const Str& lhs, const Str& rhs)
{
        return std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}
inline bool operator<=(const Str& lhs, const Str& rhs)
{
        return !std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());

}
inline bool operator>=(const Str& lhs, const Str& rhs)
{
        return !std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());

}
inline bool operator==(const Str& lhs, const Str& rhs)
{
        return lhs.size() == rhs.size() &&
                std::equal(lhs.begin(), lhs.end(), rhs.begin());
}
inline bool operator!=(const Str& lhs, const Str& rhs)
{
        return !(lhs == rhs);
}
#endif

=======
#ifndef STR_H
#define STR_H
#include <cstring>
#include <iterator>
#include <memory>
#include <algorithm>
#include <cstring>
#include <iostream>
#include "../Ptr.h"
class Str
{
public:
	typedef size_t size_type;
	typedef Ptr<char[]> iterator;
	typedef const Ptr<char[]> const_iterator;
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
	const char* c_str() const;
	const char* data() const;
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
	void create(const_iterator)
	void create(const_iterator, const_iterator);
	void create(size_type, char);
	void grow();
	void grow(size_type);
	void uncreate();
	void unchecked_append(const char c);
};
#endif
