#include <stdio.h>
#include <string.h>
int main()
{
    char str[3][81];
    int i,maxlen,max_i,minlen,min_i;
    gets(str[0]);
    gets(str[1]);
    //judge max and min
    if(strlen(str[0])>strlen(str[1]))
    {
        maxlen=strlen(str[0]);
        max_i=0;
        minlen=strlen(str[1]);
        min_i=1;
    }
    else
    {
        maxlen=strlen(str[1]);
        max_i=1;
        minlen=strlen(str[0]);
        min_i=0;
    }
    //add operation
    str[2][maxlen]=NULL;
    for(i=1;i<=minlen;i++)
        str[2][maxlen-i]=str[max_i][maxlen-i]+str[min_i][minlen-i]-'0';
    for(i=0;i<maxlen-minlen;i++)
        str[2][i]=str[max_i][i];
    //过十进一
    for(i=maxlen-1;i>=1;i--)//str[2][0]上过10需要另外处理
    {
        if(str[2][i]>'9')
        {
            str[2][i]-=10;
            str[2][i-1]++;
        }
    }
    //处理str[2][0]过10情况
    if(str[2][0]>'9')
    {
        str[2][maxlen+1]=NULL;
        str[2][0]-=10;
        for(i=maxlen;i>=1;i--)
            str[2][i]=str[2][i-1];
        str[2][0]='1';
    }
    //print
    puts(str[2]);
    system("pause");
    return 0;
}
