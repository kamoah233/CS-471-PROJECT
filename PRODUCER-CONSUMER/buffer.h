#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
#include <thread>
#include <atomic>

void produce(int producer_id);
void consume(int consumer_id);

#endif // BUFFER_H