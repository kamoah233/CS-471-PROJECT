/*#include "priority.h"

bool comparison process (process a, process b){
    return (a.priority < b.priority)
}*/

#include "priority.h"

// Constructor initializes the scheduler with a queue of processes
priority::priority(const std::queue<Process>& processes)
    : processes_(processes), currentTime_(0), totalWaitingTime_(0),
      totalTurnaroundTime_(0), totalResponseTime_(0), processesExecuted_(0) {}


// Function to execute the FIFO scheduling algorithm
void priority::run(){

    priority_queue<Process, vector<Process>, function<bool(Process,Process)>> prioritylist([] (Process a, Process b)
    {return a.priority > b.priority; });

    // Loop until all processes are executed or 500 processes are executed

    while (!processes_.empty() && processesExecuted_ < 500) {
        while(!processes_.empty()&& processes_.front().arrivalTime<= currentTime_){
            prioritylist.push(processes_.front());
            processes_.pop();
        }

        if(!prioritylist.empty()){
            Process currentProcess = prioritylist.top();
            prioritylist.pop();

        // Update start time, end time, waiting time, and turnaround time for the process
        currentProcess.startTime = currentTime_;
        currentProcess.endTime = currentProcess.startTime + currentProcess.burstTime;
        totalWaitingTime_ += currentTime_ - currentProcess.arrivalTime;
        totalTurnaroundTime_ += currentProcess.endTime - currentProcess.arrivalTime;
        totalResponseTime_ += currentProcess.startTime - currentProcess.arrivalTime;

        currentTime_ = currentProcess.endTime;

        cout << "ID: " << currentProcess.id
             << ", Arrival Time: " << currentProcess.arrivalTime
             << ", Burst Time: " << currentProcess.burstTime
             << ", Priority: " << currentProcess.priority << endl;

        processesExecuted_++;
        }
        else
        {
            currentTime_++;
        }
    }
}

void priority::Calculation(){
    int totalProcesses = processesExecuted_;
    double throughput = static_cast<double>(totalProcesses) / currentTime_;
    double cpuUtilization = static_cast<double>(totalTurnaroundTime_) / currentTime_;
    double avgWaitingTime = static_cast<double>(totalWaitingTime_) / totalProcesses;
    double avgTurnaroundTime = static_cast<double>(totalTurnaroundTime_) / totalProcesses;
    double avgResponseTime = static_cast<double>(totalResponseTime_) / totalProcesses;

    // Write an output file
    ofstream outfile;
    outfile.open("PRIORITY_Report.txt");

    outfile << "\t\tReport for PRIORITY CPU Scheduling:" << endl;
    outfile << "Number of processes : " << totalProcesses << endl;
    outfile << "Total elapsed time: (for the scheduler) " << currentTime_ << endl;
    outfile << "Throughput (Number of processes executed in one unit of CPU burst time): " << throughput << endl;
    outfile << "CPU utilization: " << cpuUtilization << endl;
    outfile << "Average waiting time (in CPU burst times): " << avgWaitingTime << endl;
    outfile << "Average turnaround time (in CPU burst times): " << avgTurnaroundTime << endl;
    outfile << "Average response time (in CPU burst times): " << avgResponseTime << endl;

    outfile.close();
}