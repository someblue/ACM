#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 130;

//   http://106.185.28.251/vjudge/contest/view.action?cid=54297#overview
char s[N];
int len,cur;
vector<string> ans;
inline bool is(char c)
{
    return (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9');
}
string readName()
{
    string res;
    while(cur<len && is(s[cur]))
    {
        res.push_back(s[cur]);
        cur++;
    }
    return res;
}
int readInt()
{
    int res=0;
    while(cur<len && isdigit(s[cur]))
    {
        res = res*10 + s[cur]-'0';
        ++cur;
    }
    return res;
}

string build()
{
    if(cur>=len)    return string("");
    string res,id,clas,name;
    bool idflag=0,clasflag=0,fir=1;
    int rep=1;
    if(s[cur]=='(')
    {
        while(s[cur]=='(')
        {
             cur++;
             res+=build();
             cur++;
        }
        return res;
    }
    name = readName();
    for(;cur<len;)
    {
        if(s[cur]=='#')
        {
            idflag = 1;
            cur++;
            id = readName();
        }
        else if(s[cur]=='.')
        {
            clasflag=1;
            if(fir) fir=0;
            else clas.push_back(' ');
            cur++;
            clas+=readName();
        }
        else if(s[cur]=='*')
        {
            cur++;
            rep = readInt();
        }
        else if(s[cur]==')')
            break;
        else if(s[cur]=='>')
            break;
    }
    res.push_back('<');
    res.append(name);
    if(idflag)
    {
        res.append(string(" id=\""));
        res.append(id);
        res.push_back('"');
    }
    if(clasflag)
    {
        res.append(string(" class=\""));
        res.append(clas);
        res.push_back('"');
    }
    res.push_back('>');
    if(s[cur]=='>')
    {
        cur++;
        res+=build();
    }
    res.push_back('<');
    res.push_back('/');
    res.append(name);
    res.push_back('>');
    if(rep>1)
    {
        string tmp = res;
        rep--;
        while(rep--)    res+=tmp;
    }
    return res;
}
bool fir=1;
void run()
{
//    scanf("%s",s);
    cin>>s;
    len = strlen(s);
    cur=0;
    ans.clear();
//    if(fir) fir=0;
//    else cout<<endl;
    cout<<build()<<endl;
}

int main()
{
    #ifdef LOCAL
//    freopen("in","r",stdin);
    #endif
    ios::sync_with_stdio(false);
    int _;
//    scanf("%d",&_);
    cin>>_;
    while(_--)
        run();
//    cout<<"---end---"<<endl;
    return 0;
}
