#pragma once
template <class T>
class Node
{
public:
	T data;
	Node(T data) : data(data), next(nullptr), prev(nullptr) {}
	Node<T> *next, *prev;
};