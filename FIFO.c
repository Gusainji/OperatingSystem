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
    for (i = 0; i < frames; i++)
    {
        temp[i] = -1;
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
            }
        }

        pageFaults++;   

        if ((pageFaults <= frames) && (p == 0))
        {
            temp[i] = referenceString[i];
        }
        else if (p == 0)
        {
            temp[(pageFaults - 1) % frames] = referenceString[i];
        }
        printf("\n");
        for (j = 0; j < frames; j++)
        {
            printf("%d\t", temp[j]);
        }
    }

    printf("\n\nTotal Page Faults:\t%d", pageFaults);

    hitR = (float)(pages - pageFaults) / pages * 100.0;
    printf("\nHit Ratio:\t%.2f%%\n", hitR);

    missR = 100.0 - hitR;
    printf("\nMiss Ratio:\t%.2f%%\n", missR);

    return 0;
}
