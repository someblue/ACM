#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <map>
#define VI vector<int>
#define N 1000010
using namespace std;
typedef long long ll;

char s[N];
int len;

inline bool equ(int s1,int l)
{
    int s2=s1+l,i;
    //if(s2>=len) return 1;
    for(i=0;i<l;i++)
        if(s[s1++]!=s[s2++]) return 0;
    return 1;
}

void run()
{
    int s1,sl,ok;
    while(gets(s),strcmp(s,".")!=0)
    {
        sl=strlen(s);//ok=0;
        for(len=1;len<sl;len++)
        {
            ok=1;
            if(sl%len!=0) continue;
            for(s1=0;s1<sl;s1+=len)
            {
                //if(equ(s1,len)){ok=1;break;}
                if(s1+len<sl)
                ok&=equ(s1,len);
            }
            if(ok) break;
        }
        printf("%d\n",sl/len);
    }
}

int main()
{
    //freopen("in","r",stdin);
    run();
    return 0;
}
