#include<stdio.h>
#include<limits.h>

/*
DYNAMIC PROGRAMMING
Created by: Kevin G. Fuentes
*/
int MatrixChainOrder(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;

    for (i=1; i<n; i++)
        m[i][i] = 0;

    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;

            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
}

int main()
{
//Sample Input.
    int n;

    printf("MATRIX CHAIN MULTIPLICATION ");
    printf("\n\nEnter number of Matrix: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter %d Values: ",n);
    int i;
    for(i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
        scanf("%d", &arr[i]);
    }
    printf("\nMinimum number of multiplications is %d. ", MatrixChainOrder(arr, n));
    getchar();
    return 0;
}
