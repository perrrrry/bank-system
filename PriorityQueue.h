/*
 * PriorityQueue.h
 *
 * Description: Priority Queue
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 * Modified: February 2019
 *
 * Class Invariant:  FIFO order
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
class PriorityQueue {

    private:
        // singly-linked list
        Node<T>* head;
        int len;

        /* You may add private methods to this class */

    public:
        // Desc: Default Constructor. (O(1))
        PriorityQueue();


        // Desc: Copy Constructor. (O(N))
        PriorityQueue(const PriorityQueue& rhs);


        // Desc: Destructor. (O(N))
        ~PriorityQueue();


        // Desc: Returns true if Priority Queue empty. (O(1))
        bool isEmpty() const;


        // Desc: Returns length of the Priority Queue. (O(1))
        int getLength() const;


        // Desc: Inserts x in sorted order. (O(N))
        //  Pre: Priority Queue is sorted.
        // Post: Priority Queue remains sorted.
        void enqueue(const T& x);


        // Desc: Removes the element with "highest" priority. (O(1))
        //  Pre: Priority Queue not empty.
        //       Throws EmptyDataCollectionException if Priority Queue empty.
        void dequeue() throw(EmptyDataCollectionException);


        // Desc: Returns the element with the "highest" priority. (O(1))
        //  Pre: Priority Queue not empty.
        //       Throws EmptyDataCollectionException if Priority Queue empty.
        // Post: Priority Queue is unchanged.
        T& peek() const throw(EmptyDataCollectionException);

}; // PriorityQueue

//default constructor
template <class T>
PriorityQueue<T>::PriorityQueue(){
head = NULL;
len = 0;

}


// Desc: Copy Constructor. (O(N))
template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& rhs){
  //first condition: if rhs is empty
  if(rhs.isEmpty()){
    head = NULL;
    len = 0;}

  else{
    // create a node point to rhs
    Node<T>* curr;
    // create a node point to new queue
    Node<T>* newcop = new Node<T>;
    //point to rhs
    curr = rhs.head;
    //define the head
    head = newcop;
    //get length of rhs
    len = rhs.getLength();
    //deep copy the data from rhs to a new Queue
    while(curr != NULL){
      newcop.data = curr.data;
      newcop->next = new Node<T>;   //create a new node
      newcop = newcop->next;
      curr = curr->next;}
      }
}


// Desc: Destructor. (O(N))
template <class T>
PriorityQueue<T>::~PriorityQueue(){
  Node<T>* curr;
    while(head != NULL){
    curr = head;
    head = head->next;
    delete curr;}
  len=0;

}


// Desc: Returns true if Priority Queue empty. (O(1))
template <class T>
bool PriorityQueue<T>::isEmpty() const{
  return len == 0;
}


// Desc: Returns length of the Priority Queue. (O(1))
template <class T>
int PriorityQueue<T>::getLength() const{
  return len;
}


// Desc: Inserts x in sorted order. (O(N))
//  Pre: Priority Queue is sorted.
// Post: Priority Queue remains sorted.
template <class T>
void PriorityQueue<T>::enqueue(const T& x){
  len++;      //increase the length
  Node<T>* newnode = new Node<T>;
  newnode->data = x;//assign the data
  // if the queue is empty
  if(len=0){
    newnode->next = NULL;
    head = newnode;
  }
  //if this is not empty
  else{
    Node<T>* curr = head;
    //search the next that is NULL or bigger time than x
    while(curr->next->Get_time() <= x->Get_time() || curr!=NULL){
      curr = curr->next;
    }
      //reach the end of the Queue
      if(curr->next == NULL){
        newnode->next = NULL;
        curr->next = newnode;
      }
      else{
        //attach thr newnode between the curr and curr->next
        Node<T>* node = curr->next;
        curr->next = newnode;
        newnode->next = node;
      }
  }
}


// Desc: Removes the element witeadh "highest" priority. (O(1))
//  Pre: Priority Queue not empty.
//       Throws EmptyDataCollectionException if Priority Queue empty.
template <class T>
void PriorityQueue<T>::dequeue() throw(EmptyDataCollectionException){
  Node<T>* curr;
    curr = head;    //create a curr to track the head in order to release the memory
    head = head->next;
    delete curr;
  len--; //decrease the Length
}


// Desc: Returns the element with the "highest" priority. (O(1))
//  Pre: Priority Queue not empty.
//       Throws EmptyDataCollectionException if Priority Queue empty.
// Post: Priority Queue is unchanged.
template <class T>
T& PriorityQueue<T>::peek() const throw(EmptyDataCollectionException){
  return head->data;
}
