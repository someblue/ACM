#include <stdio.h>

int main()
{
    FILE *fp;
    char ch1[12],ch2[12],ch3[12],ch4[13],ch5[13],ch6[13],ch7[13],ch8[13];
    fp=fopen("case1.in","r");
    fgets(ch1,10,fp);
    fseek(fp,0,0);
    fgets(ch2,11,fp);
    fseek(fp,0,0);
    fgets(ch3,12,fp);
    fseek(fp,0,0);
    fgets(ch4,13,fp);
    fseek(fp,0,0);
    fscanf(fp,"%s",ch5);
    fscanf(fp,"%s",ch6);
    fscanf(fp,"%s",ch7);
    fscanf(fp,"%s",ch8);
    printf("10:%s;\n",ch1);//有效读入9
    printf("11:%s;\n",ch2);//有效读入10
    printf("12:%s;\n",ch3);//有效读入enter
    printf("13:%s;\n",ch4);
    printf("fscanf1:%s;\n",ch5);
    printf("fscanf2:%s;\n",ch6);
    printf("fscanf3:%s;\n",ch7);
    printf("fscanf4:%s;\n",ch8);
    fclose(fp);
    return 0;
}//Õý³£
