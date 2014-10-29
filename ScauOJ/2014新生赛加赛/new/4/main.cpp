#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110

using namespace std;

int all[N][N],m,n;

int dfs(int x,int y,int dx,int dy,int cnt,int color)
{
    if(x<0||x>=m||y<0||y>=n) return 0;
    if(all[x][y]==color)
    {
        cnt++;
        if(cnt>5) return color;
        else return dfs(x+dx,y+dy,dx,dy,cnt,color);
    }
    else return 0;
}

void printxy()
{
    int x,y,a,b,c,d;
    while(scanf("%d%d",&x,&y))
    {
        a=dfs(x,y,0,1,1,all[x][y]);
        b=dfs(x,y,1,1,1,all[x][y]);
        c=dfs(x,y,1,0,1,all[x][y]);
        d=dfs(x,y,1,-1,1,all[x][y]);
        printf("%d %d %d %d\n",a,b,c,d);
    }
}

int main()
{
    int t,i,j;
    int x,y,res,temp;//res:0 for no,1 for black,2 for white,3 for imposs...
    char print[4][20]={"No","Black","White","Impossible"};
    scanf("%d",&t);
    while(t--)
    {
        res=0;
        scanf("%d%d",&m,&n);
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                scanf("%1d",&all[i][j]);

//        for(i=0;i<m;i++)
//        {
//            for(j=0;j<n;j++)
//                printf("%d ",all[i][j]);
//            cout<<endl;
//        }


        for(x=0;x<m;x++)
        {
            for(y=0;y<n;y++)
            {
                if(all[x][y]==0)
                    continue;

                temp=dfs(x,y,0,1,1,all[x][y]);
                if(temp!=0)
                {
                    if(res==0) res=temp;
                    else{res=3;break;}
                }

                temp=dfs(x,y,1,1,1,all[x][y]);
                if(temp!=0)
                {
                    if(res==0) res=temp;
                    else{res=3;break;}
                }

                temp=dfs(x,y,1,0,1,all[x][y]);
                if(temp!=0)
                {
                    if(res==0) res=temp;
                    else{res=3;break;}
                }

                temp=dfs(x,y,1,-1,1,all[x][y]);
                if(temp!=0)
                {
                    if(res==0) res=temp;
                    else{res=3;break;}
                }
            }
            if(res==3) break;
        }
        printf("%s\n",print[res]);
        //printxy();
    }
    return 0;
}
