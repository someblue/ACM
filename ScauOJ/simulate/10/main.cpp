#include <iostream>
#include <cmath>

using namespace std;

bool f(int n)
{
    int i,s;
    s=(int)sqrt((double)n);
    for(i=2;i<=s;i++)
        if(n%i==0)
            return 0;
    return 1;
}

int main()
{
    int i,j,k,a,b,t,pn,res=0;
    bool n[100],flag;
    cin>>a>>b;
    for(i=a;i<=b;i++)
    {
        if(f(i))
        {
            pn=0;
            t=i;
            while(t!=0)
            {
                n[pn++]=t%2;
                t/=2;
            }
            j=0;k=pn-1;flag=1;
            while(j<k)
                if(n[j++]!=n[k--])
                {
                    flag=0;
                    break;
                }
            if(flag)
                res++;
        }
    }
    cout<<res;
    return 0;
}
