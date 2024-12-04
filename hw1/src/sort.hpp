//Required libraries that will be utilized 
#include <iostream>
#include <stdexcept>


#define SORTEDLIST_MAX_SIZE 20
//Definition of SortedList Class
class SortedList{
    private:
    //private members of the class
    float liste[SORTEDLIST_MAX_SIZE]; // actual array that holds the elements
    size_t size; // size_t for the size of list.

    public:
    
    SortedList(size_t size = 0); // member initializer that sets the size of the list to zero.
    void copy(const SortedList& other); // public member function for copying stuff.
    float index(size_t ind); // a public member function which will return the number at the given index
    size_t insert(float number); // a public member function that is used for inserting float numbers
    float remove(size_t index); // a public member function that removes the value in the index of that list
    size_t find(float number); // a public member function that uses binary search algorithm to find the number
    void printList() const; // a public member function that is used to print the values in the array





};