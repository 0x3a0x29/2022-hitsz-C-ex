#include <stdio.h>
int main()
{
    int n,i,MT1=0,EN1=0,PH1=0;
    float MT2,EN2,PH2;
    struct student
    {
        char ID[12];
        int MT;
        int EN;
        int PH;
        int SUM;
        float AVER;
    };
    struct student stu[40];
    printf("Input the total number of the students(n<40):\n");
    scanf("%d",&n);
    printf("Input student’s ID and score as: MT  EN  PH:\n");
    for (i=0;i<n;i++)
    {
        scanf("%s %d %d %d",&stu[i].ID,&stu[i].MT,&stu[i].EN,&stu[i].PH);
    }
    for (i=0;i<n;i++)
    {
        stu[i].SUM=stu[i].MT+stu[i].EN+stu[i].PH;
        stu[i].AVER=stu[i].SUM/3.0;
        MT1+=stu[i].MT;
        EN1+=stu[i].EN;
        PH1+=stu[i].PH;
    }
    MT2=MT1/(float)n;
    EN2=EN1/(float)n;
    PH2=PH1/(float)n;
    printf("Counting Result:\nStudent’s ID\t  MT \t  EN \t  PH \t SUM \t AVER\n");
    for (i=0;i<n;i++)
    {
        printf("%12s\t%4d\t%4d\t%4d\t%4d\t%5.1f\n",stu[i].ID,stu[i].MT,stu[i].EN,stu[i].PH,stu[i].SUM,stu[i].AVER);
    }
    printf("SumofCourse \t%4d\t%4d\t%4d\t",MT1,EN1,PH1);
    printf("\nAverofCourse\t%4.1f\t%4.1f\t%4.1f\t",MT2,EN2,PH2);
    return 0;
}