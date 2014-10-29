#include <iostream>

using namespace std;

int ans[10][4]=
{
    {0,0,0,0},
    {1,1,1,1},
    {6,2,4,8},
    {1,3,9,7},
    {6,4,6,4},
    {5,5,5,5},
    {6,6,6,6},
    {1,7,9,3},
    {6,8,4,2},
    {1,9,1,9}
};

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        a%=10;
        b%=4;
        cout<<ans[a][b]<<endl;
    }
    return 0;
}
