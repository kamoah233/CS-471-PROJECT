#ifndef CONSUMER_H
#define CONSUMER_H
#include <mutex>
#include <condition_variable>
#include "buffer.h"

/* void producer(Buffer& buffer, std::mutex& mutex, std::condition_variable& buffer_not_empty,
std::condition_variable& buffer_not_full); */

void consumer(Buffer& buffer, std::mutex& mutex, std::condition_variable& buffer_not_empty,
std::condition_variable& buffer_not_full);

#endif  