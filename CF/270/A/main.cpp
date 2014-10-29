#include <iostream>

using namespace std;

int main()
{
    int x;
    while(cin>>x)
    {
        if(x&1)
        {
            cout<<"9 "<<x-9<<endl;
        }
        else
        {
            cout<<"4 "<<x-4<<endl;
        }
    }
    return 0;
}
