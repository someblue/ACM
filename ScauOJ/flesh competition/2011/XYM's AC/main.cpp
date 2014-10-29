#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[60][60],t[60];

int main()
{
    int T,n,i;
    long long cnt;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        cnt=1;n--;
        scanf("%s",s[0]);
        //cout<<s[0]<<endl;
        while(n--)
        {
            scanf("%s",t);
            for(i=0;i<cnt;i++)
                if(!(strcmp(s[i],t)))
                    break;
            if(i==cnt)
            {
                strcpy(s[cnt++],t);
            }
        }
        //cout<<cnt<<endl;
        printf("%I64d\n",((1LL)<<cnt));
    }
    return 0;
}
