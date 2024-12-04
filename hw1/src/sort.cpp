#include "sort.hpp"
#include <iostream>
#include <stdexcept>

// will be use for implementation of the defined class

//constructor implementation
SortedList::SortedList(size_t initial_size) : size(initial_size) {
    // check initial size 
    if (size > SORTEDLIST_MAX_SIZE) {
        throw std::out_of_range("Initial size exceeds maximum allowed size.");
    }
}


//copy function implementation
void SortedList::copy(const SortedList& other){

    size = other.size;
    //i = 0 , increase i for every for loop if i < size
    for (size_t i = 0; i < size; ++i ){
        
        //copy the members of list to actual list.
        liste[i] = other.liste[i];

    }


};

//implementation of index function
float SortedList::index(size_t ind){
    //used for throwing errors
    if(ind >= size) {

        throw std::out_of_range("Index is out of range.");

    }
    //if not return the object in that indices
    return liste[ind];
};

//implementation of sortedlist
size_t SortedList::insert(float number){

    if (size >= SORTEDLIST_MAX_SIZE) {
        throw std::out_of_range("cannot insert,list is full");
    }
    size_t position = 0;

    //to find the place where to put newcomer data (linear search)
    while (position < size && liste[position] < number){
        ++position;

    }

    //shifting the other things 
    for(size_t i = size; i > position; --i){

        liste[i] = liste[i-1];

    }
    //finally inserting the number.
    liste[position] = number;
    ++size;
    return position;
};

float SortedList::remove(size_t index){
    if (size >= SORTEDLIST_MAX_SIZE) {
        throw std::out_of_range("cannot insert,list is full");
    }

    float removedValue = liste[index];

    for (size_t i = index; i < size - 1; ++i) {
        liste[i] = liste[i + 1];
    }

    --size;

    return removedValue;




};


size_t SortedList::find(float number){

    size_t low = 0;
    size_t high = size - 1;
    while( low <= high ){
        size_t mid = low + (high - low) / 2;


        if(liste[mid] == number ){
            return mid;
        }

        if(liste[mid] < number){
            low = mid + 1;
        }

        if(liste[mid] > number){
            high = mid - 1;
        }
    }


    throw std::domain_error("Number not found in the list.");

};

void SortedList::printList() const {

    if(size == 0) {

        std::cout << "List is empty" << std::endl;
        return;
    }
    for (size_t i = 0; i < size; i++){
        std::cout << liste[i] << " " << std::endl;

    }

};