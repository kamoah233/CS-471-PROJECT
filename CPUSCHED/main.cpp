#include <iostream> 
#include <mutex>
#include <thread>
#include <chrono> // Fixed typo here
#include <string>


using namespace std;

int numProducers;
int numConsumers;
int sleepTime;
