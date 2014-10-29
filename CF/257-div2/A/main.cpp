#include <iostream>

using namespace std;

int main()
{
    int t=-1,idx,a;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a;
//        cout<<a/m+(a%m>0)<<' ';
        if(t<=a/m+(a%m>0))
        {
            t=a/m+(a%m>0);
            idx=i;
        }
    }
//    cout<<endl;
    cout<<idx<<endl;
    return 0;
}
