#include <iostream> 
#include <fstream>
#include <mutex>
#include <thread>
#include <chrono> // Fixed typo here
#include <string>
#include <queue>
#include "fifo.h"
#include "sjf.h"
#include "priority.h"


using namespace std;
/*
int numProducers;
int numConsumers;
int sleepTime;

struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    int startTime;
    int endTime;
    int remainingTime;
};
*/

int main()
{
    queue<Process> processes;
    ifstream inputFile("Datafile1-txt.txt");
    //ifstream inputFile("Datafile1-txt.t" && "Datafile1-txt.xlsx");

    if (!inputFile){
        cerr<< "Error: Input file not found!!!";
        return 1;
    }
    else if(inputFile){
        string header;
        getline(inputFile, header);

        Process process;
        int id = 1;
        while(inputFile >> process.arrivalTime >> process.burstTime >> process.priority){
            process.id = id;
            processes.push(process);
            id ++;
        }
    }
    inputFile.close();

    fifo data1(processes);
    cout << "FIFO list:"<<endl;
    data1.run();
    data1.Calculation();

    sjf data2(processes);
    cout << "SJF list:"<<endl;
    data2.run();
    data2.Calculation();

    priority data3(processes);
    cout << "Priority list:"<<endl;
    data3.run();
    data3.Calculation();

    


}

