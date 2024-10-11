#include <stdio.h>
int leap(int year);
int main(){
	int year,month,i,sum=0,day,start;
	scanf("%d %d",&year,&month);
	for (i=1900;i<year;i++)
	{
		sum+=365;
		if (leap(i))
		{
			sum++;
		}
	}
	switch (month)
	{
		case 1:
			day=31;
			break;
		case 2:
			day=28;
			sum+=31;
			if (leap(year))
			{
				day++;
			}
			break;
		case 3:
			sum+=59;
			day=31;
			break;
		case 4:
			sum+=90;
			day=30;
			break;
		case 5:
			sum+=120;
			day=31;
			break;
		case 6:
			sum+=151;
			day=30;
			break;
		case 7:
			sum+=181;
			day=31;
			break;
		case 8:
			sum+=212;
			day=31;
			break;
		case 9:
			sum+=243;
			day=30;
			break;
		case 10:
			sum+=273;
			day=31;
			break;
		case 11:
			sum+=304;
			day=30;
			break;
		case 12:
			sum+=334;
			day=31;
			break;
	}
	if (leap(year)&&month>2)
	{
		sum++;
	}
	printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
	start=(sum+1)%7;
	for (i=0;i<start;i++)
	{
		printf("\t");
	}
	for (i=1;i<=day;i++,start++)
	{
		if (start==6)
		{
			printf("%d\t\n",i);
			start=-1;
		}
		else
		{
			printf("%d\t",i);	
		}
	}
	return 0;
}
int leap(int year)
{
	if (year%4==0&&year%100!=0||year%400==0)
		return 1;
	else
		return 0;
}
