#include <iostream>

using namespace std;

int main()
{
    int n,m;
    int _;
    cin>>_;
    while(_--)
    {
        cin>>n>>m;
        if(n%(m+1)) cout<<"Grass"<<endl;
        else    cout<<"Rabbit"<<endl;
    }
    return 0;
}
