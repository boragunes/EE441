#pragma once

const int MaxSize = 20;

template <class T>
class Stack{

    private:
        //our stack
        T slist [MaxSize];
        //logical pointer
        int top;

    public:
        Stack(void);
        T Pop(void);
        void Push(const T &item);
        int Stack_Empty(void) const;
        int Stack_Full(void) const;

};


template < class T >
Stack<T>::Stack(void) : top(-1) {}

template < class T >
T Stack<T>::Pop(void){
    T temp;
    if(top == -1){
    std::cout << "nothing to pop " << std::endl;
    exit(1);}
        else{
    temp = slist[top];
    top--;
    return temp;}

}

template <class T>
void Stack<T>::Push(const T &item){
        if (top == MaxSize - 1){
        std::cout << "oh too full of a load no takeyyy!!" << std::endl;
        exit(1);}
            else{
        top++;
        slist[top] = item;}


}
template <class T>
int Stack<T>::Stack_Empty(void) const{
    
    return top == -1;

}

template <class T>
int Stack<T>::Stack_Full(void) const{
    
    return top == MaxSize;

}




