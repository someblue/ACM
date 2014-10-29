#include <iostream>
#include <stack>
#include <string>

using namespace std;

void run()
{
    int n,i;
    string s;
    while(cin>>n>>s)
    {
        long long ans=0;
        for(i=0;i<n;i++)
            if(s[i]=='B')
                ans+=(1LL<<i);
        cout<<ans<<endl;
    }
}

int main()
{
    run();
//    int n,i,ans,bnum;
//    string s;
//    stack<char> stk;
//    while(cin>>n)
//    {
//        cin>>s;
//        bnum=ans=0;
//        while(!stk.empty()) stk.pop();
//        for(i=n-1;i>=0;i--)
//        {
//            stk.push(s[i]);
//            if(s[i]=='B')
//                bnum++;
//        }
//        while(bnum)
//        {
//            while(stk.top()=='R') stk.pop();
//            stk.pop();bnum--;
//            stk.push('R');
//            while(stk.size()<n) stk.push('B'),bnum++;
//            ans++;
//        }
//        cout<<ans<<endl;
//    }
    return 0;
}
