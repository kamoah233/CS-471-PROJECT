#include <iostream>
#include <vector>
#include <queue>
#include "Process.h"

using namespace std;

class fifo{
    public:
    fifo(const vector<Process>& processes); 

    void run();


    private:
    vector<Process> processes_;
};