#include <iostream>
#include <cstdio>
#define N 110
using namespace std;
int t[N];

int main()
{
    int n,d;
    cin>>n>>d;
    int i,s;
    s=0;
    for(i=0;i<n;i++) cin>>t[i],s+=t[i];
    s+=10*(n-1);
    if(s<=d)
    {
        cout<<(d-s)/5+(n-1)*2<<endl;
    }
    else cout<<"-1"<<endl;
    return 0;
}
