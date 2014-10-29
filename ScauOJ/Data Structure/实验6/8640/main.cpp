#include <iostream>
#define N 1000
using namespace std;
int arr[N],n;
void show()
{
    for(int i=0;i<n;i++) cout<<arr[i]<<' ';
    cout<<endl;
}
void shellsort(int d)
{
    int t,i,j;
    for(i=d;i<n;i++)
    {
        if(arr[i]<arr[i-d])
        {
            t=arr[i];
            for(j=i-d;j>=0&&t<arr[j];j-=d)
                arr[j+d]=arr[j];
            arr[j+d]=t;
        }
    }
}
int main()
{
    cin>>n;
    int i;
    for(i=0;i<n;i++) cin>>arr[i];
    int d=n/2;
    while(d)
    {
        shellsort(d);
        show();
        d/=2;
    }
}
