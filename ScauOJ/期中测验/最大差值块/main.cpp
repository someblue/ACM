#include <iostream>
#include <cstdio>

using namespace std;

int num[11][11];

double max(double a,double b)
{
    return a>b?a:b;
}

double delta(int si,int sj,int ei,int ej)
{
    double aver,min=num[si][sj],sum=0;
    int i,j;
    for(i=si;i<=ei;i++)
        for(j=sj;j<=ej;j++)
        {
            sum+=num[i][j];
            if(min>num[i][j])
                min=num[i][j];
        }
    aver=sum/((ei-si+1)*(ej-sj+1));
    return aver-min;
}

int main()
{
    int n,i,j;
    int si,sj,ei,ej;
    double ans=0;
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>num[i][j];
    for(si=0;si<n;si++)
        for(sj=0;sj<n;sj++)
        {
            for(ei=si;ei<n;ei++)
                for(ej=sj;ej<n;ej++)
                    ans=max(ans,delta(si,sj,ei,ej));
        }
    printf("%.2lf\n",ans);
    return 0;
}
