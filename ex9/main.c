#include <stdio.h>
#include <string.h>
typedef struct user
{
    int ID,income,expenses;
    char name[11];
}USERS;
void Choice1(int length,int *plength,USERS users[]);
void Choice2(USERS users[],int length);
void Choice3(USERS users[],int length);
void Choice4(USERS users[],int length);
void Choice5(USERS users[],int length);
void Choice6(USERS users[],int length);
void Choice7(USERS users[],char *name_of_file,int length);
void Choice8(char *name_of_file,int length);
void Swap(int *a,int *b);
void UsersSwap(USERS users[],int i,int j);
int main()
{
    USERS users[10];
    int input=1,length=0;
        while (input!=0)
        {
            printf("1.Input record\n2.Sort and list records in reverse order by user name\n");
            printf("3.Search records by user name\n4.Calculate and list per capita income and expenses\n");
            printf("5.List records which have more expenses than per capita expenses\n6.List all records\n");
            printf("7.Write to a file\n8.Read from file\n0.Exit\n\tPlease enter your choice:");
            scanf("%d",&input);
            switch (input)
            {
            case 1:
                Choice1(length,&length,users);
                break;
            case 2:
                Choice2(users,length);
                break;
            case 3:
                Choice3(users,length);
                break;
            case 4:
                Choice4(users,length);
                break;
            case 5:
                Choice5(users,length);
                break;
            case 6:
                Choice6(users,length);
                break;
            case 7:
                Choice7(users,"C:\\Users\\DELL\\Desktop\\users information.txt",length);
                break;
            case 8:
                Choice8("C:\\Users\\DELL\\Desktop\\users information.txt",length);
                break;
            case 0:
                break;
            default:
                printf("please input the correct choice\n");
                break;
            }
            printf("\n");
        }
    return 0;
}
void Swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void UsersSwap(USERS users[],int i,int j)
{
    char name[11];
    strcpy(name,users[i].name);
    strcpy(users[i].name,users[j].name);
    strcpy(users[j].name,name);
    Swap(&users[i].ID,&users[j].ID);
    Swap(&users[i].income,&users[j].income);
    Swap(&users[i].expenses,&users[j].expenses);
}
void Choice1(int length,int *plength,USERS users[])
{
    int n,i;
    printf("Enter the number of users:");
    scanf("%d",&n);
     for (i=length;i<n+length;i++)
        scanf("%d %s %d %d",&users[i].ID,users[i].name,&users[i].income,&users[i].expenses);
    *plength+=n;
}
void Choice2(USERS users[],int length)
{
    int i,j;
    for (i=0;i<length;i++)
    {
        for (j=i;j<length;j++)
        {
            if (strcmp(users[i].name,users[j].name)<0)
            {
                UsersSwap(users,i,j);
            }
        }
    }
    printf("ID\tUserName\tIncome\tExpenses\n");
    for (i=0;i<length;i++)
    {
        printf("%d\t%s\t%d\t%d\n",users[i].ID,users[i].name,users[i].income,users[i].expenses);
    }
}
void Choice3(USERS users[],int length)
{
    char name[11];
    int i,error=1;
    printf("Please input the user name:");
    scanf("%s",name);
    for (i=0;i<length;i++)
    {
        if (strcmp(name,users[i].name)==0)
            error=0;
    }
    if (error==1)
        printf("Not Found\n");
    else
    {
    	printf("ID\tUserName\tIncome\tExpenses\n");
    	for (i=0;i<length;i++)
            if(strcmp(name,users[i].name)==0)
                printf("%d\t%s\t%d\t%d\n",users[i].ID,users[i].name,users[i].income,users[i].expenses);
	}
}
void Choice4(USERS users[],int length)
{
    int i,IncomeSum=0,ExpensesSum=0;
    for (i=0;i<length;i++)
    {
        IncomeSum+=users[i].income;
        ExpensesSum+=users[i].expenses;
    }
    printf("Per capita income: %f\n",(double)IncomeSum/length);
    printf("Per capita expenses: %f\n",(double)ExpensesSum/length);
}
void Choice5(USERS users[],int length)
{
    int i,ExpensesSum=0;
    double averge;
    for (i=0;i<length;i++)
    {
        ExpensesSum+=users[i].expenses;
    }
    averge=(double)ExpensesSum/length;
    printf("ID\tUserName\tIncome\tExpenses\n");
    for (i=0;i<length;i++)
    {
        if (users[i].expenses>averge)
            printf("%d\t%s\t%d\t%d\n",users[i].ID,users[i].name,users[i].income,users[i].expenses);
    }
}
void Choice6(USERS users[],int length)
{
    int i,j;
    for (i=0;i<length;i++)
    {
        for (j=i;j<length;j++)
        {
            if (users[i].ID>users[j].ID)
            {
                UsersSwap(users,i,j);
            }
        }
    }
    printf("ID\tUserName\tIncome\tExpenses\n");
    for (i=0;i<length;i++)
        printf("%d\t%s\t%d\t%d\n",users[i].ID,users[i].name,users[i].income,users[i].expenses);
}
void Choice7(USERS users[],char *name_of_file,int length)
{
    FILE *fp;
    int i;
    if((fp=fopen(name_of_file,"w"))==NULL)
        printf("Can not open the file!");
    else
    {
        for (i=0;i<length;i++)
            fprintf(fp,"%d\t%s\t%d\t%d\n",users[i].ID,users[i].name,users[i].income,users[i].expenses);
        printf("the information has been written already\n");
    }
    fclose(fp);
}
void Choice8(char *name_of_file,int length)
{
    USERS read;
    FILE *fp;
    int i;
    if ((fp=fopen(name_of_file,"r"))==NULL)
        printf("Can not open the file!");
    else
    {
        for (i=0;i<length;i++)
        {
            fscanf(fp,"%d\t%s\t%d\t%d\n",&read.ID,read.name,&read.income,&read.expenses);
            printf("%d\t%s\t%d\t%d\n",read.ID,read.name,read.income,read.expenses);
        }
        printf("the file has been read already\n");
    }
    fclose(fp);
}
