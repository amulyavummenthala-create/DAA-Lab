//sorting an array using bucket sort
#include <stdio.h>

int main()
{
    int arr[100];
    int bucket[10][100];
    int count[10] = {0};

    int n, i, j, k;
    int bucketIndex;
    int temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements (0 to 99):\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] >= 0 && arr[i] <= 9)
            bucketIndex = 0;
        else if (arr[i] >= 10 && arr[i] <= 19)
            bucketIndex = 1;
        else if (arr[i] >= 20 && arr[i] <= 29)
            bucketIndex = 2;
        else if (arr[i] >= 30 && arr[i] <= 39)
            bucketIndex = 3;
        else if (arr[i] >= 40 && arr[i] <= 49)
            bucketIndex = 4;
        else if (arr[i] >= 50 && arr[i] <= 59)
            bucketIndex = 5;
        else if (arr[i] >= 60 && arr[i] <= 69)
            bucketIndex = 6;
        else if (arr[i] >= 70 && arr[i] <= 79)
            bucketIndex = 7;
        else if (arr[i] >= 80 && arr[i] <= 89)
            bucketIndex = 8;
        else
            bucketIndex = 9;
        bucket[bucketIndex][count[bucketIndex]] = arr[i];
        count[bucketIndex]++;
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < count[i] - 1; j++)
        {
            for (k = 0; k < count[i] - j - 1; k++)
            {
                if (bucket[i][k] > bucket[i][k + 1])
                {
                    temp = bucket[i][k];
                    bucket[i][k] = bucket[i][k + 1];
                    bucket[i][k + 1] = temp;
                }
            }
        }
    }
    k = 0;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < count[i]; j++)
        {
            arr[k] = bucket[i][j];
            k++;
        }
    }
    printf("Sorted array:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}