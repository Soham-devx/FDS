
#include <stdio.h>

int main()
{
    int allocation[3][3] = {{1,1,0}, {2,0,1}, {1,1,1}};
    int max[3][3] = {{2,2,1}, {3,1,2}, {2,2,2}};
    int available[3] = {2,1,1};
    int need[3][3], finish[3] = {0}, safe[3];
    int i, j, k = 0, flag;

    // Calculate Need
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    // Banker's Algorithm
    while(k < 3)
    {
        for(i = 0; i < 3; i++)
        {
            if(finish[i] == 0)
            {
                flag = 1;

                for(j = 0; j < 3; j++)
                    if(need[i][j] > available[j])
                        flag = 0;

                if(flag)
                {
                    safe[k++] = i;

                    for(j = 0; j < 3; j++)
                        available[j] += allocation[i][j];

                    finish[i] = 1;
                }
            }
        }
    }

    printf("Safe Sequence: ");
    for(i = 0; i < 3; i++)
        printf("P%d%s", safe[i], i < 2 ? " -> " : "\n");

    return 0;
}
