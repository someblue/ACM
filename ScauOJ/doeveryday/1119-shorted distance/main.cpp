#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int m,n,num[500],dis,l,r;
    int i;
    cin>>m;
    while(m--)
    {
        cin>>n;
        for(i=0;i<n;i++)
            cin>>num[i];
        sort(num,num+n);
        l=0;r=n-1;
        dis=0;
        while(l<r)
            dis+=num[r--]-num[l++];
        cout<<dis<<endl;
    }
    return 0;
}
