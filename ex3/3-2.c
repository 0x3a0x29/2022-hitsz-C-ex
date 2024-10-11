#include <stdio.h>
int main(){
	int y,m,d,r=0;
	printf("请输入日期（年，月，日）\n");
	scanf("%d%*c%d%*c%d",&y,&m,&d);
	switch(m)
	{
		case 12:
			r+=30;
		case 11:
			r+=31;
		case 10:
			r+=30;
		case 9:
			r+=31;
		case 8:
			r+=31;
		case 7:
			r+=30;
		case 6:
			r+=31;
		case 5:
			r+=30;
		case 4:
			r+=31;
		case 3:
			r+=28;
		case 2:
			r+=31;
			if (y%4==0&&y%100!=0||y%400==0){
				r++;
			}
		case 1:
			r+=d;
			break;
		default:
			r=-1;
	}
	if (r!=-1)
	{
		printf("\n%d月%d日是%d年的第%d天。",m,d,y,r);
	}
	return 0;
}