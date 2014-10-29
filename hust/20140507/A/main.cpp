#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int n,i,cnt,j;
    bool ud;
    cin>>n;
    cin>>s;
    for(i=0,cnt=0;i<n;i++)
        if(s[i]=='X')
            cnt++;
    if(cnt==n/2)
        cnt=0;
    else if(cnt>n/2)
        ud=0,cnt-=n/2;
    else
        ud=1,cnt=n/2-cnt;
    for(i=0,j=0;i<cnt;j++)
    {
        if(ud&&s[j]=='x')
            s[j]='X',i++;
        if(!ud&&s[j]=='X')
            s[j]='x',i++;
    }
    cout<<cnt<<endl<<s<<endl;
    return 0;
}
