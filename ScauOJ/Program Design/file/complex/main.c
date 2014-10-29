#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char word[10000][21],topword[5][21];
int wordlog[10000]={0},topwordlog[5];//wordlog:the number of word appearing

int input(FILE *fp)
{
    int counter=0,letter;//word[counter][letter]
    char ch;
    int i,flag;
    while((ch=fgetc(fp))!=EOF)
    {
        if(!( (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||((ch=='-')&&(*(fp->_ptr)=='\n') ) ) )//or *(fp->_p+1)=='\n'
            continue;
        letter=0;
        while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||((ch=='-')&&(*(fp->_ptr)=='\n')))
        {
            if(ch=='-')
            {
                ch=fgetc(fp);
                ch=fgetc(fp);
                continue;
            }
            if(ch>='A'&&ch<='Z')
                ch += 32;
            word[counter][letter]=ch;
            letter++;
            ch=fgetc(fp);
        }
        word[counter][letter]='\0';
        //find existing
        flag=1;
        for(i=0;i<counter;i++)
        {
            if(strcmp(word[i],word[counter])==0)
            {
                wordlog[i]++;
                flag=0;
                break;
            }
        }
        if(flag)
            counter++;
    }
    //use for text
    /*for(i=0;i<counter;i++)
        printf("%s,%d\n",word[i],wordlog[i]+1);*/
    return counter;
}

void sort_and_print(int counter)
{
    int i,j,flag;
    char temp[21];
    int templog;
    //sort
    for(i=0;i<5;i++)
    {
        templog=-1;
        strcpy(temp,"Z");
        for(j=0;j<counter;j++)
        {
            if(templog<wordlog[j])
            {
                templog=wordlog[j];
                strcpy(temp,word[j]);
                flag=j;
            }
            else if(templog==wordlog[j] && strcmp(temp,word[j])>0)
            {
                templog=wordlog[j];
                strcpy(temp,word[j]);
                flag=j;
            }
        }
        topwordlog[i]=templog;
        strcpy(topword[i],temp);
        wordlog[flag]=-2;
    }
    //print
    for(i=0;i<5;i++)
        printf("%s %d\n",topword[i],topwordlog[i]+1);
}

int main()
{
    FILE *fp;
    int counter;
    fp=fopen("case1.in","r");
    counter=input(fp);
    sort_and_print(counter);
    //printf("%d\n",sizeof(sort_and_print));
    fclose(fp);
    return 0;
}
