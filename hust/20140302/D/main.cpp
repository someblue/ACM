#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000000

using namespace std;

int isletter(char c)
{
    return (c>='a'&&c<='z')||(c>='A'&&c<='Z');
}

struct _s{
    char so[N],sc[N];
    void oritocopy()
    {
        int po,pc;
        po=pc=0;
        while(so[po]!='\0')
        {
            if(isletter(so[po]))
                sc[pc++]=so[po];
            po++;
        }
        sc[pc]='\0';
    }
};

int cmp(_s a,_s b)
{
    if(strcmp(a.so,b.so)==0) return 2;
    if(strcmp(a.sc,b.sc)==0) return 1;
    return 0;
}

_s s[2];

int inputs(char firstchar,int id)
{
    int ps;
    char tc;
    s[id].so[0]=firstchar;
    ps=1;
    while(scanf("%c",&tc)!=EOF)
    {
        if(tc=='-')
        {
            s[id].so[ps]='\0';
            return 1;
        }
        s[id].so[ps++]=tc;
    }
    return 0;
}

void print()
{
    puts("s0 ori:");
    puts(s[0].so);
    puts("s0 copy:");
    puts(s[0].sc);
    puts("s1 ori:");
    puts(s[1].so);
    puts("s1 copy:");
    puts(s[1].sc);
}

int main()
{
    freopen("in","r",stdin);
    char ans[3][20]={"DIFFERENT","SIMILAR","SAME"};
    char c;
    int ansid;
    while(scanf("%c",&c)!=EOF)
    {
        inputs(c,0);
        if(scanf("%c",&c)==EOF) break;
        inputs(c,1);
        s[0].oritocopy();
        s[1].oritocopy();
        ansid=cmp(s[0],s[1]);
        print();
        printf("%s\n",ans[ansid]);
    }
    return 0;
}
