#include <stdio.h>
int a(int n);
int main(){
	int input1,i;
	scanf("%d",&input1);
	int x[input1];
	for (i=0;i<input1;i++)
	{
		scanf("%d",&x[i]);
	}
	for (i=0;i<input1;i++)
	{
		printf("%d\n",a(x[i])%32767);
	}
	return 0;
}
int a(int n)
{
	if (n>2)
	{
		return a(n-1)*2+a(n-2);
	}
	else if(n==2)
	{
		return 2;
	}
	else if (n==1)
	{
		return 1;
	}
}
