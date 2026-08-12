//summation of geometric series different approach , method 2
#include<stdio.h>
int a ,r , n;
Algo2_SumGeoSeries(a,r,n)
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum=sum+a;
        a=a*r;
    }
    return sum;
}
int main()
{
    printf("Enter the first term (a): ");
    scanf("%d", &a);
    printf("Enter the common ratio (r): ");
    scanf("%d", &r);
    printf("Enter the number of terms (n): ");
    scanf("%d", &n);
    int sum = Algo2_SumGeoSeries(a, r, n);
    printf("The sum of the geometric series is: %d\n", sum);
    return 0;
} 