#include "sjf.h"

// Constructor initializes the scheduler with a queue of processes
sjf::sjf(const std::queue<Process>& processes)
    : processes_(processes), currentTime_(0), totalWaitingTime_(0),
      totalTurnaroundTime_(0), totalResponseTime_(0), processesExecuted_(0) {}

void sjf::run(){
    vector<Process> sortedList;
    int i = 0;
    while (!processes_.empty() && i <500){
        sortedList.push_back(processes_.front());
        processes_.pop();
        i++;
    }
    sort(sortedList.begin(), sortedList.end(), [](const Process &a, const Process &b)
    {
     if (a.burstTime == b.burstTime)
              {
             return a.arrivalTime < b.arrivalTime; 
         }
         return a.burstTime < b.burstTime; });
    //sort(sortedList.begin(), sortedList.end(),);
    for(const Process &p : sortedList){
        if (currentTime_ < p.arrivalTime){
            currentTime_ = p.arrivalTime;
        }
        Process currentProcess = p;
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

void sjf::Calculation(){
    int totalProcesses = processesExecuted_;
    double throughput = static_cast<double>(totalProcesses) / currentTime_;
    double cpuUtilization = static_cast<double>(totalTurnaroundTime_) / currentTime_;
    double avgWaitingTime = static_cast<double>(totalWaitingTime_) / totalProcesses;
    double avgTurnaroundTime = static_cast<double>(totalTurnaroundTime_) / totalProcesses;
    double avgResponseTime = static_cast<double>(totalResponseTime_) / totalProcesses;

    // Write an output file
    ofstream outfile;
    outfile.open("SJF_Report.txt");

    outfile << "\t\tReport for SJF CPU Scheduling:" << endl;
    outfile << "Number of processes : " << totalProcesses << endl;
    outfile << "Total elapsed time: (for the scheduler) " << currentTime_ << endl;
    outfile << "Throughput (Number of processes executed in one unit of CPU burst time): " << throughput << endl;
    outfile << "CPU utilization: " << cpuUtilization << endl;
    outfile << "Average waiting time (in CPU burst times): " << avgWaitingTime << endl;
    outfile << "Average turnaround time (in CPU burst times): " << avgTurnaroundTime << endl;
    outfile << "Average response time (in CPU burst times): " << avgResponseTime << endl;

    outfile.close();
}