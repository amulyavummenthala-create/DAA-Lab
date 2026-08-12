//binary search using recursion 
#include <stdio.h>
int binarySearch(int A[], int beg, int end, int key)
{
    int mid;

    if (beg <= end)
    {
        mid = (beg + end) / 2;

        if (key == A[mid])
        {
            return mid;
        }
        else if (key < A[mid])
        {
            return binarySearch(A, beg, mid - 1, key);
        }
        else
        {
            return binarySearch(A, mid + 1, end, key);
        }
    }

    return -1;
}

int main()
{
    int A[100];
    int n, i, key, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements in sorted order:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = binarySearch(A, 0, n - 1, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}