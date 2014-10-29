#include <iostream>
#include <cstdio>
#define N 210
using namespace std;
const int INF = 11111;
int a[N],t[N],n;

void arrcpy(int *n1,int *n2,int l)
{
    int i;
    for(i=0;i<l;i++)
        *(n1+i) = *(n2+i);
}

int getmax(int *arr,int l,int r)
{
    int ret=-INF,idx=n;
    int i;
    for(i=0;i<l;i++)
    {
        if(ret<*(arr+i))
        {
            ret=*(arr+i);
            idx=i;
        }
    }
    for(i=r;i<n;i++)
    {
        if(ret<*(arr+i))
        {
            ret=*(arr+i);
            idx=i;
        }
    }
    return idx;
}
int getmin(int *arr,int l,int r)
{
    int ret=INF,idx;
    int i;
    for(i=l;i<r;i++)
    {
        if(ret>*(arr+i))
        {
            ret=*(arr+i);
            idx=i;
        }
    }
    return idx;
}
int getsum(int *arr,int l,int r)
{
    int ret=0;
    for(int i=l;i<r;i++)
        ret+=*(arr+i);
    return ret;
}

void run()
{
    int k,i,j,ans,maxidx,minidx;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)    scanf("%d",&a[i]);
    ans=-INF;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            arrcpy(t,a,n);
            t[n]=-INF;
            for(int ii=0;ii<k;ii++)
            {
                minidx = getmin(t,i,j);
                maxidx = getmax(t,i,j);
                if(t[maxidx]<=t[minidx])
                    break;
                swap(t[maxidx],t[minidx]);
            }
            ans = max(ans,getsum(t,i,j));
        }
    }
    cout<<ans<<endl;
}

int main()
{
    run();
    return 0;
}
