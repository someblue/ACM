#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
//    char c1,c2,decode;
//    c1=getchar();
//    decode=c1;
//    while((c2=getchar())!=EOF)
//    {
//        cout<<decode;
//        if(c2<c1)
//            decode=c2-c1+128;
//        else
//            decode=c2-c1+32;
//        c1=c2;
//    }
//
    char s[10001],de[10001];
    scanf("%s",s);
    int i,len;
    len=strlen(s);
    de[0]=s[0];
    for(i=1;i<len;i++)
    {
        if(s[i]<s[i-1])
            de[i]=s[i]-s[i-1]+128;
        else
            de[i]=s[i]-s[i-1]+32;
    }
    de[i]='\0';
    printf("%s",de);
    return 0;
}
//W<(tXG5z&m\K/

//     标准输入数据:
//R7z_MA-&&lM?,qcc%nZFF.obbH7,z^^QF)qqT=/r^C66%ss[D77%nQ66(mPD%sZO;|nneM2sggM6{gKYY{dP<<(q\A44uaMM:3&z_Q:)~qqeM6$k^^T9+$$qfI1==0gLL4uhhL1t]A&
//
//
//标准输出答案:
//   1|Recently farmer Bill has found such circles on his nice rectangular wheat field. Bill likes all mysterious things very much, so he has decide
//
//
//你的错误输出结果:
//   1|Recently farmer Bill has found such circles on his nice rectangular wheat field. Bill likes all mysterious things very much, so he has decid
//
//
