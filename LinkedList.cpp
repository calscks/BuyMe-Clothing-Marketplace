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
	head = new Node<T>;
	head->data = copyList.head->data;
	head->next = copyList.head->next;
	head->prev = copyList.head->prev;
	while (copyList.head->next != nullptr)
	{
		
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
}

template <class T>
void LinkedList<T>::append(T data)
{
	if (head == nullptr)

}

