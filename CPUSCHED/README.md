# CS471 Project - Problem 1

## Authors
Kofi Amoah
Truong Pham

## Description

This program will act as a CPU scheduler and handle scheduling 500 simulated processes. The user will choose which
scheduling algorithm to handle the processes: FIFO, SJF without preemption, Priority with preemption



## Input file

The program takes an input text file titled : Datafile1-txt.txt


## Compiling the program

Starting from the source code, the program can be compiled 

Must direct to folder CPUSCHED, then

The program can be compile in Terminal using the following command:
g++ -o main  main.cpp fifo.cpp sjf.cpp priority.cpp


## Running the program

The program can be run in Terminal using the following command:

./main


## The program can be run in Terminal using the following command:



## Output

The output files have the following structure: "output - [ Scheduling Type ]_Report.txt", such as:

Output-FIFO_Report.txt

Output-PriorityReport.txt

Output-SJFReport.txt

Each output file will have the following contents:

Number of processes :
Total elapsed time: (for the scheduler)
Throughput (Number of processes executed in one unit of CPU burst time):
CPU utilization: 
Average waiting time (in CPU burst times): 
Average turnaround time (in CPU burst times): 
Average response time (in CPU burst times): 


## Result's summary and explanation




