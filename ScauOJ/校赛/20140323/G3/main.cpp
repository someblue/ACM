#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#define VI vector<int>
#define N 5010

using namespace std;

char a[N],b[N];
int alen,ans;
VI pos;

void update(char oj,int difpos)
{
    VI::iterator it,it2;
    for(it=pos.begin();it!=pos.end();)
    {
//        printf("*it=%d,difpos=%d\n",*it,difpos);
        if(*it+difpos<alen && *it+difpos>=0 && a[*it+difpos]==oj)
        {
            if(difpos==-1) *it--;
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
//            printf("before erase:%d\n",*it);
            pos.erase(it);
//            printf("after erase:%d   it==end()?:%d\n",*it,it==pos.end());
        }
    }
}

void show()
{
    VI::iterator it;
    int i=0;
    for(it=pos.begin();it!=pos.end();it++)
        cout<<"pos["<<i++<<"]=="<<*it<<' ';
    cout<<endl;
}

int main()
{
    int first=1,m,i,j,len,dlen;
    char cmd[15],oj,tc;
    while(1)
    {
        if(first) first=0;
        else scanf("%c%c",&tc,&tc);
        if(gets(a)==NULL) break;
        pos.clear();ans=0;
        gets(a);
        gets(b);
        len = strlen(b);
        alen = strlen(a);
        dlen = alen - len + 1;
        //findallsub();
        for(i=0;i<dlen;i++)
        {
            for(j=0;;j++)
            {
                if(b[j]=='\0')
                {
                    pos.push_back(i);
                    ans++;
                    break;
                }
                if(b[j]!=a[i+j]) break;
            }
        }
//        show();
        //-------------
        scanf("%d",&m);
        while(m--)
        {
            //printf("i=%d\n",m);
            scanf("%s",cmd);
            //printf("%s\n",cmd);
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
    }
    return 0;
}
