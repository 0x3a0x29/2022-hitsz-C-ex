#include <stdio.h>
#include <math.h>
int main(void){
	float a,b,c,p,s;
	int i=0,j=0,k=0;
	scanf("%f%*c%f%*c%f",&a,&b,&c);
	p=(a+b+c)/2;
	if (a+b-c<1e-2||a+c-b<1e-2||b+c-a<1e-2||a<=1e-2||b<=1e-2||c<=1e-2)
	{
		printf("不是三角形\n");
		i=1;
	}else{
		if (fabs(a-b)<=1e-2&&fabs(a-c)<=1e-2&&fabs(b-c)<=1e-2)
		{
			printf("等边三角形");
		}else {if(fabs(a-b)<=1e-2||fabs(a-c)<=1e-2||fabs(b-c)<=1e-2)
		{
			j=1;
		}
		if (fabs(a*a+b*b-c*c)<=1e-2||fabs(a*a-b*b+c*c)<=1e-2||fabs(-a*a+b*b+c*c)<=1e-2)
		{
			k=1;
		}
		if (j*k==1){
			printf("等腰直角三角形");
		}else if(j==1){
			printf("等腰三角形");
		}else if(k==1){
			printf("直角三角形");
		}else {
			printf("一般三角形");
		}
        }
	}
	if (i==0){
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		printf("\nS=%.2f\n",s);
	}
	return 0;
}