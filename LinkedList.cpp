#include "stdafx.h"
#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr)
{
	cur = new Node<T>;
	cur->prev = cur->next = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyList) : head(nullptr), tail(nullptr)
{
	//deep copying the whole linked list
	if (copyList.head == nullptr)
		return;
	for (Node<T>* node = copyList.head; node != nullptr; node = node->next)
	{
		this->append(node->data);
	}
}

template <class T>
LinkedList<T>::~LinkedList()
{
	cur = head;
	while (cur != nullptr)
	{
		head = head->next;
		delete cur;
		cur = head;
	}
	delete head;
	delete tail;
}

template <class T>
void LinkedList<T>::append(T data)
{
	cur = new Node<T>;
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
	cur = new Node<T>;
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
	cur = new Node<T>;
	cur->data = data;

	if (head == nullptr)
	{
		append(data);
		std::cout << "The list is empty. Creating a new list with this data." << std::endl;
		return;
	}

	Node<T>* back = new Node<T>;
	temp = new Node<T>;
	temp = head;
	
	if (position > count || position < 1)
	{
		std::cout << "Position out of bound." << std::endl;
	} else if (position == 1)
	{
		appendFront(data);
	} else
	{
		while (temp->next != nullptr && count != position)
		{
			back = temp;
			temp = temp->next;
			count++;
		}
	}

}