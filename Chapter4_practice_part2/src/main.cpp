#include <iostream>
#include "stack.hpp"
#include "queue.hpp" // Include your Queue implementation

int main() {
    // Create a Queue of integers
    Queue<int> queue;

    // Insert elements into the queue
    std::cout << "Inserting elements into the queue..." << std::endl;
    queue.QInsert(10);
    queue.QInsert(20);
    queue.QInsert(30);
    queue.QInsert(40);
    queue.QInsert(50);

    // Display queue contents
    std::cout << "\nDisplaying the queue after insertion:" << std::endl;
    queue.DisplayQueue();

    // Displaying behavior of QRemove
    std::cout << "\nRemoving elements from the queue (FIFO behavior):" << std::endl;
    std::cout << "Removed: " << queue.Qremove() << std::endl; // Should print 10
    queue.DisplayQueue();

    std::cout << "Removed: " << queue.Qremove() << std::endl; // Should print 20
    queue.DisplayQueue();

    // Insert more elements to test reusability
    std::cout << "\nInserting more elements..." << std::endl;
    queue.QInsert(60);
    queue.QInsert(70);
    queue.DisplayQueue();

    // Remove remaining elements
    std::cout << "\nRemoving the remaining elements:" << std::endl;
    while (!queue.QEmpty()) {
        std::cout << "Removed: " << queue.Qremove() << std::endl;
        queue.DisplayQueue();
    }

    // Test QEmpty
    std::cout << "\nChecking if the queue is empty: ";
    if (queue.QEmpty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }

    return 0;
}
