#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int min(int x,int y,int z);
int distance(int i,int j,char w[],char v[]);
int main()
{
    FILE *Vp=fopen("C:\\Users\\DELL\\Desktop\\vocabulary.txt","r");
    FILE *Wp=fopen("C:\\Users\\DELL\\Desktop\\words.txt","r");
    FILE *Cp=fopen("C:\\Users\\DELL\\Desktop\\words_correct.txt","w");
    char word[20]="";
    char voca[20]="";
    char corr[20]="";
    char ch,vh;
    int i,j,max,op,num=1;
    while((ch=fgetc(Wp))!=EOF)
    {
        fprintf(Cp,"%04d",num);
        printf("%04d",num);
        while((ch=fgetc(Wp))==' ');
        i=0;
        while((ch=fgetc(Wp))!='\n')
        {
            if (ch=='/'||ch==' ')
            {
                if(ch=='/')
                    op=1;
                else
                    op=2;
                j=0;
                max=20;
                while((vh=fgetc(Vp))!=EOF)
                {
                    if (vh!='\n')
                    {
                        voca[j]=vh;
                        j++;
                    }
                    else
                    {
                        if (max>distance(strlen(word)-1,strlen(voca)-1,word,voca))
                        {
                        	for (j=0;j<20;j++)
                        		corr[j]='\0';
                            strcpy(corr,voca);
                        }
                        for(j=0;j<20;j++)
                            voca[j]='\0';
                        j=0;
                    }
                }
                if (op==1)
                {
                	fprintf(Cp,"/%s",corr);
                	printf("/%s",corr);
				}
                else
                {
                	fprintf(Cp," %s",corr);
                	printf(" %s",corr);
				}
            }
            else if(ch<0&&ch!=EOF)
            {
                fseek(Wp,1,SEEK_CUR);
                continue;
            }
            else if(ch==EOF)
                break;
            else
            {
                word[i]=ch;
                i++;
            }
        }
        for(i=0;i<20;i++)
        	word[i]='\0';
        fputc('\n',Cp);
        putchar('\n');
        num++;
    }
    fclose(Vp);
    fclose(Wp);
    fclose(Cp);
    return 0;
}
int min(int x,int y,int z)
{
    if (x>=y&&x>=z)
        return x;
    else if (y>=x&&y>=z)
        return y;
    else
        return z;
}
int distance(int i,int j,char w[],char v[])
{
    if (i==0)
        return j;
    else if (j==0)
        return i;
    else
    {
        if (w[i]==v[j])
            return min(distance(i-1,j,w,v)+1,distance(i,j-1,w,v)+1,distance(i-1,j-1,w,v));
        else
            return min(distance(i-1,j,w,v)+1,distance(i,j-1,w,v)+1,distance(i-1,j-1,w,v)+1);
    }
}
