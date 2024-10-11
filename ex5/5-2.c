#include <stdio.h>
int main()
{
    int n1=123,n2=246,n3=369,rem,i,j,t[9],r;
    while (n1<=333)
    {
    	r=0;
    	rem=n1;
    	for (i=0;i<3;i++)
    	{
    		t[i]=rem%10;
    		rem/=10;
		}
		rem=n2;
		for (i=3;i<6;i++)
		{
			t[i]=rem%10;
			rem/=10;
		}
		rem=n3;
		for (i=6;i<9;i++)
		{
			t[i]=rem%10;
			rem/=10;
		}
		for (i=0;i<9;i++)
		{
			for (j=i+1;j<9;j++)
			{
				if (t[i]==t[j]||t[j]==0)
				{
					r=1;
					break;
				}
			}
			if (r==1)
				break;
		}
		if (r==0)
			printf("%d,%d,%d\n",n1,n2,n3);
    	n1++;
    	n2+=2;
    	n3+=3;
	}
    return 0;
}