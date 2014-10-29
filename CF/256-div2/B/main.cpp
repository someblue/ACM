#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#define N 110
using namespace std;
const int INF=1<<30;
const double eps=1e-6;
string s1,s2;
int vis1[30],vis2[30];

char anss[][20]={"need tree","automaton","array","both"};

bool substring(string &s1,string &s2)
{
    int len1=s1.length(),len2=s2.length();
    int i,j;
    for(i=0,j=0;i<len1;++i)
    {
        if(s1[i]==s2[j])
        {
            ++j;
            if(j==len2) return 1;
        }
    }
    return 0;
}

int main()
{
    cin>>s1>>s2;
    int ans=0;
    int i;
    for(i=0;i<s1.length();i++)
        vis1[s1[i]-'a']++;
    for(i=0;i<s2.length();i++)
        vis2[s2[i]-'a']++;
    for(i=0;i<26;i++)
        if(vis2[i]>vis1[i])
        {
            ans=0;
            goto gt;
        }
    if(s1.length()==s2.length())    {ans=2;goto gt;}
//    if(s1.find(s2)!=string::npos)   {ans=1;goto gt;}
    if(substring(s1,s2))            {ans=1;goto gt;}
    ans=3;
gt:
    cout<<anss[ans]<<endl;
    return 0;
}
