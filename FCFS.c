#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, req, size, sum = 0, head;

    printf("\nEnter the size of Disk\n");
    scanf("%d", &size);
    printf("Enter Total number of requests\n");
    scanf("%d", &req);
    printf("Enter the requests\n");

    int a[req];
    for (i = 0; i < req; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < req; i++)
    {
        if (a[i] > size)
        {
            printf("Error, Unknown position %d\n", a[i]);
            return 0;
        }
    }
    printf("Enter Initial head position\n");
    scanf("%d", &head);
    printf("\n");
    int temp = head;
    for (i = 0; i < req; i++)
    {
        int diff = abs(a[i] - temp);
        printf("Disk head moves from %d to %d with seek %d\n", temp, a[i], diff);
        sum += diff;
        temp = a[i];
    }
    printf("\n");
    printf("Total Seek time: %d\n", sum);
    double avg_time = sum / (double)req;
    printf("Average Seek time for head movements: %f\n", avg_time);

    return 0;
}
