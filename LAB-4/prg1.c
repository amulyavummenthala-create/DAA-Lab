//hash table using linear probing
#include<stdio.h>
#define size 11
int hashfunction(int key)
{
    return key%size;
}
void insert (int hashtable[],int key)
{
    int index=hashfunction(key);
    int original_index=index;
    while (hashtable[index]!=-1)
    {
        index=index +1%size;
    
    if( index==original_index)
    printf("hashtable is full");
    }
    hashtable[index]=key;
}
void display(int hashtable[])
{
    printf("hashtable ");
    for (int i =0;i<size;i++)
    {
    if (hashtable[i] == -1)
            printf("Index %d : Empty\n", i);
        else
            printf("Index %d : %d\n", i, hashtable[i]);
    }
    }
int main()
{
    int hashtable[size];
    int n, key;
    int i;
    for (i = 0; i < size; i++)
    {
        hashtable[i] = -1;
    }

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(hashtable, key);
    }

    display(hashtable);

    return 0;
}