#include <iostream>
#define N 1000
using namespace std;
int h[N],n;
void  show()
{
    for(int i=1;i<=n;i++) cout<<h[i]<<' ';
    cout<<endl;
}
void adjust(int s,int m)
{
    int rc=h[s],j;
    for(j=2*s;j<=m;j*=2)
    {
        if(j<m&&h[j+1]>h[j]) j++;
        if(rc>=h[j]) break;
        h[s]=h[j];s=j;
    }
    h[s]=rc;
}
int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++) cin>>h[i];
    for(i=n/2;i>0;i--) adjust(i,n);
    show();
    for(i=n;i>1;i--)
    {
        swap(h[1],h[i]);
        adjust(1,i-1);
        show();
    }
    return 0;
}
