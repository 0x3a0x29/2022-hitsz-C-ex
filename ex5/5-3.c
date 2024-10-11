#include <stdio.h>
void Mean(int number[],int sum);
void Median(int number[],int sum);
void Mode(int number[]);
int main()
{
    int number[11],sum,i,input;
    scanf("%d",&sum);
    for (i=0;i<11;i++)
    {
        number[i]=0;
    }
    for (i=0;i<sum;i++)
    {
        scanf("%d",&input);
        number[input]++;
    }
    Mean(number,sum);
    Median(number,sum);
    Mode(number);
    return 0;
}
void Mean(int number[],int sum)
{
    int i;
    int result=0;
    for (i=0;i<11;i++)
    {
        result+=number[i]*i;
    }
    result/=sum;
    printf("Mean=%d\n",result);
}
void Median(int number[],int sum)
{
    int i,j,target=(sum+1)/2;
    int result;
    if (sum%2==1)
    {
        for (i=0;i<11;i++)
        {
            if (target>number[i])
            {
                target-=number[i];
            }
            else
            {
                printf("Median=%d\n",i);
                break;
            }
        }
    }
    else
    {
        for (i=0;i<11;i++)
        {
            if (target>number[i])
            {
                target-=number[i];
            }
            else if (target==number[i])
            {
                for (j=i+1;j<11;j++)
                {
                    if (number[j]!=0)
                    {
                        result=(i+j)/2;
                        break;
                    }
                }
                printf("Median=%d\n",result);
                break;
            }
            else
            {
                printf("Median=%d\n",i);
                break;
            }
        }
    }
}
void Mode(int number[])
{
    int i,max=0,result;
    for (i=0;i<11;i++)
    {
        if (number[i]>max)
        {
            max=number[i];
            result=i;
        }
    }
    printf("Mode=%d\n",result);
}