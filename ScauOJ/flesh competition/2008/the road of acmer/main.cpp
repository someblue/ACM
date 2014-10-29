#include <iostream>
#define MAXN 1000

using namespace std;

int main()
{
    bool sub[MAXN]={0};
    int i;
    int tot_sub,tot_study,a,b,num=0;
    cin>>tot_sub>>tot_study;
    while(tot_study--)
    {
        cin>>a>>b;
        if(sub[a]||sub[b])
            sub[a]=sub[b]=1;
        else
        {
            num++;
            sub[a]=sub[b]=1;
        }
    }
    for(i=0;i<tot_sub;i++)
        if(!sub[i])
            num++;
    cout<<num<<endl;
    return 0;
}
