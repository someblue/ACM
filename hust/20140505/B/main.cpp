#include <iostream>

using namespace std;

int main()
{
    int n,c,t,a,b,i,res,k;
    cin>>n>>t>>c;
    a=-1;res=0;
    for(i=0;i<n;i++)
    {
        cin>>k;
        if(k>t)
        {
            b=i;
            if(b-c>a)   res+=b-c-a;
            a=b;
        }
    }
    b=n;
    if(b-c>a)   res+=b-c-a;
    a=b;
    cout << res << endl;
    return 0;
}
