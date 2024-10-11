#include <stdio.h>
int main(){
	const int M;
	int N,i,j,k,l,input,r;
	scanf("%d",&M);
	if (M>0&&M<10)
	{
		for (i=0;i<M;i++)
		{
            r=0;
			scanf("%d",&N);
			for (j=0;j<N&&N>0&&N<1000;j++)
			{
				scanf("%d",&input);
				if (input<1000){
					l=0;
					for (k=2;k<input;k++)
					{
						if (input%k==0)
						{
							l=1;
						}
					}
					if (l==0&&input>1)
					{
						r+=input;
					}
				}
			}
            printf("%d\n",r);
		}
	}
	return 0;
}
