#include <iostream>
#include <cstdio>
#define N 210

using namespace std;

char s[N];

int main()
{
    int T,Ti,i;
    long long div,bediv;
    scanf("%d",&T);
    for(Ti=1;Ti<=T;Ti++)
    {
        scanf("%s%I64d",s,&div);
        if(div<0)div=-div;
        bediv=0;
        if(s[0]=='-') i=1;
        else i=0;
        for(;s[i]!='\0';i++)
            bediv=(bediv*10+s[i]-'0')%div;
        if(bediv)
            printf("Case %d: not divisible\n",Ti);
        else
            printf("Case %d: divisible\n",Ti);
    }
    return 0;
}
