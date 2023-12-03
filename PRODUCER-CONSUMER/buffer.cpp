#include "buffer.h"

Buffer::Buffer(int capacity) : capacity(capacity), head(0), tail(0), buffer(new Item[capacity]) {}

bool Buffer::isempty() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return head == tail;
}

bool Buffer::isfull() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return (tail+1) % capacity == head;
}

void Buffer::insert(const Item& item) {
    //std::lock_guard<std::mutex> lock(mutex_);
    std::unique_lock<std::mutex> lock(mutex_);
    while (isfull()) {
        buffer_not_full.wait(lock);
    }
    buffer [tail] = item;
    tail = (tail+1) % capacity;
    buffer_not_empty.notify_one();
}

Item Buffer::remove() {
    std::unique_lock<std::mutex> lock(mutex_);
    while (isempty()) {
        buffer_not_empty.wait(lock);
    }
    Item item = buffer[head];
    head = (head+1) % capacity;
    buffer_not_full.notify_one();
    return item;
}