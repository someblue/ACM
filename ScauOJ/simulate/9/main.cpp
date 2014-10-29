#include <cstdio>

int main()
{
    freopen("case.txt","r",stdin);
    FILE *fp;
    char c1,c2,c3;
    fp=fopen("answer.txt","w");
    c1=c2=c3='a';
    while((c3=getchar())!=EOF)
    {
        fputc(c3,fp);
        if(c1=='b'&&c2=='y'&&c3=='e')
            break;
        c1=c2;c2=c3;
    }
    fclose(fp);
}
