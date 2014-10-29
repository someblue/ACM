#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100000;
int a[maxn],b[maxn];

 void merge(int i,int m,int n)
 {
     int j,k;
     for(j=m+1,k=i;i<=m&&j<=n;k++)
     {
         if(a[i]<=a[j]) b[k]=a[i++];
         else b[k]=a[j++];
     }
     while(i<=m) b[k++]=a[i++];
     while(j<=n) b[k++]=a[j++];
 }
 int main()
 {
     int x,i,j;
     scanf("%d",&x);
     for(i=0;i<x;i++) scanf("%d",&a[i]);
     i=2;
     do
     {
        for(j=0;j<x;j+=i)
        {
            if(j+i>=x) merge(j,(j+x-1)/2,x-1);
            else merge(j,j+(i-1)/2,j+i-1);
        }
        //printf("\n%d%d\n",j,i);
        for(j=0;j<x;j++) {a[j]=b[j];printf("%d ",a[j]);}
        putchar('\n');
        i*=2;
     }while(i<=x);
     i/=2;
     merge(0,i-1,x-1);
     for(j=0;j<x;j++) {a[j]=b[j];printf("%d ",a[j]);}
 }
