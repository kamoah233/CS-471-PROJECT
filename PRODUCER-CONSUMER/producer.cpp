#include "producer.h"
#include "buffer.h"
#include <random>
#include <iostream>
#include <condition_variable>
#include <mutex>



void producer(Buffer& buffer, std::mutex& mutex, std::condition_variable& buffer_not_empty,
std::condition_variable& buffer_not_full){
    while (true) {
        Item item = std::rand();

        std::unique_lock<std::mutex> lock(mutex);
        while (buffer.isfull())
        {
            buffer_not_full.wait(lock);
    }
    buffer.insert(item);
    std::cout << "Produced: " << item << std::endl;
    buffer_not_empty.notify_one();
    }

}