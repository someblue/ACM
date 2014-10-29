#include <iostream>
#include <cstring>
#include <cstdio>
#define N 100010

using namespace std;

char s[N],t[N];

bool cmp()
{
    int ps,pt,slen,tlen;
    slen=strlen(s);
    tlen=strlen(t);
    for(ps=pt=0;ps<slen;ps++)
    {
        if(s[ps]==t[pt])
        {
            pt++;
            if(pt==tlen) return 1;
        }
    }
    return 0;
}

int main()
{
    freopen("case.txt","r",stdin);
    while(1)
    {
        if(!gets(s)) break;
        if(!gets(t)) break;
        //puts(s);puts(t);
        printf("%s\n",cmp()?"Yes":"No");
    }
    return 0;
}
/*
输入样例中的空行实际上是不存在的
*/
/*
AC
*/
