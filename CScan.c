#include <stdio.h>
#include <stdlib.h>

void cscanDiskScheduling(int requests[], int n, int initialPosition, int diskSize)
{
    int totalSeekTime = 0;
    int currentHeadPosition = initialPosition;

    // Sort the requests in ascending order
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (requests[j] > requests[j + 1])
            {
                // Swap the requests
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    // Move towards the end
    for (int i = 0; i < n; i++)
    {
        if (requests[i] >= currentHeadPosition)
        {
            printf("Move from %d to %d\n", currentHeadPosition, requests[i]);
            totalSeekTime += abs(requests[i] - currentHeadPosition);
            currentHeadPosition = requests[i];
        }
    }

    // Move to the beginning (start of the disk)
    printf("Move from %d to 0\n", currentHeadPosition);
    totalSeekTime += abs(currentHeadPosition); // Head moves to track 0
    currentHeadPosition = 0;

    // Move towards the end again
    for (int i = 0; i < n; i++)
    {
        if (requests[i] < currentHeadPosition)
        {
            printf("Move from %d to %d\n", currentHeadPosition, requests[i]);
            totalSeekTime += abs(requests[i] - currentHeadPosition);
            currentHeadPosition = requests[i];
        }
    }

    printf("Total Seek Time: %d\n", totalSeekTime);

    // Calculate average seek time
    float avgSeekTime = (float)totalSeekTime / n;
    printf("Average Seek Time: %.2f\n", avgSeekTime);
}

int main()
{
    int requests[100];
    int n, initialPosition, diskSize;

    // Input the number of requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    // Input the disk requests
    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }

    // Input the initial head position
    printf("Enter the initial head position: ");
    scanf("%d", &initialPosition);

    // Input the size of the disk
    printf("Enter the size of the disk: ");
    scanf("%d", &diskSize);

    // Validate that disk requests are within the valid range
    for (int i = 0; i < n; i++)
    {
        if (requests[i] < 0 || requests[i] >= diskSize)
        {
            printf("Error: Disk request %d is out of range.\n", requests[i]);
            return 1; // Exit with an error code
        }
    }

    // Perform C-SCAN disk scheduling
    cscanDiskScheduling(requests, n, initialPosition, diskSize);

    return 0;
}
