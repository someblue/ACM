#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 100;
int cas = 1;

//  http://acm.zju.edu.cn/mdj2014/contestInfo.do?contestId=2
char s[N],s2[N];
int n;

bool equ(int s1,int e1,int s2,int e2)
{
    if(e1-s1 != e2-s2) return 0;
    for(int i=0;i<e1-s1;i++)
        if(s[s1+i]!=s[s2+i])
            return 0;
    return 1;
}

bool check1() //ABABA
{
    int i,j,z;
    for(i=1;i*3<=n;i++)
    for(j=1;i*3+j*2<=n;j++)
    {
        if(i*3+j*2 != n) continue;
        if(equ(0,i,i,i+j)) continue;
        bool flag=1;
        for(z=0;z<i;z++)
        {
            if(s[z]!=s[z+i+j] || s[z]!=s[z+i*2+j*2])
            {
                flag = 0;
                break;
            }
        }
        for(z=i;z<i+j;z++)
        {
            if(s[z]!=s[z+i+j])
            {
                flag = 0;
                break;
            }
        }
        if(flag) return 1;
    }
    return 0;
}

bool check2() // ABABCAB
{
    int i,j,k,z;
    for(i=1;i*3<=n;i++)
    for(j=1;i*3+j*3<=n;j++)
    for(k=1;i*3+j*3+k<=n;k++)
    {
        if(i*3+j*3+k!=n) continue;
        if(equ(0,i,i,i+j) || equ(0,i,i*2+j*2,i*2+j*2+k) || equ(i,i+j,i*2+j*2,i*2+j*2+k)) continue;
        bool flag = 1;
        for(z=0;z<i;z++) if(s[z]!=s[z+i+j] || s[z]!=s[z+i+j+i+j+k])
        {
            flag = 0;
            break;
        }
        for(z=i;z<i+j;z++) if(s[z]!=s[z+i+j] || s[z]!=s[z+j+i+j+k+i])
        {
            flag = 0;
            break;
        }
        if(flag) return 1;
    }
    return 0;
}

void pre()
{
    int sz = strlen(s2),i;
    n = 0;
    for(i=0;i<sz;i++)
    {
        if((s2[i]>='a' && s2[i]<='z') || (s2[i]>='A'&&s2[i]<='Z'))
            s[n++]=s2[i];
    }
    s[n]='\0';
}

void run()
{
    scanf("%s",s2);
    pre();
//    printf("%s",s);
//    cout<<check1()<<endl;
//    cout<<check2()<<endl;
    if(check1() || check2())
        puts("Yes");
    else
        puts("No");
}

int main()
{
    #ifdef LOCAL
//    freopen("case.txt","r",stdin);
    #endif
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
