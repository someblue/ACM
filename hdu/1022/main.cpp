#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1000;

int n;
char s1[N],s2[N];
char stk[N];
int order[N];
char sss[2][5]={"out","in"};

int main()
{
    while(scanf("%d%s%s",&n,s1,s2)!=EOF)
    {
        int p1,p2,ps,po;
        p1=p2=ps=po=0;
        while(p1<n)
        {
            stk[ps++]=s1[p1++];
            order[po++]=1;
            while(ps && stk[ps-1]==s2[p2])
                ps--,p2++,order[po++]=0;
        }
        while(ps && stk[ps-1]==s2[p2])
            ps--,p2++;
        if(p2<n)
        {
            printf("No.\n");
        }
        else
        {
            printf("Yes.\n");
            for(int i=0;i<po;++i)
                printf("%s\n",sss[order[i]]);
        }
        puts("FINISH");
    }
    return 0;
}
