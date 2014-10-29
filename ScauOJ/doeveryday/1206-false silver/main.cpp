#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char s[3][3][15],status[3],anseven[12],ansup[12],happen[12];

inline void init()
{
    int i;
    for(i=0;i<12;i++)
    {
        anseven[i]=ansup[i]=1;
        happen[i]=0;
    }
}

void even(char s[3][15])
{
    int i,j;
    for(i=0;i<2;i++)
        for(j=0;s[i][j]!='\0';j++)
            anseven[s[i][j]-'A']=0;
}

void up(char s[3][15])
{
    int temp[12]={0};
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;s[i][j]!='\0';j++)
        {
            temp[s[i][j]-'A']=1;
        }
    }
    for(i=0;i<12;i++)
    {
        if(!temp[i])
            ansup[i]=0;
    }
}

int printans(int ans,char s[3][15])
{
    int i,j;
    char t=ans+'A';
    for(i=0;i<2;i++)
        for(j=0;s[i][j]!='\0';j++)
            if(s[i][j]==t)
                return i;
}

void print()
{
    int i;
    printf("\teven\tup\thappen\n");
    for(i=0;i<12;i++)
    {
        printf("%c:\t%d\t%d\t%d\n",i+'A',anseven[i],ansup[i],happen[i]);
    }
}

int main()
{
    int T,i,j,k,ans;
    char temp[15],ansstring[2][7]={"heavy","light"};
    cin>>T;
    while(T--)
    {
        init();
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                cin>>s[i][j];
                for(k=0;s[i][j][k]!='\0';k++)
                    happen[s[i][j][k]-'A']=1;
            }
            //cout<<s[i][2]<<endl;
            if(strcmp(s[i][2],"even")==0)
            {
                //cout<<"even"<<endl;
                status[i]=0;
                even(s[i]);
            }
            else
            {
                //cout<<"up"<<endl;
                status[i]=1;
                if(strcmp(s[i][2],"down")==0)
                {
                    //cout<<"down"<<endl;
                    strcpy(temp,s[i][0]);
                    strcpy(s[i][0],s[i][1]);
                    strcpy(s[i][1],temp);
                }
                up(s[i]);
            }
        }
        print();
        for(i=0;i<12;i++)
            if(anseven[i]&&ansup[i]&&happen[i])
                ans=i;
        for(i=0;i<3;i++)
            if(status[i])
                printf("%c is the counterfeit coin and it is %s.\n",ans+'A',ansstring[printans(ans,s[i])]);
    }
    return 0;
}
