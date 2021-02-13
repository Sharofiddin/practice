/*
 * =====================================================================================
 *
 *       Filename:  List.h
 *
 *    Description: List impl 
 *
 *        Version:  1.0
 *        Created:  12/17/2020 10:56:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sharofiddin Pardayev (p.sh.t), pardayev.sharofddin@gmail.com
 *        Company:  BIS, Tashkent
 *
 * =====================================================================================
 */
#ifndef _LIST_GUARD
#define _LIST_GUARD
#include <iostream>

template <class T>
struct Node
{
		T val;
		Node *next;
		Node *prev;
		Node() : next(nullptr), prev(nullptr) {}
		Node(T d) : val(d), next(nullptr), prev(nullptr) {}
};
template <typename T>
struct ListIterator
{
	typedef ListIterator<T>		_Self;
    typedef Node<T>			_Node;
	typedef std::bidirectional_iterator_tag	iterator_category;
    typedef ptrdiff_t				difference_type;
    typedef T						value_type;
    typedef T*					pointer;
    typedef T&					reference;
	ListIterator() : data(){}; 
	ListIterator(_Node* d) : data(d){}; 
	_Self _M_const_cast() const{
		return *this;
	}
	_Self& operator++()
	{
	 data = data->next;
		  return *this;
	};
	_Self operator++(int)
	{
		_Self temp = *this;
		data = data->next;
		return temp;
	};

	_Self& operator--()
	{
	  data = data->prev();
	  return *this;
	};
	_Self operator--(int)
	{
	 _Self temp = *this;
	 data = data->prev;
	 return temp;
	};
	bool operator!=(const _Self& rhs) const{
	 return this->data != rhs.data;
	}
	bool operator==(const _Self& rhs) const{
	 return this->data == rhs.data;
	}
	reference operator*()
	{
		return data->val;
	}

	pointer operator->()
	{
		return &(data->val);
	}
	
	_Node *data;
};

template <typename T>
struct ConstListIterator
{
	typedef ConstListIterator<T>		_Self;
	typedef ListIterator<T>		iterator;
    typedef const Node<T>			_Node;
	typedef std::bidirectional_iterator_tag	iterator_category;
    typedef ptrdiff_t				difference_type;
    typedef T						value_type;
    typedef const T*					pointer;
    typedef const T&					reference;
	ConstListIterator() : data(){}; 
	ConstListIterator(_Node* d) : data(d){}; 
	ConstListIterator(const iterator& __x): data(__x.data) { }
	iterator
      _m_const_cast() const
      { return iterator(const_cast<Node<T>*>(data)); }

	_Self& operator++()
	{
	 data = data->next;
		  return *this;
	};
	_Self operator++(int)
	{
		_Self temp = *this;
		data = data->next;
		return temp;
	};

	_Self& operator--()
	{
	  data = data->prev();
	  return *this;
	};
	_Self operator--(int)
	{
	 _Self temp = *this;
	 data = data->prev;
	 return temp;
	};
	bool operator!=(const _Self& rhs) const{
	 return this->data != rhs.data;
	}
	bool operator==(const _Self& rhs) const{
	 return this->data == rhs.data;
	}
	reference operator*()
	{
		return data->val;
	}

	pointer operator->()
	{
		return &(data->val);
	}
	
	Node<T> *data;
};
template <typename T>
class List
{
public:
	typedef ListIterator<T> iterator;
	typedef ConstListIterator<T> const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;
	List();
	List(int n, const T&);
	List(iterator b, iterator e);
	~List();

	void push_back(const T &);
	void erase(iterator );
	void erase(iterator , iterator );
	iterator begin() { return iterator(head); }
	iterator end() { return iterator(0); }
	const_iterator begin() const { return const_iterator(head); }
	const_iterator end() const { return const_iterator(0); }


private:
	Node<T> *head;
	Node<T> *tail;
	size_type size;
	void create(iterator , iterator );
	void create(size_type , const T&);
	void uncreate();
	List<T>& operator=(const List<T>&);
	
};
template <typename T>
List<T>::List(){
	size = 0;
   	head = tail = nullptr; 
};

template <typename T>
List<T>::List(int n, const T& t)
{
	create(n,t);
}

template <typename T>
List<T>::List(iterator b, iterator e)
{
	create(b,e);
}
template <typename T>
void List<T>::create(size_type n, const T& t)
{
	for(size_type i = 0; i < n; i++)
		push_back(t);
}

template <typename T>
void List<T>::create(iterator b, iterator e)
{
	while (b!=e)
		push_back(*b++);
	
}

template <typename T> 
void List<T>::uncreate()
{
	while (tail)
	{
		Node<T>* node = tail;
		tail = tail->prev;
		delete node;
	}
	head = 0; 
	size = 0;
	
}
template <typename T>
List<T>& List<T>::operator=(const List<T>& tr)
{
	if(this->head)
		uncreate();
	create(tr.begin(), tr.end());
	return *this;
}
template <typename T>
List<T>::~List(){
   uncreate();
};
template <typename T>
void List<T>::push_back(const T& val)
{
   Node<T> *new_node = new Node<T>(val);
   if(size == 0)
   	head = new_node;
   else if(size == 1){
	   new_node->prev = head;
	   tail = new_node;
	   head->next = new_node;
   } else{
	   tail->next = new_node;
	   new_node->prev = tail;
	   tail = new_node;
   }
	size++;
}

template <typename T>
void List<T>::erase(iterator pos )
{
	iterator it = begin();
	while(it!=end()){
		if(it == pos ){
			Node<T>* prev = it.data->prev; 
			Node<T>* next = it.data->next; 
			if(prev != 0)
				prev->next = next;
			if(next != 0)
				next->prev = prev;
			it.data = 0;
			break;
		} 
		it++;
			
	}
}

template <typename T>
void  List<T>::erase(iterator b , iterator e)
{
	while(b!=e){
		iterator pos = b++;
		erase(pos);
	}
}
#endif