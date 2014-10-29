#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
const int N = 100010;

char p[N];
LL len,c[N];

void init(){ memset( c, 0 ,sizeof c); }
int lowbit(int x){return x&-x;}
void update(int pos ,LL key ){while( pos <= len+1 ){c[pos]+= key ; pos += lowbit(pos);}}
LL query(int pos ){if(pos==0) return 0; LL res = 0 ; while( pos > 0 ) { res += c[pos] ; res %= MOD; pos -= lowbit(pos ); }return res; }
//----------------------------------------------------


LL solve(LL x,LL y)
{
    LL xx = x % len , yy = y % len;
    LL posx = x / len ;LL posy = y / len ;
    if( xx ) posx ++; if( yy ) posy ++;                   //�ڵڼ���ѭ����

    if( xx == 0)xx = len;
    if( yy == 0)yy = len;

    LL res = 0 ;


    if( y - x < len && xx <= yy ){                      //��ͬѭ����
        res = query(yy) - query(xx-1);
        if(xx%2 == 0 ) res = -res ;
        return res;
    }

    LL sum  = query( len );

    if( len % 2 == 0 ) {                            //ѭ���ڳ���Ϊż�������ϵ���
            res += sum * ( yy - xx - 1LL ) % MOD;   // ( yy-xx -1)��ʾx . y ֮��ѭ���ڵĸ���
            res %= MOD;
    }
    else {                                           //ѭ���ڳ���Ϊ���������ϵ���
        if( ( yy - xx - 1LL ) % 2 == 0 )               //x . y ֮��ѭ���ڵĸ���Ϊ����Ҫ���һ��
            res += sum;
            res %= MOD;
    }

    LL tou = 0 , wei = 0 ;

    tou  = query ( len ) - query(xx) ;
    wei  = query ( len ) - query(yy) ;

    res = (res + tou )%MOD;
    res = (res + wei )%MOD;
    if( xx % 2 == 0 )                             //x��λ�ô�ż��λ�ÿ�ʼ �����ȡ��
        res = -res;

    return res ;
}

void run()
{
    int q,op;
    LL x,y;

    init();

    scanf("%s",p);
    len = strlen(p);


    for(int i = 0 ; i < len ; ++i ){
        int num = p[i]-'0';
        if( i%2 ) num = -num;
        update(i+1,num);
    }


    scanf("%d",&q);
    while(q--){
        scanf("%d%lld%lld",&op,&x,&y);

        if(op==1 ){
            int pre_num = query(x) - query(x-1);
            update(x,-pre_num);

            if(x%2==0)y = -y;
            update(x,y);
        }

        else
        {
            printf("%lld\n",solve(x,y));
        }
    }
}
int main()
{
    #ifdef LOCAL
//        freopen("in.txt","r",stdin);
    #endif // LOCAL

//    ios::sync_with_stdio(0);
    int cas=1, _;
    scanf("%d",&_);
    while(_--){
        run();
    }
    return 0;
}

