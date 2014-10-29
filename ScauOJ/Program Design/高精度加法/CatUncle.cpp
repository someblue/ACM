#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int len = 10000;
struct bign
{
	int num[333];
	int l;//length of num
	void set0(){memset(num,0,sizeof(num));l = 1;}
	void set1(){set0();num[0] = 1;}
	friend bign operator + (bign a,bign b)
	{
		bign ret;ret.set0();
		int l = max(a.l,b.l);
		for(int i = 0;i < l;i ++)
		{
			ret.num[i] += a.num[i] + b.num[i];
			ret.num[i + 1] += ret.num[i]/len;
			ret.num[i]%=len;
		}
		if(ret.num[l])l++;
		ret.l = l;
		return ret;
	}
	void print(){
		printf("%d",num[l-1]);
		for(int i = l - 2;i >= 0;i --)
			printf("%04d",num[i]);
		puts("");
	}
};
int main()
{
  	bign a,b;
  	a.print();
 	a.set1();b.set0();
 	a.print();
 	for(int i = 0;i < 33;i ++)
 		b = b + a;
 	b.print();
 	 return 0;
}
