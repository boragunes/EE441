#pragma once
#include <iostream>
// defines the fixed size of array
const int maxSize = 20;


//defines the what type of variable will class work on
template < class T >

//actual class definition
class Array{
        private:
        
        //creating mArray with maximum size
        T mArray[maxSize];


        public:
        //member functions
        void SetValue(T val, int pos);
        T getValue(int pos) const;
        void Display(void) const;
        Array(void);
        
        


};




// implementation of the constructor
template < class T >
Array<T>::Array(void) : mArray() {} //create an array with default values


//implementation of the Display function

template < class T >
void Array<T>::Display(void) const{

	for (int i = 0; i < maxSize; i++)
		std::cout << mArray[i] << " " << std::endl;

}

//implementation of the SetValue Function
template < class T >
void Array<T>::SetValue(T val, int pos){
//Check if pos is suitable value 
	if(pos >= 0 && pos < maxSize)
			mArray[pos] = val;
	else
		std::cout << "out of range" << std::endl;

}

//implementation of the getValue Function
template < class T >
T Array<T>::getValue(int pos) const {

	if(pos >= 0 && pos < maxSize)
			return mArray[pos];
	else
		std::cout << "out of range" << std::endl;
}