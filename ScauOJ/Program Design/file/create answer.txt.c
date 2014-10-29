#include <stdio.h>

main()
{
    FILE *fp;
    char ch1,ch2,ch3;

    fp=fopen("answer.txt","w");
    ch1=getchar();
    fputc(ch1,fp);
    ch2=ch1;
    ch1=getchar();
    fputc(ch1,fp);
    while(!(ch1=='e' && ch2=='y' && ch3=='b'))
    {
        ch3=ch2;
        ch2=ch1;
        ch1=getchar();
        fputc(ch1,fp);
    }
    fclose(fp);
}
