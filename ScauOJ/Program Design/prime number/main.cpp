#include <iostream>
using namespace std;

int main()
{
    int prime[10000],n,i,j,counter,scope;
    bool flag;
    prime[0]=2;prime[1]=3;
    counter=2;
    cout<<"input the scope:";
    cin>>scope;
    cout<<'2'<<endl<<'3'<<endl;
    for(i=2;;i++)
    {
        //------------------6n-1------------------
        flag=1;
        n=6*(i-1)-1;
        if(n>scope)break;
        for(j=0;j<counter;j++)
            if(n%prime[j]==0)
            {
                flag=0;
                break;
            }
        if(flag)
        {
            prime[counter]=n;
            cout<<n<<endl;
            counter++;
        }
        //------------------6n+1------------------
        flag=1;
        n=6*(i-1)+1;
        if(n>scope)break;
        for(j=0;j<counter;j++)
            if(n%prime[j]==0)
            {
                flag=0;
                break;
            }
        if(flag)
        {
            prime[counter]=n;
            cout<<n<<endl;
            counter++;
        }
    }
    cout<<"counter:"<<counter<<endl;
    return 0;
}
