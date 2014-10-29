#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define MAXN 502

int w[MAXN][MAXN],match[MAXN];
int lx[MAXN],ly[MAXN],slack[MAXN];
int visitx[MAXN],visity[MAXN];
int nx,ny;

int find(int x)
{
	int i,temp;
	visitx[x]=1;
	for(i=0;i<ny;++i)
	{
		if(visity[i])
			continue;
		temp=lx[x]+ly[i]-w[x][i];
		if(temp==0)
		{
			visity[i]=1;
			if(match[i]==-1||find(match[i]))
			{
				match[i]=x;
				return 1;
			}
		}
		else if(slack[i]>temp)
		{
			slack[i]=temp;
		}
	}
	return 0;
}

int KM()
{
	int i,j,d,sum,cnt;
	memset(ly,0,sizeof(ly));
	memset(match,-1,sizeof(match));
	for(i=0;i<nx;++i)
	{//lx初始化为与它关联边中最大的
		lx[i]=w[i][0];
		for(j=1;j<ny;++j)
			if(w[i][j]>lx[i])
				lx[i]=w[i][j];
	}
	for(i=0;i<nx;++i)
	{
		for(j=0;j<ny;++j)
			slack[j]=INF;
		while(1)
		{
			memset(visitx,0,sizeof(visitx));
			memset(visity,0,sizeof(visity));
			if(find(i))
				break;
			d=INF;
			for(j=0;j<ny;++j)
			{
				if(!visity[j]&&d>slack[j])
					d=slack[j];
			}
			for(j=0;j<nx;++j)
			{
				if(visitx[j])
					lx[j]-=d;
			}
			for(j=0;j<ny;++j)
			{
				if(visity[j])
					ly[j]+=d;
				else
					slack[j]-=d;
			}
		}
	}
	sum=0;
	cnt=0;
	for(i=0;i<ny;++i)
	{
		if(match[i]==-1||w[match[i]][i]==(~INF+1))
		    continue;
		sum+=w[match[i]][i];
		cnt++;
	}
	if(cnt!=nx)//nx个学生是否都安排房间
        return -1;
	else
		return sum;
}

int main()
{
	int E,s,r,val,ans,cases=1;
	while(scanf("%d %d %d",&nx,&ny,&E)!=EOF)
	{
		for(s=0;s<=nx;++s)
		{
			for(r=0;r<=ny;++r)
				w[s][r]=(~INF+1);
		}
		if(E==0)
		{
			printf("Case %d: -1\n",cases++);
			continue;
		}
		while(E--)
		{
			scanf("%d %d %d",&s,&r,&val);
			if(val>=0)
				w[s][r]=val;
		}
		ans=KM();
		printf("Case %d: %d\n",cases++,ans);
	}
	return 0;
}
