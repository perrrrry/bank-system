

// Class Invariant:  FIFO order
/*
 * Queue.h
 *
 * Class Definition: Queue.h to define the private varibles and public mehtod for Queue
 *
 *
 * Created on: Februar 26 2019
 * Author: Perry Wu
 *
 * None of the provided code (basecode) may be modified.
 */


#pragma once

#include "Node.h"
#include "EmptyDataCollectionException.h"

#include <cstdio>

using namespace std;

template <class T>
class Queue {
    private:
      //seting a head and a tail to track the linked list
      Node<T> * head;
		  Node<T> * tail;
		  int len;
        /* Set privete varivables  */

    public:

        // Desc: Constructor. (O(1))
        Queue();


        // Desc: Returns true if Queue is empty. (O(1))
        bool isEmpty() const;


        // Desc: Inserts x at the "back" of this Queue. (O(1))
        void enqueue(const T& x);


        // Desc: Removes the element at the "front". (O(1))
        //  Pre: Queue not empty.
        //       Throws EmptyDataCollectionException if Queue empty.
        void dequeue() throw(EmptyDataCollectionException);


        // Desc: Returns the element at the "front". (O(1))
        //  Pre: Queue not empty.
        //       Throws EmptyDataCollectionException if Queue empty.
        // Post: Queue is unchanged.
        T& peek() const throw(EmptyDataCollectionException);



        /* you may add more methods */


};


// Desc: Constructor. (O(1))
template <class T>
Queue<T>::Queue() {
head = NULL;
tail = NULL;
len = 0;
} // constructor



// Desc: Returns true if Queue is empty. (O(1))
template <class T>
bool Queue<T>::isEmpty() const {
  return len == 0;
} // isEmpty



// Desc: Inserts x at the "back" of this Queue. (O(1))
template <class T>
void Queue<T>::enqueue(const T& x) {
  //if the Queue is empty
  if(len == 0){
    //create a new node and update the head and tail and len
    Node<T> * newnode = new Node<T>;
    newnode->data = x;
    newnode->next = NULL;
    head = newnode;
    tail = newnode;
    len++;
  }
  else{
        //create a new node and update the tail and len
    Node<T> * newnode = new Node<T>;
    newnode->data = x;
    newnode->next = NULL;
    tail->next = newnode;
    tail = newnode;
    len++;
  }
} // enqueue



// Desc: Removes the element at the "front". (O(1))
//  Pre: Queue not empty.
//       Throws EmptyDataCollectionException if Queue empty.
template <class T>
void Queue<T>::dequeue() throw(EmptyDataCollectionException) {
    if(len == 1){
      //release the memory
      delete head;
      head = NULL;
      tail = NULL;
      len--;}
    
    else{
      Node<T> * newnode;
      newnode = head;
      //move head to the next node
      head = head->next;
      //release the memory
      delete newnode;
      len--;}
} // dequeue



// Desc: Returns the element at the "front". (O(1))
//  Pre: Queue not empty.
//       Throws EmptyDataCollectionException if Queue empty.
// Post: Queue is unchanged.
template <class T>
T& Queue<T>::peek() const throw(EmptyDataCollectionException) {
  return head->data;
} // peek
