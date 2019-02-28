/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list (template)
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: Februar 26 2019
 * Author: Perry Wu
 */
 // #pragma once is shorthand for the 2 #include guards we've seen before:
 // #ifndef _NODE and #define _NODE
 // and it means: do not include me more than once.
#pragma once

#include <cstdio>  // Needed for NULL

using namespace std;


template <class T>
class Node {


    public:
      T data;      // The data for any data type in the node
      Node* next;   // Pointer to next node
      // Constructors
      Node();
      Node(T theData);
      Node(T theData, Node* theNextNode);

}; // Node

//define the constructors
template <class T>
Node<T>::Node() {
	data = NULL;
	next = NULL;
}
//define the constructors
template <class T>
Node<T>::Node(T theData) {
	data = theData;
	next = NULL;
}
//define the constructors
template <class T>
Node<T>::Node(T theData, Node* theNextNode) {
	data = theData;
	next = theNextNode;
}
