#include <iostream>
#include <cmath>
#include <cstdio>
#define PI 3.1415927
using namespace std;
int main()
{
    int n,m;
    cin>>m;
    while(m--)
    {
        cin>>n;
        double sum=0.0;
        for(int i=1; i<=n; i++)
        {
            if(i%2) sum += 1.0/i;
            else sum -= 1.0/i;
        }
        printf("%.2f\n",sum);
    }
}
