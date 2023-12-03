#ifndef PRODUCER_H
#define PRODUCER_H
#include "buffer.h"
#include <mutex>
#include <condition_variable>

/* void producer(Buffer& buffer, std::mutex& mutex, std::condition_variable& buffer_not_empty, 
std::condition_variable& buffer_not_full); */

void producer(Buffer& buffer, std::mutex& mutex, std::condition_variable& buffer_not_empty, std::condition_variable& buffer_not_full);

#endif