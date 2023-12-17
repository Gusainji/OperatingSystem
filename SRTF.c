#include <stdio.h>
#include <stdlib.h>

#include <limits.h>  
#define MAX_PROCESSES 10

struct Process {
    int processId;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
};

int main() {
    int n;  // Number of processes
    struct Process processes[MAX_PROCESSES];
    int completedProcesses = 0;
    int currentTime = 0;
    int shortestProcess;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter details for Process %d:\n", i + 1);
        processes[i].processId = i + 1;
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
    }

    while (completedProcesses < n) {
        shortestProcess = -1;
        int shortestTime = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime < shortestTime && processes[i].remainingTime > 0) {
                shortestProcess = i;
                shortestTime = processes[i].remainingTime;
            }
        }

        if (shortestProcess == -1) {
            currentTime++;
        } else {
            processes[shortestProcess].remainingTime--;
            if (processes[shortestProcess].remainingTime == 0) {
                completedProcesses++;
                processes[shortestProcess].turnaroundTime = currentTime - processes[shortestProcess].arrivalTime + 1;
            }
            currentTime++;
        }
    }

    // Calculate waiting times
    for (int i = 0; i < n; i++) {
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
    }

    // Calculate average waiting and turnaround times
    double avgWaitingTime = 0;
    double avgTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }

    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    // Display the results
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].processId, processes[i].arrivalTime, processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }

    printf("\nAverage Waiting Time: %.2lf\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnaroundTime);

    return 0;
}
