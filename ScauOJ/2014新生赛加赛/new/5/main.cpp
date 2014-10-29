#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 2010

using namespace std;

char a[N],m[N];
long long w[N];

int main()
{
    long long s,y;
    int mlen,i,t,n,ok;
    char tempc;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        n=strlen(a);
        for(i=0;i<n-1;i++)
            scanf("%I64d",&w[i]);
        scanf("%d",&mlen);
        scanf("%c",&tempc);
        for(i=0;i<mlen;i++)
        {
            //do{scanf("%c",&m[i]);}while(m[i]!=' ');
            scanf("%c%c",&m[i],&tempc);
        }

//        printf("%s\n",a);
//        for(i=0;i<n-1;i++)
//            printf("%I64d ",w[i]);
//        cout<<endl;
//        printf("mlen:%d\n",mlen);
//        for(i=0;i<mlen;i++)
//            printf("%c ",m[i]);

        s=0;ok=0;
        for(i=0;i<n-1;i++)
        {
            s+=(a[i]-'0')*w[i];
        }
        y=s%mlen;
        if(a[n-1]==m[y]) ok=1;
        printf("%s\n",ok?"Yes":"No" );
    }
    return 0;
}
