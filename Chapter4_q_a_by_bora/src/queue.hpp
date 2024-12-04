#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

const int MaxQSize = 50;
template < class T>

class Queue{
        private:
        int front,rear,count;
        T qlist[MaxQSize];

        public:
        Queue(void);
        void QInsert(const T &item);
        T QDelete(void);
        void ClearQueue(void);
        T QFront(void) const;
        int QLength(void) const;
        int QEmpty(void) const;
        int QFull(void) const;
  

};

template <class T >
Queue<T>::Queue(void) : front(0) , rear(0), count(0){}

template <class T>
void Queue<T>::QInsert(const T &item) {
    if(count == MaxQSize){

        cerr<<"Queue overflow!" << endl;
        exit(1);
    }
    count++;
    qlist[rear] = item;
    rear = (rear+1)%MaxQSize;
}

template <class T>
T Queue<T>::QDelete(void) {

    T temp;
    if (count == 0){

        cerr << "deleting from an empty queue" << endl;

    }
    temp = qlist[front];
    count--;
    front = (front + 1) % MaxQSize;
    return temp;

}


template <class T>
void Queue<T>::ClearQueue(void){

    front = 0 ; rear = 0; count = 0;
}

template <class T>
T Queue<T>::QFront(void) const {
    T temp;
    if(count==0){
        cerr << "Accesing to an empty queue" << endl;

    }
    temp = qlist[front];
    return temp;
}

template <class T >
int Queue<T>::QLength(void) const {
    return count;
}

template <class T >
int Queue<T>::QEmpty(void) const {
    return count == 0;
}

template <class T >
int Queue<T>::QFull(void) const {
    return count == MaxQSize;
}