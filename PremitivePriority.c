#include <stdio.h> 
 
void swap(int *a, int *b) {   
    int temp = *a;   *a = *b; 
  *b = temp; 
} 
 
int main() { 
  int n; 
  printf("Enter Number of Processes: "); 
    scanf("%d", &n); 
 
  int BT[n], prior[n], AT[n], p[n];  
   for (int i = 0; i < n; i++) { 
        printf("Enter details for process %d:\n", i + 1);       
          printf("Arrival Time: ");       
  scanf("%d", &AT[i]);        
 printf("Burst Time: ");         
scanf("%d", &BT[i]);        
 printf("Priority: ");        
 scanf("%d", &prior[i]); 
        p[i] = i + 1; 
    } 
 
  // Sort the processes by priority and arrival time  
   for (int i = 0; i < n; i++) {     int x = i; 
 
    for (int j = i; j < n; j++) { 
              if (prior[j] > prior[x] || (prior[j] == prior[x] && AT[j] < AT[x])) {        
                 x = j; 
      } 
    } 
    swap(&prior[i], &prior[x]);  
       swap(&AT[i], &AT[x]);     
swap(&BT[i], &BT[x]); 
    swap(&p[i], &p[x]); 
  } 
 
  int t = AT[0]; // Initialize time to the arrival time of the first process  
   for (int i = 0; i < n; i++) { 
        t += BT[i]; 
  } 
 
  printf("\nP\tAT\tBT\tPrior\tCT\tTAT\tWT\n"); 
  int totalTAT = 0; 
  int totalWT = 0; 
  for (int i = 0; i < n; i++) { 
    int CT = t; // Completion Time is the current time    
     int TAT = CT - AT[i];     
 totalTAT += TAT;   
  int WT = TAT - BT[i];  
    totalWT += WT; 
 
    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i], AT[i], BT[i], prior[i], CT, TAT, WT); 
    // Update time 
    t += BT[i]; 
  } 
 
  float avgTAT = (float)totalTAT / n; 
  float avgWT = (float)totalWT / n; 
 
  printf("\nAverage Turnaround Time is %.2f\n", avgTAT);  
   printf("Average Waiting Time is %.2f\n", avgWT); 
 
  return 0; 
} 

