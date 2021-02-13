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
	reference operator*()
	{
		return data->val;
	}

	pointer operator->()
	{
		return &(data->val);
	}
	private:
		_Node *data;
};
template <typename T>
class List
{
public:
	typedef ListIterator<T> iterator;
	typedef const ListIterator<T> const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;
	List();
	~List();
	void push_back(const T &);
	iterator begin() { return iterator(head); }
	iterator end() { return iterator(0); }
	const_iterator begin() const { return iterator(head); }
	const_iterator end() const { return iterator(0); }

private:
	Node<T> *head;
	Node<T> *tail;
	size_type size;
	
};
template <typename T>
List<T>::List(){
	size = 0;
   	head = nullptr; 
};

template <typename T>
List<T>::~List(){
   while(tail){
	   Node<T> *node = tail;
	   tail = tail->prev;
	   delete node; 
   }
   head = 0;
   size = 0;
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

#endif