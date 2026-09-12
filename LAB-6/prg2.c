//Maximum Subarray using Divide and Conquer
#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int maxCrossingSum(int arr[], int low, int mid, int high)
{
    int sum = 0;
    int leftSum = -999999;
    int rightSum = -999999;
    int i;

    for (i = mid; i >= low; i--)
    {
        sum = sum + arr[i];

        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;

    for (i = mid + 1; i <= high; i++)
    {
        sum = sum + arr[i];

        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubarray(int arr[], int low, int high)
{
    int mid;
    int leftSum, rightSum, crossSum;

    if (low == high)
        return arr[low];

    mid = (low + high) / 2;

    leftSum = maxSubarray(arr, low, mid);
    rightSum = maxSubarray(arr, mid + 1, high);
    crossSum = maxCrossingSum(arr, low, mid, high);

    return max(leftSum, max(rightSum, crossSum));
}

int main()
{
    int arr[100], n;
    int i;
    int result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    result = maxSubarray(arr, 0, n - 1);

    printf("Maximum subarray sum = %d\n", result);

    return 0;
}