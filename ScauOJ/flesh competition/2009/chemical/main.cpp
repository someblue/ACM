#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    freopen("case.txt","r",stdin);
    int T,num[128],len,i,t,p1,p2;
    char s[110];
    double sum,m[128];
    m['C']=12.01;m['H']=1.008;m['O']=16.00;m['N']=14.01;
    cin>>T;
    while(T--)
    {
        sum=0;
        memset(num,0,sizeof(num));
        cin>>s;
        len=strlen(s);
        if(isalpha(s[len-1]))
            {s[len++]='1';}
        s[len++]='a';s[len]='\0';
        //cout<<s<<endl;
        p1=0;p2=0;
        while(++p2<len)
        {
            if(isalpha(s[p2]))
            {
                //cout<<p2<<' ';
                if(p2-p1==1) {num[s[p1]]++;p1=p2;}
                else
                {
                    t=0;
                    for(i=p1+1;i<p2;i++)
                    {
                        t=t*10+s[i]-'0';
                    }
                    num[s[p1]]+=t;
                    p1=p2;
                }
            }
            //cout<<'.';
        }
        //cout<<"C:"<<num['C']<<",H:"<<num['H']<<",O:"<<num['O']<<",N:"<<num['N']<<endl;
        double ans=num['C']*m['C']+num['H']*m['H']+num['O']*m['O']+num['N']*m['N'];
        printf("%.3lf\n",ans);
    }
    return 0;
}
