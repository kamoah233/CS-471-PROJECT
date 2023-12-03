#ifndef BUFFER_H
#define BUFFER_H
#include <mutex>
#include <condition_variable>
typedef int Item;
class Buffer {
    public:
        explicit Buffer(int cpacity);
        bool isempty() const;
        bool isfull() const;
        void insert(const Item& item);
        Item remove();

    private:
        int capacity;
        int head;
        int tail;
        Item* buffer;
        mutable std::mutex mutex_;
        std::condition_variable buffer_not_full;
        std::condition_variable buffer_not_empty;
};

#endif