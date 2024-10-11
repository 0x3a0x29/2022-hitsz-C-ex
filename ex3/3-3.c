#include <stdio.h>
#include <math.h>
int main(){
	int hour,minute;
	float result;
	printf("Please input time");
	while (1){
		scanf("%dh%dm",&hour,&minute);
		if (hour>=0&&hour<=12&&minute>=0&&minute<60)
		{
			break;
		}
	}
	result=fabs((hour+minute/60.0)/12.0-minute/60.0)*360;
	while (result>=180)
	{
		result-=180;
	}
	printf("\nAt %d:%02d the angle is %.1f degrees.\n",hour,minute,result);
	return 0;
}
