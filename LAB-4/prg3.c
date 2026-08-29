/*Given an array and a target value T, determine whether there are two elements whose sum is
equal to T. (Average Time Complexity should be O(n))*/
#include <stdio.h>

#define SIZE 100

int hashFunction(int key)
{
    if (key < 0)
        key = -key;

    return key % SIZE;
}

void insert(int hashTable[], int key)
{
    int index = hashFunction(key);

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

int search(int hashTable[], int key)
{
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
            return 1;

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    return 0;
}

int main()
{
    int arr[100];
    int hashTable[SIZE];
    int n, T;
    int i, required;
    int found = 0;
    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter target value T: ");
    scanf("%d", &T);

    for (i = 0; i < n; i++)
    {
        required = T - arr[i];

        if (search(hashTable, required))
        {
            printf("Pair found: %d + %d = %d\n",
                   required, arr[i], T);

            found = 1;
            break;
        }

        insert(hashTable, arr[i]);
    }

    if (found == 0)
    {
        printf("No pair found\n");
    }

    return 0;
}