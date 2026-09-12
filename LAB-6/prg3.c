//Strassen's Matrix Multiplication
#include <stdio.h>
#define MAX 100

void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void subtractMatrix(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
void strassen(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n)
{
    int i, j;
    int mid;

    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    mid = n / 2;

    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], M4[MAX][MAX];
    int M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];
    int X[MAX][MAX], Y[MAX][MAX];
    int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];
    for (i = 0; i < mid; i++)
    {
        for (j = 0; j < mid; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }
    addMatrix(A11, A22, X, mid);
    addMatrix(B11, B22, Y, mid);
    strassen(X, Y, M1, mid);
    addMatrix(A21, A22, X, mid);
    strassen(X, B11, M2, mid);
    subtractMatrix(B12, B22, Y, mid);
    strassen(A11, Y, M3, mid);
    subtractMatrix(B21, B11, Y, mid);
    strassen(A22, Y, M4, mid);
    addMatrix(A11, A12, X, mid);
    strassen(X, B22, M5, mid);
    subtractMatrix(A21, A11, X, mid);
    addMatrix(B11, B12, Y, mid);
    strassen(X, Y, M6, mid);

    subtractMatrix(A12, A22, X, mid);
    addMatrix(B21, B22, Y, mid);
    strassen(X, Y, M7, mid);

    addMatrix(M1, M4, X, mid);
    subtractMatrix(X, M5, Y, mid);
    addMatrix(Y, M7, C11, mid);

    addMatrix(M3, M5, C12, mid);

    addMatrix(M2, M4, C21, mid);

    subtractMatrix(M1, M2, X, mid);
    addMatrix(X, M3, Y, mid);
    addMatrix(Y, M6, C22, mid);

    for (i = 0; i < mid; i++)
    {
        for (j = 0; j < mid; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
}

int main()
{
    int A[MAX][MAX] = {0};
    int B[MAX][MAX] = {0};
    int C[MAX][MAX] = {0};
    int n, size;
    int i, j;

    printf("Enter size of matrix: ");
    scanf("%d", &n);

    size = 1;

    while (size < n)
        size = size * 2;

    printf("Enter elements of first matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(A, B, C, size);

    printf("Resultant matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", C[i][j]);
        }

        printf("\n");
    }

    return 0;
}