//quadratic probing in hash table
#include <stdio.h>

#define SIZE 10

int hashFunction(int key)
{
    return key % SIZE;
}

void insert(int hashTable[], int key)
{
    int index;
    int i;

    for (i = 0; i < SIZE; i++)
    {
        index = (hashFunction(key) + i * i) % SIZE;

        if (hashTable[index] == -1)
        {
            hashTable[index] = key;
            return;
        }
    }

    printf("Could not insert %d. Hash table is full or no suitable position found.\n", key);
}

void display(int hashTable[])
{
    int i;

    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("Index %d : Empty\n", i);
        else
            printf("Index %d : %d\n", i, hashTable[i]);
    }
}

int main()
{
    int hashTable[SIZE];
    int n, key;
    int i;
    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(hashTable, key);
    }

    display(hashTable);

    return 0;
}