#include <iostream>
#include <cstdio>
#define swap(x,y){temp=x;x=y;y=temp;}
#define MAXN 1000

using namespace std;

struct fruit{
    int w,t;
    bool vis;
    fruit(){w=t=0;vis=0;}
};

bool operator > (fruit &a,fruit &b)
{
    return a.t>b.t;
}

fruit f[MAXN];

int partition(int p,int r)
{
    int x=f[r].t;
    int i=p-1;
    int j;
    fruit temp;
    for(j=p;j<=r-1;j++)
        if(f[j].t>x)
        {
            i++;
            swap(f[i],f[j]);
        }
    i++;
    swap(f[i],f[r]);
    return i;
}

void quicksort(int p,int r)//decreasion,sort depending on time
{
    int q;
    if(p<r)
    {
        q=partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);
    }
}

int findday(int day,int s,int e)//return i. And f[i].t>=day && f[i+1].t<day
{
    if(s==e)return s;
    int m=(s+e)/2;
    if(f[m].t>=day&&f[m+1].t<day) return m;
    else if(f[m+1].t>=day) return findday(day,m+1,e);
    else if(f[m].t<day) return findday(day,s,m);
}

int main()
{
    freopen("case.txt","r",stdin);

    int n,i,day,maxday,sum,submaxday,maxw,max_i;
    bool flag;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>f[i].w>>f[i].t;
    sum=0;submaxday=0;
    maxday=f[0].t;
    for(i=1;i<n;i++)
        if(maxday<f[i].t) maxday=f[i].t;
    quicksort(0,n-1);
    for(day=maxday;day>=1;day--)
    {
        submaxday=findday(day,submaxday,n-1);
        maxw=0;flag=0;
        for(i=0;i<=submaxday;i++)
        {
            if(!f[i].vis)
                if(maxw<f[i].w)
                {
                    maxw=f[i].w;
                    max_i=i;
                    flag=1;
                }
        }
        if(flag)
        {
            sum+=maxw;
            f[max_i].vis=1;
        }
    }
    cout<<sum<<endl;
    return 0;
}
