#include <stdio.h>
int main(void){
	int a,b,c,d;
    float r;
	scanf("%d%*c%d%*c%d%*c%d",&a,&b,&c,&d);
	if (a>0&&b>0&&c>0&&d>0){
		r=(float)a/b-(float)c/d;
		if (r>0){
			printf("%d/%d > %d/%d",a,b,c,d);
		}else if(r<0){
			printf("%d/%d < %d/%d",a,b,c,d);
		}else {
			printf("%d/%d = %d/%d",a,b,c,d);
		}
	}
	return 0;
}