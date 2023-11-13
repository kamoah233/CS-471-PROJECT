#ifndef PROCESS_H
#define PROCESS_H


struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    int startTime;
    int endTime;
    int remainingTime;
};

#endif // PROCESS_H