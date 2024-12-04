#pragma once

#include <iostream>
#include <stdexcept>
template <class T>
class Stack
{
private:
    size_t m_capacity;
    size_t m_size;
    T* m_data;

public:
    Stack() {
		//throw std::logic_error("Function \"default constructor\" is not implemented!");
        m_capacity = 0;
        m_size = 0;
        m_data = nullptr;
	}
    Stack(size_t capacity)
    {
       //throw std::logic_error("Function \"constructor\" is not implemented!");
       m_capacity = capacity;
       m_size = 0;
       m_data = new T[capacity];
    }
    ~Stack()
    {
        //throw std::logic_error("Function \"destructor\" is not implemented!");
        delete[] m_data;
    }

    bool is_empty() const {
        //throw std::logic_error("Function \"is_empty\" is not implemented!");
        //basically checks whether or not m_size = 0 since if it is zero it means stack is empty.
        return m_size == 0;
    }

    void clear() {
        //throw std::logic_error("Function \"clear\" is not implemented!");
    delete[] m_data;

    m_data = nullptr;
    m_capacity = 0;
    m_size = 0;
    }

    void reserve(size_t new_capacity)
    {
        //throw std::logic_error("Function \"reserve\" is not implemented!");
        //first lets make sure that new_capacity is not smaller than zero

    if(new_capacity == 0){

        throw std::invalid_argument("New capacity must be greater than 0.");
    }
    // if new_capacity is same as old capacity do nothing my friend!
    if(new_capacity == m_capacity){
        return;

    }
    //allocate some new data for new array

    T* new_data = new T[new_capacity];

    //decide the how many times for loop will turn.
    //basically do std::min

    size_t elements_to_copy = (m_size < new_capacity) ? m_size : new_capacity;

    for (size_t i = 0 ; i < elements_to_copy ; i++) {

        new_data[i] = m_data[i];
    }

    delete[] m_data;

    m_data = new_data;
    m_capacity = new_capacity;

    m_size = elements_to_copy;
    }

    void push_back(const T& value)
    {
       // throw std::logic_error("Function \"push_back\" is not implemented!");
       
    if (m_size >= m_capacity){
        //double the capacity if m_capacity is not zero or make it 1 if m_capacity is zero
        size_t new_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        reserve(new_capacity); // then reserve it 
    }

    m_data[m_size++] = value;
    }

    T pop_back()
    {   
      //  throw std::logic_error("Function \"pop_back\" is not implemented!");
      
    if(is_empty()){

        throw std::out_of_range("Cannot pop from an empty stack.");
    }


    return m_data[m_size--];
    }

    // Friend function to overload << operator for output
    friend std::ostream& operator<<(std::ostream& os, const Stack& stack)
    {
        os << "[ ";
        for (size_t i = 0; i < stack.m_size; ++i) {
            os << stack.m_data[i] << ' ';
        }
        os << ']';
        return os;
    }
};





