#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "stdafx.h"
#include <functional>
#include "Node.h"
#include "Clothes.h"

template <class T>
class LinkedList
{
	typedef std::function<void(LinkedList<T>*)> callback; //should be taking void as return type, takes LL as arg (hopefully)
	typedef std::function<double(double, double)> comparator; //heck

public:
	LinkedList();
	LinkedList(const LinkedList<T>& copyList);
	LinkedList& operator=(LinkedList<T> rhs);
	~LinkedList();
	void appendFront(T data);
	void append(T data);
	void appendPosition(T data, int& position);
	void traversePrint(callback callback) const;
	void sort(comparator comparator);
	int getSize() const;
	Node<T>* getFirst();
	Node<T>* getLast();
	void destroy(int pos);

private:
	Node<T> *head, *tail, *temp, *cur;
};

//constructor
template <class T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

//copy constructor, deep copying the list
template <class T>
LinkedList<T>::LinkedList (const LinkedList<T>& copyList) : head(nullptr), tail(nullptr)
{
	if (copyList.head == nullptr)
		return;
	for (Node<T>* node = copyList.head; node != nullptr; node = node->next)
	{
		this->append(node->data);
	}
}

//overriding = operator for copying
template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> rhs)
{
	if (&rhs != this) //remember, this is a ptr!
	{
		temp = head; //this->temp, this->head, lazy to put this because it's the same in this context
		while (head->next != nullptr)
		{
			head = head->next;
			delete temp;
			temp = head;
		}

		for (Node<T>* node = rhs.head; node != nullptr; node = node->next)
		{
			this->append(node->data);
		}
	}
	return *this;
}

//user-defined destr to free dynamically allocated memories
template <class T>
LinkedList<T>::~LinkedList()
{
	while (head != nullptr)
	{
		cur = head;
		head = cur->next;
		delete cur;
	}
}

template <class T>
void LinkedList<T>::appendFront(T data)
{
	cur = new Node<T>(data);
	if (head == nullptr)
		head = cur; //can be shortened but I lazy
	else if (head != nullptr)
	{
		head->prev = cur;
		cur->next = head;
		head = cur;
	}
	tail = cur;
}

template <class T>
void LinkedList<T>::append(T data)
{
	cur = new Node<T>(data);
	if (head == nullptr)
		head = cur;
	else if (tail != nullptr)
	{
		tail->next = cur;
		cur->prev = tail;
	}
	tail = cur;
}

template <class T>
void LinkedList<T>::appendPosition(T data, int& position)
{
	auto count = 1;
	cur = new Node<T>(data);

	if (head == nullptr)
	{
		append(data);
		std::cout << "The list is empty. Creating a new list with this data." << std::endl;
		return;
	}

	temp = new Node<T>;

	if (position > count || position < 1)
	{
		std::cout << "Position out of bound." << std::endl;
	}
	else if (position == 1)
	{
		appendFront(data);
	}
	else if (position < this->getSize())
	{
		temp = head;
		while (temp->next != nullptr && count != position)
		{
			temp = temp->next;
			count++;
		}
		cur->next = temp;
		cur->prev = temp->prev;
		temp->prev->next = cur;
		temp->prev = cur;
	}
	else
	{
		append(data);
	}
}

template <class T>
void LinkedList<T>::traversePrint(callback callback) const
{
	LinkedList<T>* printList = new LinkedList<T>(*this);
	callback(printList);
	for (printList->cur = printList->head; printList->cur; printList->cur = printList->cur->next)
		std::cout << printList->cur->data << std::endl;
	delete printList; //no idea if this works
}

template <class T>
void LinkedList<T>::sort(comparator comparator)
{
	for (Node<Clothes>* i = this->head; i; i = i->next)
	{
		for (Node<Clothes>* j = i->next; j; j = j->next)
		{
			if (comparator(i->data.get_price(), j->data.get_price()) > 0)
			{
				auto temp1 = i->data;
				i->data = j->data;
				j->data = temp1;
			}
		}
	}
}

template <class T>
int LinkedList<T>::getSize() const
{
	int count = 0;
	temp = head;
	while (temp != nullptr)
	{
		++count;
		temp = temp->next;
	}
	return count;
}

template <class T>
Node<T>* LinkedList<T>::getFirst()
{
	return head;
}

template <class T>
Node<T>* LinkedList<T>::getLast()
{
	return tail;
}

template <class T>
void LinkedList<T>::destroy(int pos)
{
	cur = head;
	for (auto i = 1; i < pos; i++)
	{
		cur = cur->next;
	}

	if (cur->next != nullptr)
		cur->next->prev = cur->prev;
	if (cur->prev != nullptr)
		cur->prev->next = cur->next;
	if (head == cur)
		head = cur->next;
	if (tail == cur)
		tail = cur->prev;
	delete cur;
}

#endif

