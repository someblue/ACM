#include <iostream>

using namespace std;

void showb(int x)
{
    if(!x) return;
    showb(x/2);
    cout<<x%2;
}

void text1()//1^2^3^...^n-1^0
{
    int n,i,res;
    for(n=1;n<=50;n++)
    {
        res=0;
        for(i=0;i<n;i++)
            res^=i;
        cout<<n<<": "<<res<<endl;
    }
}

void text2()//1%n^2%n^3%n^...^n%n
{
    int n,i,res;
    for(n=1;n<=50;n++)
    {
        res=0;
        for(i=1;i<=n;i++)
            res^=i%n;
        cout<<n<<": "<<res<<endl;
    }
}

void text3()
{
    int n,i,res1,res2,res3;
    for(n=1;n<=50;n++)
    {
        res1=res2=res3=0;
        for(i=1;i<=n;i++)
        {
            res1^=i%n;
            res2^=n%i;
            res3=res1^res2;
        }
        cout<<n<<":\t"<<res1<<'\t'<<res2<<'\t'<<res3<<endl;
    }
}

int main()
{
//    text1();
//    text2();
//    text3();
//    return 0;
    int i,j,n;
    int res;
//    while(cin>>n)
    for(n=1;n<=100;n++)
    {
        //cout<<n<<": ";
        res=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                res^=i%j;
            }
        }
//        cout<<res;
//        if(n%10==0)
//            cout<<endl;
//        else
//            cout<<'\t';

        cout<<n<<":\t"<<res<<"\t\t";

        showb(n);cout<<'\t';showb(res);cout<<endl;

    }
    return 0;
}
