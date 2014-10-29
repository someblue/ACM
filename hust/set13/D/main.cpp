#include <iostream>

using namespace std;

int main()
{
    int m,x,ans;
    while(cin>>m && m)
    {
        ans = 0;
        while(m--)
        {
            cin>>x;
            ans ^= x;
        }
        if(ans) cout<<"Rabbit Win!"<<endl;
        else    cout<<"Grass Win!"<<endl;
    }
    return 0;
}
