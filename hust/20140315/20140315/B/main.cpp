#include <iostream>
#include <cstdio>
#include <cstring>
#define N 15

using namespace std;

char s[N];

int main()
{
    int i,j,l,n,ok;
    gets(s);
    l=strlen(s);ok=1;
    for(i=0;i<l;i++)
    {
        if(s[0]!='1'){ok=0;break;}
        n=0;
        for(j=i;j<l;j++)
        {
            if(s[j]!='4'&&s[j]!='1'){ok=0;break;}
            if(s[j]=='1'){break;}
            if(s[j]=='4'){n++;if(n==3){ok=0;break;}}
        }
        if(ok==0) break;
    }
    printf("%s\n",ok?"YES":"NO");
    return 0;
}
