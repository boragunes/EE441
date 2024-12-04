#include "sort.hpp"
#include <iostream>

int main() {
    // Create the first SortedList and add some elements
    SortedList list1;
    list1.insert(3.5);
    list1.insert(7.2);
    list1.insert(1.4);
    
    std::cout << "Contents of list1:" << std::endl;
    list1.printList();

    // Create a second SortedList and copy contents from list1
    SortedList list2;
    list2.copy(list1);

    std::cout << "\nContents of list2 after copying from list1:" << std::endl;
    list2.printList();

    // To confirm that it's a true copy, we can modify list1 and show that list2 remains unchanged
    list1.insert(5.0);

    std::cout << "\nContents of list2 remain unchanged after modifying list1:" << std::endl;
    list2.printList();

    std::cout << "we will remove 3.5" << std::endl;
    
    list1.remove(0);
    list1.printList();
     std::cout << "we removed" << std::endl;
    list1.find(5.0);

    
    
}
