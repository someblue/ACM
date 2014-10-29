#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n,i,j,flag;
    cin>>n;
    for(i=-n;i<=n;i++)
    {
        flag=1;
        for(j=-n;j<=n;j++)
        {
            if((fabs(i)+fabs(j)<=n))
            {
                cout<<'*';
                flag=0;
            }
            else if(flag)
                cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}
