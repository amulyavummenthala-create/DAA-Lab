//frequency in an array
#include <stdio.h>
#define SIZE 100

int hashFunction(int key)
{
    if (key < 0)
        key = -key;

    return key % SIZE;
}

void insert(int hashTable[], int frequency[], int key)
{
    int index = hashFunction(key);

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            frequency[index]++;
            return;
        }

        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
    frequency[index] = 1;
}

void display(int hashTable[], int frequency[])
{
    int i;

    printf("\nFrequency of every distinct element:\n");

    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] != -1)
        {
            printf("%d : %d\n",
                   hashTable[i],
                   frequency[i]);
        }
    }
}

int main()
{
    int arr[100];
    int hashTable[SIZE];
    int frequency[SIZE];
    int n;
    int i;

    // Initialize hash table
    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
        frequency[i] = 0;
    }

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Find frequency using hashing
    for (i = 0; i < n; i++)
    {
        insert(hashTable, frequency, arr[i]);
    }

    display(hashTable, frequency);

    return 0;
}