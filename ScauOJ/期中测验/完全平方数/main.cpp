#include <iostream>
#include <cstring>

using namespace std;

int n[100100];

int main()
{
    int i;
    memset(n,0,sizeof(n));
    for(i=1;i*i<=100000;i++)
        n[i*i]=1;
    for(i=21;i<=100000-268;i++)
    {
        if(n[i+100]&&n[i+268])
            cout<<i<<endl;
    }
    return 0;
}
