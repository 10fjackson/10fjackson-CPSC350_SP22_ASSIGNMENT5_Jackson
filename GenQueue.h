#ifndef GENQUEUE_H
#define GENQUEUE_H
#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;
template <typename T>
class GenQueue{
  public:
    GenQueue(); // default
    ~GenQueue(); //destructor

    //core functions
    void insert(T data);
    void enqueue(T data);
    T remove(); //aka front()
    T peak();

    //aux functions
    bool isEmpty();
    bool isFull();
    int getSize();

  private:
    DoublyLinkedList<T> *myArray;
    ListNode<T> *rear;
    ListNode<T> *front;
    //int size();

};

template <typename T>
GenQueue<T>::GenQueue(){
  front = NULL;
  rear = NULL;
  //numElements = 0;
  myArray = new DoublyLinkedList<T>();
} // default

//No overloaded constructor needed, no max size

template <typename T>
GenQueue<T>::~GenQueue(){
  delete[] myArray;

} //destructor


//core functions
template <typename T>
void GenQueue<T>::insert(T data){
  //check if queue is is full
  myArray->insertBack(data);
  rear = myArray->getBack();
}

template <typename T>
void GenQueue<T>::enqueue(T data){
  //make sure queue is not empty before proceeding
  myArray->insertFront(data);
  front = myArray->getFront();
}

template <typename T>
T GenQueue<T>::remove(){
  //doubly linked list makes sure queue is not empty before proceeding
    T data = myArray->removeFront();
    return data;
} //aka front()

//aux functions
template <typename T>
bool GenQueue<T>::isEmpty(){
  return (myArray->isEmpty());
  //return (rear == NULL);
}

template <typename T>
T GenQueue<T>::peak(){
    return myArray->getFront();
}

//No isFull function needed

template <typename T>
int GenQueue<T>::getSize(){
  return myArray->getSize();
}

#endif
