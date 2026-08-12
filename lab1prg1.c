//Linear search 
#include <stdio.h>
int linearSearch(int arr[], int n, int target)
{   int current;
    for (current = 0; current < n; current++)
    {if (arr[current] == target)
        {
            return current;
        }
    }
    return -1;
}
int main()
{
    int arr[100], n, target, current, index;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (current = 0; current < n; current++)
    {
        scanf("%d", &arr[current]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &target);
    index = linearSearch(arr, n, target);
    if (index != -1)
        printf("Element found at position %d\n", index + 1);
    else
        printf("Element not found\n");
    return 0;
}