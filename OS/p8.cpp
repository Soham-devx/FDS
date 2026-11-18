
#include <stdio.h>

int main()
{
    int pages[] = {1, 2, 3, 1, 4, 5};
    int n = 6, capacity = 3;
    int frames[3], time[3], i, j, k, pos, faults, found;

    // FIFO Algorithm
    faults = 0;
    pos = 0;

    for(i = 0; i < capacity; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < capacity; j++)
            if(frames[j] == pages[i])
                found = 1;

        if(!found)
        {
            frames[pos] = pages[i];
            pos = (pos + 1) % capacity;
            faults++;
        }
    }

    printf("FIFO Page Faults = %d\n", faults);

    // LRU Algorithm
    faults = 0;

    for(i = 0; i < capacity; i++)
        frames[i] = -1, time[i] = 0;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < capacity; j++)
            if(frames[j] == pages[i])
                found = 1, time[j] = i;

        if(!found)
        {
            pos = 0;

            for(j = 0; j < capacity; j++)
                if(frames[j] == -1)
                {
                    pos = j;
                    break;
                }

            if(frames[pos] != -1)
                for(j = 1; j < capacity; j++)
                    if(time[j] < time[pos])
                        pos = j;

            frames[pos] = pages[i];
            time[pos] = i;
            faults++;
        }
    }

    printf("LRU Page Faults = %d\n", faults);

    // Optimal Algorithm
    faults = 0;

    for(i = 0; i < capacity; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < capacity; j++)
            if(frames[j] == pages[i])
                found = 1;

        if(!found)
        {
            pos = -1;
            int farthest = -1;

            for(j = 0; j < capacity; j++)
            {
                if(frames[j] == -1)
                {
                    pos = j;
                    break;
                }

                for(k = i + 1; k < n; k++)
                    if(pages[k] == frames[j])
                        break;

                if(k > farthest)
                    farthest = k, pos = j;
            }

            frames[pos] = pages[i];
            faults++;
        }
    }

    printf("Optimal Page Faults = %d\n", faults);

    return 0;
}
