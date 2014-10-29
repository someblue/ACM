#include <iostream>

using namespace std;

int v[10000];

void print(const int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<v[i]<<' ';
    cout<<endl;
}

int main()
{
    int n,i,j,t,minn,mini;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        v[i]=t;
    }
    for(i=0;i<n-1;i++)
    {
        minn=v[i];mini=i;
        for(j=i;j<n;j++)
        {
            if(minn>v[j]){minn=v[j];mini=j;}
        }
        swap(v[i],v[mini]);
        print(n);
    }
    return 0;
}
