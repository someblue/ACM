#include <iostream>

using namespace std;

int main()
{
    int n;
    double a,b,x,y;
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>x>>y;
        if((a>=x&&b>=y)||(a>=y&&b>=x)) cout<<"Cutting is possible."<<endl;
        else cout<<"Cutting is impossible."<<endl;
    }
    return 0;
}
