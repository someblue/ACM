#include <iostream>

using namespace std;

int cnt,k;

void div(int x)
{
    int a,b;
    if(x%2){a=x/2;b=x/2+1;}
    else a=b=x/2;
    if(a<=k){cnt++;}
    else div(a);
    if(b<=k){cnt++;}
    else div(b);
}

int main()
{
    int case_num,n;
    cin>>case_num;
    while(case_num--)
    {
        cnt=0;
        cin>>n>>k;
        div(n);
        cout<<cnt<<endl;
    }
    return 0;
}
