#pragma once
#include <iostream>

// Define your Tile struct
class Tile {
public:
    char m_suit;
    int m_number;

    // Default constructor
    Tile() {
		//throw std::logic_error("Function \"default constructor\" is not implemented!");
        m_suit = '\0';
        m_number = 0;
        //Default Constructor Implementation with both m_suit and m_number initialized to zero.
	}

    // Parameterized constructor
    Tile(char s, int n) {
		//throw std::logic_error("Function \"destructor\" is not implemented!");
        m_suit = s;
        m_number = n;
        //Parametrized Constructor Implementation with m_suit = char s and m_number = int n
    }

    // Comparison operator for equality
    bool operator==(const Tile& other) const {
        //throw std::logic_error("Function \"==\" is not implemented!");
        return ((m_suit == other.m_suit ) && (m_number == other.m_number));
    }
    // Overload less-than operator
    bool operator<(const Tile& other) const {
        // throw std::logic_error("Function \"<\" is not implemented!");
           
    // since the suites are declared as B(66)<C(67)<D(68) directly comparing them in given if statement will yield the 
    // correct results.
    if (m_suit != other.m_suit){
        //if they are not equal directly compare the suits
        return m_suit < other.m_suit;
    }
    //if they are equal compare the numbers.
    return m_number < other.m_number;
    }

    // Overload greater-than operator
    bool operator>(const Tile& other) const {
            // similarly do the opposite of the < operator
    if(m_suit != other.m_suit){
        return m_suit > other.m_suit;

    }
    return m_number > other.m_number;
        //throw std::logic_error("Function \">\" is not implemented!");
    }

    bool operator<=(const Tile& other) const {
        //throw std::logic_error("Function \"<=\" is not implemented!");
           //m_suit being smaller then other.m_suit directly makes it smaller
    if(m_suit < other.m_suit){

        return true;
    }
    //again if suites have the same value but m_number is smaller than other.m_number it makes it smaller
    if(m_suit == other.m_suit && m_number < other.m_number){

        return true;
    }

    return false;

    }

    bool operator>=(const Tile& other) const {    
        //throw std::logic_error("Function \">=\" is not implemented!");
           if(m_suit > other.m_suit){

        return true;
    }
    if(m_suit == other.m_suit && m_number > other.m_number){

        return true;
    }

        return false;

    }

    bool operator!=(const Tile& other) const {
        //throw std::logic_error("Function \"!=\" is not implemented!");
        return !(*this == other);
    }

    // Friend function to overload << operator for output
    friend std::ostream& operator<<(std::ostream& os, const Tile& tile) {
        os << tile.m_suit << tile.m_number;
        return os;
    }
};

