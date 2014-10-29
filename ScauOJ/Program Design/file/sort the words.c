#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fin,*fout;
    char ans[10000][11],temp[11];
    int i,j,counter;
    fin=fopen("case1.in","r");
    fout=fopen("answer.txt","w");
    for(counter=1;!feof(fin);counter++)
    {
        fgets(ans[counter-1],11,fin);
    }
    for(i=0;i<counter;i++)
        for(j=0;j<counter-i-1;j++)
        {
            if(strcmp(ans[j],ans[j+1])>0)
            {
                strcpy(temp,ans[j]);
                strcpy(ans[j],ans[j+1]);
                strcpy(ans[j+1],temp);
            }
        }
    for(i=0;i<counter;i++)
        fputs(ans[i],fout);
    fclose(fin);
    fclose(fout);
}
