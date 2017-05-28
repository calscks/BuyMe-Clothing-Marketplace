#include "stdafx.h"
#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr)
{
	cur = new Node;
	cur->prev = cur->next = nullptr;
}

//deep copying whole linked list
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyList) : head(nullptr), tail(nullptr)
{
	if (copyList.head == nullptr)
		return;
	for (Node* node = copyList.head; node != nullptr; node = node->next)
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

		for (Node* node = rhs.head; node != nullptr; node = node->next)
		{
			this->append(node->data);
		}
	}
	return *this;
}

//destructor
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
void LinkedList<T>::append(T data)
{
	cur = new Node;
	cur->data = data;
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
void LinkedList<T>::appendFront(T data)
{
	cur = new Node;
	cur->data = data;
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
void LinkedList<T>::appendPosition(T data, int& position)
{
	auto count = 1;
	cur = new Node;
	cur->data = data;

	if (head == nullptr)
	{
		append(data);
		std::cout << "The list is empty. Creating a new list with this data." << std::endl;
		return;
	}

	temp = new Node;
	
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
int LinkedList<T>::getSize()
{
	auto count = 0;
	temp = head;
	while (temp != nullptr)
	{
		++count;
		temp = temp->next;
	}
	return count;
}

//call using lambda expression. gotta try
//[](LinkedList<T> aList){}
template <class T>
void LinkedList<T>::traversePrint(callback callback) const
{
	LinkedList<T>* printList = new LinkedList<T>(*this);
	callback(printList);
	delete printList; //no idea if this works
}

