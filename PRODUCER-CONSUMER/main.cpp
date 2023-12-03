#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include "buffer.h"
#include "producer.h"

#include <vector>
#include <chrono>

using namespace std;
using namespace std::this_thread;

int main()
{
    int num_producers=1;
    int num_consumers=1;
    int buffer_size=10;

    Buffer buffer (buffer_size);
    std::mutex mutex;
    std::condition_variable buffer_not_empty;
    std::condition_variable buffer_not_full;

    std::vector<std::thread> producers;
    for (int i = 0; i < num_producers; i++) {
        producers.emplace_back(std::thread(producer, std::ref(buffer), std::ref(mutex), std::ref(buffer_not_empty), std::ref(buffer_not_full)));
    } 

    std::vector<std::thread> consumers;
    for (int i = 0; i < num_consumers; i++) {
        consumers.emplace_back(std::thread(consumer, std::ref(buffer), std::ref(mutex), std::ref(buffer_not_empty), std::ref(buffer_not_full)));
    }

    for (auto& producer_thread : producers) {
        producer_thread.join();
    }
    for (auto& consumer_thread : consumers) {
        consumer_thread.join();
    }

}