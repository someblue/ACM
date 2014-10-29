#include <iostream>

using namespace std;

bool f(int n)
{
    int i;
    for(i=2;i<n;i++)
        if(n%i==0)
            return 0;
    return 1;
}

int main()
{
    int i,j;
    cout<<'2'<<endl;
    for(i=3;i<200;i++)
        if(f(i))
            cout<<i<<endl;
    return 0;
}
