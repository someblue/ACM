#include <iostream>
#include <cstdio>
#define N 100010
using namespace std;
int num[N],n,k,p,a,b,c;

void nextodd(int &i)
{
    for(;i<n;i++)   if(num[i]&1)    return;
}
void nexteven(int &i)
{
    for(;i<n;i++)   if(!(num[i]&1))    return;
}

int main()
{
    scanf("%d%d%d",&n,&k,&p);
    int i;
    a=b=c=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        if(num[i]&1) a++;
    }
    b=n-a;
    if(a<(k-p) || (a-(k-p))&1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(b<p)
    {
        if((a-(k-p))/2+b<p)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        c=(p-b);
        a-=c*2;
    }
    //printf("a=%d b=%d c=%d\n",a,b,c);
    //print
    cout<<"YES"<<endl;
    int podd,peven;
    podd=peven=0;
    //print odd
    if(a)
    {
        printf("%d",a-(k-p)+1);
        for(i=0;i<a-(k-p)+1;i++)
        {
            nextodd(podd);
            printf(" %d",num[podd++]);
        }
        printf("\n");
    }
    for(i=1;i<k-p;i++)
    {
        nextodd(podd);
        printf("1 %d\n",num[podd++]);
    }
    //print even
    if(c)
    {
        for(i=0;i<c;i++)
        {
            printf("2 ");
            nextodd(podd);
            printf("%d ",num[podd++]);
            nextodd(podd);
            printf("%d\n",num[podd++]);
        }
        for(i=0;i<b;i++)
        {
            nexteven(peven);
            printf("1 %d\n",num[peven++]);
        }
    }
    else
    {
        if(b)
        {
            printf("%d",b-p+1);
            for(i=0;i<b-p+1;i++)
            {
                nexteven(peven);
                printf(" %d",num[peven++]);
            }
            printf("\n");
        }
        for(i=1;i<p;i++)
        {
            nexteven(peven);
            printf("1 %d\n",num[peven++]);
        }
    }
    return 0;
}
