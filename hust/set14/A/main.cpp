#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;

int MinimumRepresentation(char *s, int l)
{
    int i = 0, j = 1, k = 0, t;
    while(i < l && j < l && k < l) {
        t = s[(i + k) >= l ? i + k - l : i + k] - s[(j + k) >= l ? j + k - l : j + k];
        if(!t) k++;
        else{
            if(t > 0) i = i + k + 1;
            else j = j + k + 1;
            if(i == j) ++ j;
            k = 0;
        }
    }
    return (i < j ? i : j);
}

set<string> ms;
char s[210];
int n;

void run()
{
    int idx,len;
    ms.clear();
    while(n--)
    {
        scanf("%s",s);
        len = strlen(s);
        idx = MinimumRepresentation(s,len);
        ms.insert(string(s+idx)+string(s,idx));
    }
    printf("%d\n",ms.size());
}

int main()
{
    while(scanf("%d",&n)!=EOF)
        run();
    return 0;
}
