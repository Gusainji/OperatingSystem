#include <stdio.h>

int main()
{
    int referenceString[10], pageFaults = 0, i, j, p, pages, frames;
    float hitR = 0.0, missR = 0.0;

    printf("\nEnter the number of Pages:\t");
    scanf("%d", &pages);

    printf("\nEnter reference string values:\t");
    for (i = 0; i < pages; i++)
    {
        scanf("%d", &referenceString[i]);
    }

    printf("\nEnter the Total number of frames:\t");
    scanf("%d", &frames);

    int temp[frames];
    int counter[frames]; // To keep track of when each frame was last used
    for (i = 0; i < frames; i++)
    {
        temp[i] = -1;
        counter[i] = 0;
    }
    for (i = 0; i < pages; i++)
    {
        p = 0;
        for (j = 0; j < frames; j++)
        {
            if (referenceString[i] == temp[j])
            {
                p++;
                pageFaults--;

                counter[j] = 0;
            }
            else
            {
                counter[j]++;
            }
        }

        pageFaults++;

        if ((pageFaults <= frames) && (p == 0))
        {
            temp[i] = referenceString[i];
        }
        else if (p == 0)
        {
            // Find the frame with the maximum counter value (least recently used)
            int maxCounterIndex = 0;
            for (j = 1; j < frames; j++)
            {
                if (counter[j] > counter[maxCounterIndex])
                {
                    maxCounterIndex = j;
                }
            }

            temp[maxCounterIndex] = referenceString[i];
            counter[maxCounterIndex] = 0; // Reset the counter for the used page
        }
        for (j = 0; j < frames; j++)
        {
            printf("%d\t", temp[j]);
        }

        printf("\n"); // Print a new line after each set of frames
    }
    printf("\nTotal Page Faults:\t%d\n", pageFaults);

    hitR = (float)(pages - pageFaults) / pages * 100.0;
    printf("\nHit Ratio:\t%.2f%%", hitR);

    missR = 100.0 - hitR;
    printf("\nMiss Ratio:\t%.2f%%\n\n", missR);

    return 0;
}
