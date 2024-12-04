#include "stack.hpp"


template < class T>
class Queue{
    private:

        Stack<T> SLIFO,SFIFO;

    public:
        Queue (void);
        void QInsert (const T &item);
        T Qremove (void);
        int QEmpty(void);
        int QFull(void);
        void DisplayQueue(void);

};

template < class T >
void Queue<T>::QInsert(const T &item){

    if(SLIFO.Stack_Full()){
        std::cout<< "Stack is full" << std::endl;
        exit(1);
    }
    else{
        SLIFO.Push(item);
    }


}
template < class T >
T Queue<T>::Qremove(void){
    T temp;
    if(SLIFO.Stack_Empty()){
        std::cout << "stack is empty" << std::endl;
        exit(1);
    }
    while(!(SLIFO.Stack_Empty())){
        SFIFO.Push(SLIFO.Pop());

        
    }
    temp = SFIFO.Pop();
    while(!(SFIFO.Stack_Empty())){
        SLIFO.Push(SFIFO.Pop());
        
    }
    return temp;
}

template <class T > 
int Queue<T>::QEmpty(void){

return SLIFO.Stack_Empty();

}

template <class T > 
int Queue<T>::QFull(void){

return SLIFO.Stack_Full();

}

template <class T>
void Queue<T>::DisplayQueue(void) {
    // Create a temporary stack to preserve the queue order
    Stack<T> tempSLIFO = SLIFO;
    Stack<T> tempSFIFO = SFIFO;

    // Transfer elements from SLIFO to SFIFO for proper ordering
    while (!tempSLIFO.Stack_Empty()) {
        tempSFIFO.Push(tempSLIFO.Pop());
    }

    // Display elements from SFIFO (front to back of the queue)
    std::cout << "Queue contents (front to back): ";
    while (!tempSFIFO.Stack_Empty()) {
        std::cout << tempSFIFO.Pop() << " ";
    }
    std::cout << std::endl;
}
template <class T>
Queue<T>::Queue(void) {
    // Empty constructor body
}