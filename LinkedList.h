#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

template <class T>
class LinkedList
{
	Node<T> *head, *tail, *temp, *cur, *back;
public:
	LinkedList();
	~LinkedList();
	void appendFront(T data);
	void append(T data);
	void appendPosition(T data);
	void traversePrint() const;
	void traverseRevPrint() const;
	void singlePrint() const;
	int getSize();
	void destroy(T data);
};



#endif
