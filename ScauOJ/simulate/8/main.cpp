#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int man,woman,child,res,n,m;
    res=0;
    cin>>n>>m;
    for(child=0;child<=n;child+=2)
    {
        for(woman=0;woman<=n-child;woman++)
        {
            for(man=0;man<=n-child-woman;man++)
            {
                if(child+man+woman==n&&child/2+man*3+woman*2==m)
                {
                    res++;
                    //printf("man:%d,woman:%d,child:%d\tsum:%d\n",man,woman,child,man+woman+child);
                }
            }
        }
    }
    if(res==0)cout<<"no"<<endl;
    else cout<<res<<endl;
    return 0;
}
