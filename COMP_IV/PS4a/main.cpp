#include "CircularBuffer.hpp"

int main(){
    std::cout << "Test main.\n";

    CircularBuffer test(100);
    test.enqueue(1);
    test.enqueue(2);
    test.enqueue(3);
    std::cout << "Peek: " << test.peek() << "\n";

    std::cout << "Deq 1: " << test.dequeue() << "\n";
    std::cout << "Deq 2: " << test.dequeue() << "\n";

    test.output();

    // Test looping back around
    CircularBuffer test2(3);

    test2.enqueue(1);
    test2.enqueue(2);
    test2.enqueue(3);

    test2.dequeue();
    test2.dequeue();
    test2.dequeue();

    test2.enqueue(1);
    test2.enqueue(2);
    test2.enqueue(3);
    test2.dequeue();
    test2.enqueue(4);

    test2.output();

    return 0;
}
