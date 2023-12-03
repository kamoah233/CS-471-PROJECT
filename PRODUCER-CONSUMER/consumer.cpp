#include "consumer.h"
#include <iostream>

void consumer(Buffer& buffer, std::mutex& mutex, std::condition_variable& buffer_not_empty,
std::condition_variable& buffer_not_full){
    while (true) {
        Item item;

        std::unique_lock<std::mutex> lock(mutex);
        while (buffer.isempty())
        {
            buffer_not_empty.wait(lock);
        }
        item = buffer.remove();
        std::cout << "Consumed: " << item << std::endl;
        buffer_not_full.notify_one();
    }
}