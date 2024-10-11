#include <stdio.h>
int main()
{
    int n,i,j,k,swap;
    scanf("%d",&n);
    int r=n;
    int a[n],b[n];
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=0;
    }
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (a[i]>a[j])
            {
                swap=a[i];
                a[i]=a[j];
                a[j]=swap;
            }
        }
    }
    for (i=0;i<n;i++)
    {
        if (a[i]==a[i+1])
        {
            r--;
        }
        else
        {
            b[i]=a[i];
        }
    }
    printf("%d\n",r);
    for (i=0;i<n;i++)
    {
        if (b[i]!=0)
        printf("%d ",b[i]);
    }
    return 0;
}
