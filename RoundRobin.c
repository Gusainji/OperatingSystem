#include <stdio.h>

int main()
{
    int i, j, n, time, remain, flag = 0, quant;
    int WT = 0, TAT = 0, p[10], AT[10], BT[10], RT[10], CT[10];
    printf("Enter Total Process:\t ");
    scanf("%d", &n);
    remain = n;
    for (int i = 0; i < n; i++)
    {
        printf("Enter details for process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &AT[i]);
        printf("Burst Time: ");
        scanf("%d", &BT[i]);
        RT[i] = BT[i];
        p[i] = i + 1;
    }

    printf("Enter Time Quantum:\t");
    scanf("%d", &quant);
    printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");
    for (time = 0, i = 0; remain != 0;)
    {

        if (RT[i] <= quant && RT[i] > 0)
        {
            time += RT[i];
            RT[i] = 0;
            flag = 1;
        }
        else if (RT[i] > 0)
        {
            RT[i] -= quant;
            time += quant;
        }
        if (RT[i] == 0 && flag == 1)
        {
            remain--;
            CT[i] = time;
            printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, AT[i], BT[i], CT[i], time - AT[i] - BT[i], time - AT[i]);
            WT += time - AT[i] - BT[i];
            TAT += time - AT[i];
            flag = 0;
        }
        if (i == n - 1)
            i = 0;
        else if (AT[i + 1] <= time)
            i++;
        else
            i = 0;
    }

    printf("Average Waiting Time= %f\n", WT * 1.0 / n);
    printf("Avg Turnaround Time = %f", TAT * 1.0 / n);

    return 0;
}
