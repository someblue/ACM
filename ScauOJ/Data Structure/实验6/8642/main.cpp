#include <iostream>
#include <cstdio>
#include <cstring>
#define N 10010

using namespace std;

int num[N],n;

void show(int l,int r)
{
    int p=l;
    for(;p<r;p++) cout<<num[p]<<' ';
    cout<<endl;
}

int par(int l,int r)
{
    int key=num[l],t=num[l];
    while(l<r)
    {
        while(l<r&&num[r]>=key) r--;
        num[l]=num[r];
        while(l<r&&num[l]<=key) l++;
        num[r]=num[l];
    }
    num[l]=t;
    return l;
}

void qs(int l,int r)
{
    if(l<r)
    {
        int p=par(l,r);
        show(0,n);
        qs(l,p-1);
        qs(p+1,r);
    }
}

int main()
{
    int i;
    cin>>n;
    for(i=0;i<n;i++) cin>>num[i];
    //show(0,n);
    qs(0,n-1);
}
