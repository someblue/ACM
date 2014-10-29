#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100100

using namespace std;

char s[N],arr[N],in[N];
int w[N],stk[N],whi[N];

int main()
{
    int p,pw,pin,ps,pstk;
    int i;
    char c;
    p=pw=pin=ps=pstk=0;
    memset(s,0,sizeof(s));
    memset(arr,0,sizeof(arr));
    memset(in,0,sizeof(in));
    memset(whi,0,sizeof(whi));
    while((c=getchar())!='#')
    {
        switch(c)
        {
            case '>': case '<': case '+': case '-': case '.': case ',': case '[': case ']': s[ps++]=c;
        }
    }
    s[ps]='\0';
    getchar();
    gets(in);
    for(i=0;i<ps;i++)
    {
        if(s[i]=='[') stk[pstk++]=i;
        else if(s[i]==']')
        {
            whi[stk[pstk-1]]=i;
            whi[i]=stk[pstk-1];
            pstk--;
        }
    }
    for(i=0;i<ps;i++)
    {
        c=s[i];
        switch(c)
        {
            case '>': p++;break;
            case '<': p--;break;
            case '+': arr[p]++;break;
            case '-': arr[p]--;break;
            case '.': putchar(arr[p]);break;
            case ',': arr[p]=in[pin++];break;
            case '[': if(!arr[p]) i=whi[i];break;
            case ']': if(arr[p]) i=whi[i];break;
        }
    }
    //printf("%s\n",in);
    return 0;
}
