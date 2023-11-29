#include "fifo.h"


// Constructor initializes the scheduler with a queue of processes
fifo::fifo(const std::queue<Process>& processes)
    : processes_(processes), currentTime_(0), totalWaitingTime_(0),
      totalTurnaroundTime_(0), totalResponseTime_(0), processesExecuted_(0) {}


// Function to execute the FIFO scheduling algorithm
void fifo::run(){
    // Loop until all processes are executed or 500 processes are executed

    while (!processes_.empty() && processesExecuted_ < 500) {
        Process currentProcess = processes_.front();
        processes_.pop();

        // If the process arrives after the current time, update the current time
        if (currentTime_ < currentProcess.arrivalTime) {
            currentTime_ = currentProcess.arrivalTime;
        }

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
    }
void fifo::Calculation(){
    int totalProcesses = processesExecuted_;
    double throughput = static_cast<double>(totalProcesses) / currentTime_;
    double cpuUtilization = static_cast<double>(totalTurnaroundTime_) / currentTime_;
    double avgWaitingTime = static_cast<double>(totalWaitingTime_) / totalProcesses;
    double avgTurnaroundTime = static_cast<double>(totalTurnaroundTime_) / totalProcesses;
    double avgResponseTime = static_cast<double>(totalResponseTime_) / totalProcesses;
/*
    cout << "\t\tReport for FIFO CPU Scheduling:" << endl;
    cout << "Number of processes: " << totalProcesses << endl;
    cout << "Throughput: " << throughput << endl;
    cout << "Total elapsed time: " << currentTime_ << endl;
    cout << "CPU utilization: " << cpuUtilization << endl;
    cout << "Average waiting time: " << avgWaitingTime << endl;
    cout << "Average turnaround time: " << avgTurnaroundTime << endl;
    cout << "Average response time: " << avgResponseTime << endl;
*/
    // Write an output file
    ofstream outfile;
    outfile.open("FIFO_Report.txt");

    outfile << "\t\tReport for FIFO CPU Scheduling:" << endl;
    outfile << "Number of processes : " << totalProcesses << endl;
    outfile << "Total elapsed time: (for the scheduler) " << currentTime_ << endl;
    outfile << "Throughput (Number of processes executed in one unit of CPU burst time): " << throughput << endl;
    outfile << "CPU utilization: " << cpuUtilization << endl;
    outfile << "Average waiting time (in CPU burst times): " << avgWaitingTime << endl;
    outfile << "Average turnaround time (in CPU burst times): " << avgTurnaroundTime << endl;
    outfile << "Average response time (in CPU burst times): " << avgResponseTime << endl;

    outfile.close();
}
