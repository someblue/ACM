#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
//#define VI vector<int>
#define N 5010

using namespace std;

char a[N],b[N];
int alen,ans;
int pos[N],poslen,f[N];

void clear()
{
    poslen=0;
}

inline void push_back(int k)
{
    pos[poslen++]=k;
}

inline void erase(int p)
{
    int i;
    for(i=p+1;i<poslen;i++)
        pos[i-1]=pos[i];
    poslen--;
}

void update(char oj,int difpos)
{
    int it;
    for(it=0;it!=poslen;)
    {
//        printf("*it=%d,difpos=%d\n",pos[it],difpos);
        if(pos[it]+difpos<alen && pos[it]+difpos>=0 && a[pos[it]+difpos]==oj)
        {
            if(difpos==-1) pos[it]--;
            it++;
        }
        else
        {
//            printf("before erase:%d\n",*it);
//            ans--;
//            it2=it;
//            it++;
//            pos.erase(it2);
//            printf("after erase:%d   it==end()?:%d\n",*it,it==pos.end());
//            printf("it2:after erase:%d   it==end()?:%d\n",*it2,it2==pos.end());
            ans--;
//            printf("before erase:%d\n",pos[it]);
            erase(it);
//            printf("after erase:%d   it==end()?:%d\n",pos[it],it==poslen);
        }
    }
}

void show()
{
    int i;
    for(i=0;i!=poslen;i++)
        printf("p[%d]=%d",i,pos[i]);
    cout<<endl;
}

void getFail()
{
    int m=strlen(b);
    f[0]=0;f[1]=0;
    for(int i=1;i<m;i++)
    {
        int j=f[i];
        while(j&&b[i]!=b[j]) j=f[j];
        f[i+1]=b[i] == b[j]? j+1:0;
    }
}

void find()
{
    int n=strlen(a),m=strlen(b);
    getFail();
    int j=0;
    for(int i=0;i<n;i++)
    {
        while(j && b[j]!=a[i]) j=f[j];
        if(b[j]==a[i]) j++;
        if(j==m)
        {
            push_back(i-m+1);
            i = i-m+2;
            j=0;
        }
    }
}

void findallsub()
{
    memset(f,0,sizeof(f));
    find();
    show();
}

int main()
{
    //freopen("in.txt","r",stdin);
    int first=1,m,i,j,len;
    char cmd[15],oj,tc;
    while(1)
    {
        if(first) first=0;
        else if(scanf("%c%c",&tc,&tc)==EOF) break;
        clear();ans=0;
//        gets(a);
        if(gets(a)==NULL) break;
        gets(b);
//        puts(a);
//        puts(b);
        len=strlen(b);
        alen=strlen(a);
        findallsub();
////        for(i=0;a[i]!='\0';i++)
////        {
////            for(j=0;;j++)
////            {
////                if(b[j]=='\0')
////                {
////                    push_back(i);
////                    ans++;
////                    break;
////                }
////                if(b[j]!=a[i+j] || a[i+j]=='\0') break;
////            }
////        }
////        len = strlen(b);
////        alen = strlen(a);
//        show();
        //-------------
        scanf("%d",&m);
        while(m--)
        {
//            printf("i=%d\n",m);
            scanf("%s",cmd);
//            printf("%s\n",cmd);
            if(ans==0)
            {
                if(strcmp(cmd,"Query")==0)
                    printf("0\n");
                continue;
            }
            if(strcmp(cmd,"Query")==0)
                printf("%d\n",ans);
            else
            {
                scanf("%c%c",&tc,&oj);
                if(strcmp(cmd,"Push_back")==0)
                    update(oj,len);
                else
                    update(oj,-1);
                len++;
//                show();
            }
        }
        //printf("\n");
    }
    return 0;
}
