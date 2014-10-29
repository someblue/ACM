#include <iostream>

using namespace std;

int pow(int a,int n)
{
    int i,ans=1;
    for(i=0;i<n;i++)
        ans*=a;
    return ans;
}

int R_to_ten(int a,int R)
{
    int t,ans=0,cnt=0;
    while(a!=0)
    {
        t=a%10;
        ans+=t*pow(R,cnt++);
        a/=10;
    }
    return ans;
}

int ten_to_R(int a,int R)
{
    int m,cnt=0,ans=0;
    while(a!=0)
    {
        m=a%R;
        ans+=m*pow(10,cnt++);
        a/=R;
    }
    return ans;
}

struct number{
    int n,len,maxnum,notation;
    void count_len()
    {
        int t=n,t2;
        maxnum=len=0;
        while(t!=0)
        {
            len++;
            t2=t%10;
            if(maxnum<t2)maxnum=t2;
            t/=10;
        }
    }
    friend number operator + (number a,number b)
    {
        number ans;
        if(a.notation==10)
        {
            ans.n=a.n+b.n;
            ans.notation=10;
            return ans;
        }
        int t;
        t= R_to_ten(a.n,a.notation) + R_to_ten(b.n,b.notation);
        ans.n= ten_to_R(t,a.notation);
        return ans;
    }
};

int main()
{
    number a,b,t;
    cin>>a.n>>b.n;
    a.count_len();
    b.count_len();
    a.notation=b.notation=max(a.maxnum,b.maxnum)+1;
    t=a+b;
    t.count_len();
    cout<<t.len<<endl;
    return 0;
}
