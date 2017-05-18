#include "stdafx.h"
#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr)
{
	cur = new Node<T>;
	cur->prev = cur->next = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& LL)
{
	
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
