#include <stdio.h>
#include <ctype.h>
int main()
{
    char input[100];
    int i,j;
    int num;
    for (i=0;i<100;i++)
        input[i]='\0';
    scanf("%s",input);
    for (i=0;i<100;i++)
    {
        if (isdigit(input[i]))
        {
            num=input[i]-'0';
            for (j=i+1;j<100;j++)
            {
                if (isdigit(input[j]))
                {
                    num*=10;
                    num+=input[j]-'0';
                }
                else
                {
                    i=j;
                    printf("%10d\n",num);
                    break;
                }
            }
        }
    }
    return 0;
}