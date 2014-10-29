#include <iostream>

using namespace std;

int main()
{
    int n[6]={0};
    int i,j,k;
    for(i=1;i<=5;i++)
    {
        n[i]=1;
        for(j=0;j<=5;j++)
        {
            if(n[j]==1)
                continue;
            n[j]=1;
            for(k=0;k<=5;k++)
            {
                if(n[k]==1)
                    continue;
                cout<<i<<j<<k<<endl;
            }
            n[j]=0;
        }
        n[i]=0;
    }
    return 0;
}
