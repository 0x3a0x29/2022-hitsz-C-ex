//实验8改错题,结构体动态申请内存
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int i,n;
	struct axy   //1
	{
		float x,y;
	};
    struct axy a;  //2
    scanf("%d",n); //3

    a=(struct axy*) malloc(n*sizeof(struct axy));

    for(i=0; i<n; i++)
        scanf("%f%f",&a[i].x,&a[i].y);

    for(i=1; i<=n; i++)
        if(sqrt(pow(a[i].x,2)+pow(a[i].y,2))<=5)
        {
            printf("%f",a[i].x);
            printf("%f\n",a+i->y);   //4
        }
    //5
    return 0;
}
