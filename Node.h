﻿#pragma once
#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
public:
	T data;
	Node *next, *prev;
};

#endif