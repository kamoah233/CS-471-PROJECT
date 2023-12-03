#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include "buffer.h"
#include "producer.h"
#include "consumer.h"
#include <vector>
#include <chrono>
#include <thread>
#include <iostream>
//#include <pthread.h>

using namespace std::chrono_literals;
using namespace std;
using namespace std::this_thread;

int main(int argc, char* argv[]) {
    int num_producers;
    int num_consumers;
    int buffer_size;

    Buffer buffer (buffer_size);
    std::mutex mutex;
    std::condition_variable buffer_not_empty;
    std::condition_variable buffer_not_full;

    std::vector<std::thread> producers;
    for (int i = 0; i < num_producers; i++) {
        producers.push_back(std::thread(producer, std::ref(buffer), std::ref(mutex), std::ref(buffer_not_empty), std::ref(buffer_not_full)));
    } 

    std::vector<std::thread> consumers;
    for (int i = 0; i < num_consumers; i++) {
        consumers.push_back(std::thread(consumer, std::ref(buffer), std::ref(mutex), std::ref(buffer_not_empty), std::ref(buffer_not_full)));
    }

    for (auto& thread : producers) {
        thread.join();
    }
    for (auto& thread : consumers) {
        thread.join();
    }
}