#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;
const int N = 1000005;

char s[N];
int l;
int minidx,minnum;
int maxidx,maxnum;

void MinimumRepresentation()
{
    minidx = -1;
    minnum = 0;
    int i = 0, j = 1, k = 0, t;
    while(i < l && j < l) {
        t = s[(i + k) >= l ? i + k - l : i + k] - s[(j + k) >= l ? j + k - l : j + k];
        if(!t) k++;
        else{
            if(t > 0) i = i + k + 1;
            else j = j + k + 1;
            if(i == j) ++ j;
            k = 0;
        }
        if(k>=l)
        {
            if(minidx == -1)    minidx = (i < j ? i : j);
            ++minnum;
            if(i<j) ++i,j=i+1;
            else    ++j,i=j,++j;
            k=0;
        }
    }
    if(minidx == -1)
    {
        minidx = (i < j ? i : j);
    }
    ++minnum;
}

void MaximumRepresentation()
{
    maxidx = -1;
    maxnum = 0;
    int i = 0, j = 1, k = 0, t;
    while(i < l && j < l) {
        t = s[(i + k) >= l ? i + k - l : i + k] - s[(j + k) >= l ? j + k - l : j + k];
        if(!t) k++;
        else{
            if(t < 0) i = i + k + 1;
            else j = j + k + 1;
            if(i == j) ++ j;
            k = 0;
        }
        if(k>=l)
        {
            if(maxidx == -1)    maxidx = (i < j ? i : j);
            ++maxnum;
            if(i<j) ++i,j=i+1;
            else    ++j,i=j,++j;
            k=0;
        }
    }
    if(maxidx == -1)
    {
        maxidx = (i < j ? i : j);
    }
    ++maxnum;
}

void run()
{
    l = strlen(s);
    MinimumRepresentation();
    MaximumRepresentation();
    printf("%d %d %d %d\n",minidx+1,minnum,maxidx+1,maxnum);
}

int main()
{
    while(scanf("%s",s)!=EOF)
        run();
    return 0;
}
