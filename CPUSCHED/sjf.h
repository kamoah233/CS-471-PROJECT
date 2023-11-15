#ifndef SJF_H
#define SJF_H
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>
#include "Process.h"

using namespace std;

class sjf{
    public:
    // Constructor takes a queue of processes as input
    sjf(const queue<Process>& processes); 
    // Function to execute the SJF scheduling algorithm
    void run();
    // Function to calculate the data of the run
    void Calculation();

    private:
    queue<Process> processes_;      // Queue of processes to be scheduled
    int currentTime_;               // Current time during scheduling
    int totalWaitingTime_;          // Total waiting time for all processes
    int totalTurnaroundTime_;       // Total turnaround time for all processes
    int totalResponseTime_;         // Total response time for all processes
    int processesExecuted_;         // Number of processes executed
};


#endif // SJF