#include <iostream>

using namespace std;
const int N = 100;
int f[N];

void build()
{
    f[0]=7;
    f[1]=11;
    for(int i=2;i<N;++i)
        f[i]=f[i-1]+f[i-2];
}

void dabiao()
{
    for(int i=0;i<40;++i)
    {
        if(i%10==0) cout<<endl;
        if(f[i]%3)  cout<<0<<' ';
        else cout<<1<<' ';

    }
}

int main()
{
//    build();
//    dabiao();
    int n;
    while(cin>>n)
        if(n%4==2)  cout<<"yes"<<endl;
        else    cout<<"no"<<endl;
    return 0;
}
