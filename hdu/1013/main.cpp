#include <iostream>

using namespace std;

int solve(string s)
{
    int res=0,t;
    for(int i=0;i<s.size();++i)
        res+=s[i]-'0';
    while(res/10)
    {
        t=res;
        res=0;
        for(;t;t/=10)
            res+=t%10;
    }
    return res;
}

int main()
{
    string n;
    while(cin>>n && n[0]!='0')
        cout<<solve(n)<<endl;
    return 0;
}
