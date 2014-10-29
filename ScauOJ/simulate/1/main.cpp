#include <iostream>

using namespace std;

int main()
{
    int i,j,k;
    int n[3][4];
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
            cin>>n[i][j];
    }
    for(j=0;j<4;j++)
    {
        for(i=0;i<3;i++)
            cout<<n[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
