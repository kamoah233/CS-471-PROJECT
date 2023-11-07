#include <iostream> 
#include <fstream>
#include <mutex>
#include <thread>
#include <chrono> // Fixed typo here
#include <string>
#include <queue>


using namespace std;

int numProducers;
int numConsumers;
int sleepTime;

const int consumer_max_wait_time = 200; // in ms - max time that a consumer can wait for a product to be consumed
const int max_production = 16;  // when producers has produced this quantity they will stop to produce
const int max_products = 16;  //maximum number of products that can be stored

atomic<int> num_producers_working(0); // when there's no number of producers working the program will stop; the consumer stop as well

stack<int> products; // The products stack, where we will store our products
mutex m; // mutex for the products stack

condition_variable is_not_full; // condition variable for the products stack; to indicate that our stack is not full between the thread operations 
condition_variable is_not_empty; // condition variable for the products stack; to indicate that our stack is not empty between the thread operations        

/**
 * Produce function
 * @param producer_id
*/

void produce(int producer_id){
    unique_lock<mutex> lock(m);
    int product;
    is_not_full.wait(lock, []{return products.size()!= max_products;});
    product = products.size();
    products.push(product);
    is_not_empty.notify_all();



}

/**
 * Consume
 * @param consumer_id
*/

void consume(int consumer_id){
    unique_lock<mutex> lock(m);
    int product;

    if(is_not_empty.wait_for(lock, chrono::milliseconds(consumer_max_wait_time),
    []{return products.size()> 0;})){
        product = products.top();
        products.pop();
        is_not_full.notify_all();
    }
}


