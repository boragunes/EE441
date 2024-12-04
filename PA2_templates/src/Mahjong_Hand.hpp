#pragma once
#include <algorithm>
#include "Tile.hpp"

#define MAX_HAND_SIZE 14
class Hand {
private:
    Tile* m_tiles[MAX_HAND_SIZE];        // Array of pointers to Tile objects
    size_t m_handSize;       // Current hand size

    void insert_before(size_t index, Tile* new_tile) {
        //throw std::logic_error("Function \"insert_before\" is not implemented!");
        //edge case handling where you try to insert even though your hand is full
    if(m_handSize >= MAX_HAND_SIZE){

        throw std::out_of_range("Your hand is already full.");

    }
    //shift all the indexes by 1 to the right
    for (size_t i = m_handSize; i > index; --i) {
        m_tiles[i] = m_tiles[i - 1];
    }
    //after shifting operation add the new_tile to corresponding index
    m_tiles[index] = new_tile;

    m_handSize++; 
    };

    Tile * pop(size_t index) {
    //throw std::logic_error("Function \"pop\" is not implemented!");
        
    if(index >= m_handSize) {

        throw::std::out_of_range("Index out of bonds.");
    }
    Tile* removedTile = m_tiles[index];

    for (size_t i = index; i < m_handSize - 1; i++){

        m_tiles[i] = m_tiles[i+1];
        
    }
    m_tiles[m_handSize - 1] = nullptr;

    m_handSize--;

    return removedTile;

    };
public:
    // Constructors and Destructor
    Hand() {
        //throw std::logic_error("Function \"default constructor\" is not implemented!");
            //it iterates to make all m_tiles nullptr (making them uninitialized may result in a bad situations)
    
    m_handSize = 0;
    for (size_t i = 0; i < MAX_HAND_SIZE; i++){
        m_tiles[i] = nullptr;

    }

    };
    ~Hand() {
        //throw std::logic_error("Function \"destructor\" is not implemented!");
        //similarly for all already non nullptr m_tiles it deletes the memory allocated and assigns nullptr .
    for (size_t i = 0; i < m_handSize; ++i) {
            if (m_tiles[i] != nullptr) {
                delete m_tiles[i];
                m_tiles[i] = nullptr;
            }
        }
    };

    // Member Functions
    void clear() {
        //throw std::logic_error("Function \"clear\" is not implemented!");;
            // Iterate through all the tiles in the hand
    for (size_t i = 0; i < m_handSize; ++i) {
        if (m_tiles[i] != nullptr) {
            delete m_tiles[i];   // Delete the dynamically allocated Tile object
            m_tiles[i] = nullptr; // Set the pointer to nullptr to avoid dangling references
        }
    }

    // Reset the hand size to 0
    m_handSize = 0;
    };

    void add_tile(Tile* tile) {
        //throw std::logic_error("Function \"add_tile\" is not implemented!"); 
            //error handling
    if(m_handSize >= MAX_HAND_SIZE) {

        throw::std::out_of_range("Cannot add more tiles! Your hand is full");
    }
    //finding correct place to add tile mechanism
    size_t index = 0;
    while(index < m_handSize && *m_tiles[index] < * tile) {

        index++;
    }
    
    insert_before(index,tile);    
    };

    Tile* discard_tile(void) {
        //throw std::logic_error("Function \"discard_tile\" is not implemented!");
        
    if(m_handSize == 0) {

        throw std::logic_error("Hand is empty!");
    }
    for(size_t i = 0; i < m_handSize - 4; i++) {
        if(*m_tiles[i] == *m_tiles[i+1] &&
           *m_tiles[i] == *m_tiles[i+2] &&
           *m_tiles[i] == *m_tiles[i+3]){

            Tile * discarded = pop(i);
            std::cout << "Discarded Tile" << *discarded << std::endl;
            
            return discarded;
           }

    }
    for(size_t i = 0; i < m_handSize; i++){
        bool isSingle = true;
        if(i > 0 && *m_tiles[i] == *m_tiles[i-1]){
            isSingle = false;
        }
        if(i< m_handSize - 1 && *m_tiles[i] == *m_tiles[i+1]){
            isSingle = false;
        }
    
        if (isSingle) {
            Tile * discarded = pop(i);
            std::cout << "Discarded tile (single): " << *discarded << std::endl;
        
            return discarded;

        }
    }

    size_t nr_of_pairs = 0;
    for(size_t i = 0; i < m_handSize - 1; i++ ) {
        if(*m_tiles[i] == *m_tiles[i+1]) {

            ++nr_of_pairs;
            Tile * discarded = pop(i);

            std::cout << "Discarded tile (pair): " << *discarded << std::endl;
            
            return discarded;
        }

    }


    std::cout << "No tiles to discard." << std::endl;
    return nullptr;
    };

    bool check_win_condition() const {
        //throw std::logic_error("Function \"check_win_condition\" is not implemented!");
            if (m_handSize != 14) {
        return false; // Winning condition requires exactly 14 tiles in the hand
    }

    // Step 1: Check if the first two tiles form a pair
    if (*m_tiles[0] == *m_tiles[1]) {
        // Check the remaining tiles for 4 triplets
        size_t i = 2; // Start after the pair
        while (i < m_handSize) {
            if (i + 2 >= m_handSize || 
                !(*m_tiles[i] == *m_tiles[i + 1] && *m_tiles[i] == *m_tiles[i + 2])) {
                return false; // Not a triplet
            }
            i += 3; // Skip the triplet
        }
        return true;
    }

    // Step 2: Check if the last two tiles form a pair
    if (*m_tiles[m_handSize - 2] == *m_tiles[m_handSize - 1]) {
        // Check the preceding tiles for 4 triplets
        size_t i = 0; // Start at the beginning
        while (i < m_handSize - 2) {
            if (i + 2 >= m_handSize - 2 || 
                !(*m_tiles[i] == *m_tiles[i + 1] && *m_tiles[i] == *m_tiles[i + 2])) {
                return false; // Not a triplet
            }
            i += 3; // Skip the triplet
        }
        return true;
    }

    // If neither the first two nor the last two tiles form a pair, return false
    return false;
    };

    // Display Function
    void display_hand() const {
        //throw std::logic_error("Function \"display_hand\" is not implemented!");  
        
    for(size_t i = 0; i < m_handSize; i++){

        if(m_tiles[i] != nullptr){

            std::cout << *m_tiles[i] << " " ;

        }

        
    } 
    std::cout << std::endl; 
    };
};


















