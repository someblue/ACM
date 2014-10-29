#include <iostream>
#include <cstring>

using namespace std;

int twopow(int n)
{
    int res=1;
    while(n--) res*=2;
    return res;
}

int main()
{
    char s[20];
    int len,si,ans,i;
    cin>>s;
    len=strlen(s);
    ans=0;
    for(i=0;i<len;i++)
    {
        si=len-1-i;
        if(s[i]=='1') ans+=twopow(si);
        else if(s[i]=='0') continue;
        else
        {
            ans+=twopow(si+1)-1;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
