#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
typedef long long LL;
//#pragma comment(linker, "/STACK:102400000,102400000")
#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define MP make_pair
#define AA first
#define BB second
#define PB push_back
#define SZ size()
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
///======GET INV===============================
const int N = 100005;
LL inv[N];
void init()
{
    inv[0] = inv[1] = 1;
    for(int i = 2; i < N; i++)
        inv[i] = ((MOD - MOD / i) * inv[MOD % i]) % MOD;
}
LL Exgcd(LL a,LL b,LL &x,LL &y){
    LL r,t;
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    r=Exgcd(b,a%b,x,y);
    t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
LL getinv(LL a)
{
    if(a < N) return inv[a];
    LL x,y;
    Exgcd(a,MOD,x,y);
    return (x % MOD + MOD) % MOD;
}
///============================================
const int MAXN = 10000 + 5;

int main()
{
    init();
    int _T;
    scanf("%d", &_T);
    LL b1,q,a1,d,n,m;
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&b1,&q,&a1,&d,&n,&m);
        b1 %= MOD;
        a1 %= MOD;
        q %= MOD;
        d %= MOD;
        LL ans = 0;
        for(int i = 1; i < n; i++)
            a1 = (a1 + d) % MOD;
        //cout << "a1 = " << a1 << endl;
        d = MOD - d;
        LL now = 1;
        LL j = m - 1;
        LL i = m - 1;
        for(LL l = 1; l <= n; l++)
        {
            ans = (ans + now * a1 % MOD) % MOD;
            now = now * (i + 1LL) % MOD * getinv(i + 1LL - j) % MOD;
            i++;
            a1 = (a1 + d) % MOD;
        }
        //cout << "ans = " << ans << endl;
        for(int i = 1; i < m; i++)
            b1 = b1 * q % MOD;
        q = getinv(q);
        //cout << "bn = " << b1 << endl;
        now = 1;
        j = n - 1;
        i = n - 1;
        for(LL l = 1; l <= m; l++)
        {
            ans = (ans + now * b1 % MOD) % MOD;
            now = now * (i + 1LL) % MOD * getinv(i + 1LL - j) % MOD;
            cout << i + 1LL << " inv[" <<i + 1LL - j << "] = " << getinv(i + 1LL - j) << endl;
            i++;
            b1 = b1 * q % MOD;
            //cout << "now = " << now <<" bi = " << b1 << endl;
        }
        printf("Case #%d: %I64d\n",CAS,ans);
    }
    return 0;
}
