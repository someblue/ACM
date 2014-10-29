#include <iostream>

using namespace std;

int main()
{
    int res,n,i,a;
    while(cin>>n&&n)
    {
        res=0;
        for(i=0;i<n;i++)
        {
            cin>>a;
            res^=a;
        }
        cout<<res<<endl;
        if(res) cout<<"Rabbit Win!"<<endl;
        else cout<<"Grass Win!"<<endl;
    }
    return 0;
}
