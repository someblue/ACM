#include <bits/stdc++.h>
using namespace std;
char s[1000];
int BkdrHash(char *s)
{
    unsigned int seed = 131;
    unsigned int hash = 0;
    while(*s)
        if(*s==' ') s++;
        else hash = hash*seed + (*s++);
    return hash & 0x7fffffff;
}
int main()
{
    freopen("case.txt","r",stdin);
    while(gets(s))
        printf("%s // %x\n",s,BkdrHash(s));
    return 0;
}
