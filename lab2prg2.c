#include <stdio.h>

void merge(int a[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = 0;
    int temp[100];
    while (i <= mid && j <= ub)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= ub)
    {
        temp[k] = a[j];
        j++;
        k++;
    }
    for (i = lb, k = 0; i <= ub; i++, k++)
    {
        a[i] = temp[k];
    }
}
void mergeSort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int main()
{
    int a[100], n, k;
    int i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter k: ");
    scanf("%d", &k);
    mergeSort(a, 0, n - 1);
    printf("Kth smallest element = %d\n", a[k - 1]);
    return 0;
}