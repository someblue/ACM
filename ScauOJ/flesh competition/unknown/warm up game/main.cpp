#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct bign{
    int num[1000],len;
    bign(){memset(num,0,sizeof(num));len=0;}
};

istream &operator >> (istream &in,bign &x)
{
    int n;
    in>>n;
    while(n!=0)
    {
        x.num[x.len++]=n%10000;
        n/=10000;
    }
    return in;
}

ostream &operator << (ostream &out,const bign &x)
{
    int i;
    for(i=x.len-1;i>=0;i--)
    {
        cout<<x.num[i];
    }
    cout<<endl;
    return out;
}

int main()
{
    long long sum,f1,f2;
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>f2>>f1>>n;
        sum=f2+f1;
        n-=2;
        while(n--)
        {
            f1=f1+f2;
            f2=f1-f2;
            sum+=f1;
        }
        cout<<sum<<endl;
    }
    return 0;
}
