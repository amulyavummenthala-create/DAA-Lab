//Sum of geometric series method 1
#include<stdio.h>
#include<math.h>
int a , r , n ;
Algo1_SumGeoSeries(int a, int r, int n)
{
    int sum = 0;
    return(a*pow(r,n)-1)/(r-1);
}
int main()
{
    printf("Enter the first term a: ");
    scanf("%d", &a);
    printf("Enter the common ratio r: ");
    scanf("%d", &r);
    printf("Enter the number of terms n: ");
    scanf("%d", &n);
    int sum = Algo1_SumGeoSeries(a, r, n);
    printf("The sum of the geometric series is: %d\n", sum);
    return 0;
} 