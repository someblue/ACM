#include <iostream>

using namespace std;

const int dx[]={1,1,0,-1,-1,0};
const int dy[]={-1,0,1,1,0,-1};
const int mod = 1000000007 ;

int main()
{
    int x,y,n;
    cin>>x>>y>>n;
    int k=n%6;
    int ans=(dx[k]*x+dy[k]*y)%mod;
    if(ans<0)   ans+=mod;
    cout<<ans<<endl;
    return 0;
}
