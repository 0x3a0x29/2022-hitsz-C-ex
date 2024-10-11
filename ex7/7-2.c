#include <stdio.h>
#include <string.h>
int main()
{
    char c1[51],c2[51];
    int n1[50],n2[50],n[51],i;
    for (i=0;i<51;i++)
        c1[i]=c2[i]='\0';
    for (i=0;i<50;i++)
    {
        n[i]=n1[i]=n2[i]=0;
    }
    n[50]=0;
    scanf("%s",c1);
    scanf("%s",c2);
    for (i=0;i<strlen(c1);i++)
    {
        if (c1[i]!='\0')
            n1[50-strlen(c1)+i]=c1[i]-'0';
        else
            break;
    }
    for (i=0;i<strlen(c2);i++)
    {
        if (c2[i]!='\0')
            n2[50-strlen(c2)+i]=c2[i]-'0';
        else
            break;
    }
    for (i=49;i>=0;i--)
    {
        n[i+1]+=n1[i]+n2[i];
        if (n[i+1]>9)
        {
            n[i+1]-=10;
            n[i]++;
        }
    }
    for(i=0;i<51;i++)
    {
        if (n[i]!=0)
            break;
    }
    while(i<51)
    {
        printf("%d",n[i]);
        i++;
    }
    return 0;
}