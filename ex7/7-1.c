#include <stdio.h>
int main()
{
    int m,n,i,j;
    scanf("%d %d",&m,&n);
    int marix[m][n];
    int marixT[n][m];
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d",&marix[i][j]);
        }
    }
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            marixT[j][i]=marix[i][j];
        }
    }
    for (j=0;j<n;j++)
    {
        for (i=0;i<m;i++)
            {
                printf("%d ",marixT[j][i]);
            }
            printf("\n");
    }
    return 0;
}