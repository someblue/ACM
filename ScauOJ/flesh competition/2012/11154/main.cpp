#include<stdio.h>
#include<string.h>
double lesvalue(int t,double v)
{
    double sum=0;
    if(t>7) sum=0;
    else sum=v/(t+1);
    return sum;
}
int night(char str,int t)
{
    int sum;
    if(str=='0') sum=0;
    else sum=t+1;
    return sum;
}
int main()
{
    int n,t=0,temp=0,i;
    double v[110],sum=0,total=0;
    char s[110],str[110];
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%lf",&v[i]);
        total+=v[i];
    }
    //printf("total:%lf\n",total);//******************************//
    for(i=0; i<=n; i++) s[i]=getchar();
    s[i]='\0';
    for(i=1; i<=n; i++)
    {
        sum=0;
        t=0;
        strcpy(str,s);
        str[i]='0';
        for(int j=0; j<n; j++)
        {
            sum=sum+lesvalue(t,v[j]);
            t=night(str[j],t);
        }
        //printf("%d:%lf\n",i,sum);//***********************************//
        if(sum>=total/2)
        {
            printf("0>_<0!");
            temp=1;
            break;
        }
    }
    if(!temp) printf("POOR LRC!");
    return 0;
}
