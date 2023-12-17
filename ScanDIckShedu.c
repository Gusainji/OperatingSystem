#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX_REQUESTS 100 
 
void scanDiskScheduling(int requests[], int n, int initial, int diskSize) 
{     
    int totalSeekTime = 0; 
    int currentHeadPosition = initial; 
 
    for (int i = 0; i < n - 1; i++) {         
        for (int j = 0; j < n - i - 1; j++) {             
            if (requests[j] > requests[j + 1]) { 
                // Swap the requests                 
                int temp = requests[j];                 
                requests[j] = requests[j + 1]; 
                requests[j + 1] = temp; 
            } 
        } 
    } 
    int currentHeadIndex = 0;     
    for (int i = 0; i < n; i++) { 
        if (requests[i] >= currentHeadPosition) {             
            currentHeadIndex = i; 
            break; 
        } 
    } 
// Move towards the end
for (int i = currentHeadIndex; i < n; i++)
{
    printf("Disk head Moves from %d to %d\n", currentHeadPosition, requests[i]);
    totalSeekTime += abs(requests[i] - currentHeadPosition);
    currentHeadPosition = requests[i];
}
// Move towards the beginning
for (int i = currentHeadIndex - 1; i >= 0; i--)
{
    printf("Disk head Moves from %d to %d\n", currentHeadPosition, requests[i]);
    totalSeekTime += abs(requests[i] - currentHeadPosition);
    currentHeadPosition = requests[i];
}
printf("\nTotal Seek Time: %d\n", totalSeekTime);
float avgSeekTime = (float)totalSeekTime / n;
printf("\nAverage Seek Time: %.2f\n\n", avgSeekTime);
}

int main()
{
    int requests[MAX_REQUESTS];
    int n, initial, diskSize;

    printf("\nEnter the size of the disk: ");
    scanf("%d", &diskSize);
    printf("\nEnter the number of disk requests: ");
    scanf("%d", &n);
    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &requests[i]);
    }
    printf("Enter Initial head position: ");
    scanf("%d", &initial);
    for (int i = 0; i < n; i++)
    {
        if (requests[i] < 0 || requests[i] >= diskSize)
        {
            printf("Error: Disk request %d is out of range.\n", requests[i]);
            return 1; // Exit with an error code
        }
    }
    scanDiskScheduling(requests, n, initial, diskSize);
    return 0;
}
