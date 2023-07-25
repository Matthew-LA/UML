#include "CircularBuffer.hpp"

CircularBuffer::CircularBuffer(int capacity) {
    if (capacity < 1){
        throw std::invalid_argument("Circular Buffer constructor: capacity must be greater than zero");
    }

    last = 0;
    first = 0;
    s = 0;
    cap = capacity;
    buff.resize(capacity);

    return;
}

int CircularBuffer::size() {
    return s;
}

bool CircularBuffer::isEmpty() {
    if(s != 0){
        return false;
    }
    else{
        return true;
    }
}

bool CircularBuffer::isFull() {
    if(s == cap){
        return true;
    }
    else{
        return false;
    }
}
void CircularBuffer::enqueue(int16_t x) {
    if (isFull()){
        throw std::runtime_error("enqueue: can't enqueue to a full buffer");
    }
    if (last >= cap){
        last = 0;
    }
    //Continue
    buff.at(last) = x; 
    last++;
    s++;
}

int16_t CircularBuffer::dequeue() {
    if (isEmpty()){
        throw std::runtime_error("dequeue: can't dequeue an empty buffer");
    }
    int16_t retFirst = buff.at(first);
    buff.at(first) = 0;
    first++;
    s--;

    if (first >= cap){
        first = 0;
    }

    return retFirst;
}

int16_t CircularBuffer::peek() {
    if (isEmpty()){
        throw std::runtime_error("peek: can't peek an empty buffer");
    }
    return buff.at(first);
}

void CircularBuffer::output()
{
    std::cout << "   First: " << first << "\n";
    std::cout << "    Last: " << last << "\n";
    std::cout << "Capacity: " << cap << "\n";
    std::cout << "    Size: " << s << "\n";
    std::cout << "Vector size: " << buff.size() << "\n";
    std::cout << "Vector capacity: " << buff.capacity() << "\n";
    std::cout << "Buffer (no blanks): \n";

    int x = 0;
    int y = first;

    while (x < s)
    {
        // Make the loop go back to 0 to continue printing.
        if (y >= cap){
            y = 0;
        }

        std::cout << buff[y] << " ";
        y++;
        x++;
    }

    std::cout << "\nDump the entire buffer (including blanks): \n";

    for (int x = 0; x < cap; x++) {
        std::cout << buff[x] << " ";
    }

    std::cout << "\n\n";
}
