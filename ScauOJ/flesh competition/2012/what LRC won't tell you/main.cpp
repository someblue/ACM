#include <iostream>

using namespace std;

inline double f(char *s,double *v,int n)
{
    int i,p0;
    double sums=v[0];
    for(i=1;i<n;i++)
    {
        if(s[i-1]=='0')
            {p0=i;sums+=v[i];}
        else if(i-p0>7) continue;
            else sums+=v[i]/(i-p0);
    }
    return sums;
}

int main()
{
    int n,i;
    double v[110],sumv=0,sums=0;
    char s[110];
    cin>>n;
    for(i=0;i<n;i++) {cin>>v[i];sumv+=v[i];}
    cin>>s;
    cout<<"total:"<<sumv<<endl;
//    if(f(s,v,n)>=sumv/2)
//    {
//        cout<<"0>_<0!"<<endl;
//        return 0;
//    }
    for(i=0;i<n-1;i++)
    {
        if(s[i]=='0') continue;
        s[i]='0';
        sums=f(s,v,n);
        cout<<i<<":"<<sums<<endl;
        s[i]='1';
//        if(sums>=sumv/2)
//        {
//            cout<<"0>_<0!"<<endl;
//            return 0;
//        }
    }
    cout<<"POOR LRC!"<<endl;
    return 0;
}
