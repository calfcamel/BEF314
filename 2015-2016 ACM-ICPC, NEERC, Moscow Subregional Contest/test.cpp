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
#include <cassert>
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
#define dbg(x) cerr <<#x<<" = " << x << endl
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)

const int MAXN = 18 + 1;
const int MAXM = 262144 + 1;
LL C[MAXN][MAXM];
LL a[MAXM];
LL b[MAXN];
LL bj[MAXN];
LL f[MAXM];
LL finv[MAXM];
const int N = MAXM;
LL inv[N];
void initinv()
{
    inv[0] = inv[1] = 1;
    for(LL i = 2; i < N; i++)
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

LL getinv(LL a,LL M = MOD)
{
    LL x,y;
    Exgcd(a,M,x,y);
    return (x % MOD + MOD) % MOD;
}
LL C2[MAXM];
LL mulans[MAXN];
void initans()
{
    clr(C2,0);
    for(LL i = 2; i < MAXM; i++)
    {
        C2[i] = i * (i - 1LL) % MOD * inv[2] % MOD;
    }
    for(LL l = 1; l <= 18; l++)
    {
        LL tmp = 1;
        for(LL i = 1; i <= b[l]; i++)
            if(i % 2LL == 0)tmp = tmp * C2[i] % MOD;
        mulans[l] = f[b[l]] * getinv(tmp) % MOD * f[b[l - 1]] % MOD;
    }
//    for(int i = 1; i <= 18; i++)
//        cout << mulans[i] << endl;
}
void init()
{
    initinv();
    b[0] = 1;
    for(LL i = 1; i <= 18; i++) b[i] = b[i - 1] * 2LL % MOD;
    for(LL i = 0; i <= 18; i++) bj[i] = (b[i] - 1 + MOD) % MOD;
    f[0] = 1;
    for(LL i = 1; i <= MAXM; i++) f[i] = f[i - 1] * i % MOD;
    for(LL i = 0; i <= MAXM; i++) finv[i] = getinv(f[i]);
    LL tmp;
    clr(C,0);
    LL j;
    for(LL l = 0; l <= 18; l++)
    {
        tmp = 1;
        C[l][bj[l]] = 1;
        for(LL i = bj[l] + 1; i < MAXM; i++)
        {
            C[l][i] = C[l][i - 1] * i % MOD * inv[i - bj[l]] % MOD;
        }
    }
    initans();
}
LL powmod(LL a,LL b)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1LL;
    }
    return ret;
}
LL getf(LL x)
{
    LL ret = 1;
    for(LL i = 1; i <= x; i++)
        ret = ret * i % MOD;
    return ret;
}
int main()
{
    init();
    LL n;
    scanf("%I64d",&n);
//    assert(n <= 2);
    for(LL i = 1; i <= b[n]; i++)
        scanf("%I64d",&a[i]);
    reverse(a + 1, a + 1 + b[n]);
    LL ans = 0;
    LL sum = 0;
//    for(int l = 1; l <= 1; l++)
//    {
//        sum = 0;
//        for(LL i = 1; i <= b[n]; i++)
//        {
//            if(i != 1LL)
//            {
//                ans = (ans + sum * a[i] % MOD) % MOD;
//                cout << "AD " << sum * a[i] % MOD << endl;
//            }
//            sum = (sum + a[i] % MOD) % MOD;
//        }
//    }
    for(LL l = 1; l <= n; l++)
    {
        sum = 0;
        for(LL i = b[l - 1]; i <= b[n]; i++)
        {
            if(i >= b[l])
            {
                ans = (ans + sum * C[l - 1][i - b[l - 1] - 1LL] % MOD * a[i] % MOD) % MOD;
                cout << "ADD " << sum * C[l - 1][i - b[l - 1] - 1LL] % MOD * a[i] % MOD << " " << b[n - l + 1] % MOD << endl;
            }
            sum = (sum + a[i] * C[l - 1][i - 1LL] % MOD) % MOD;
        }
        cout << endl;
//        // init
//        for(int i = b[l]; i <= n; i++)
//            sum[i] = (sum[i - 1] + a[i] * C[i - 1][l - 1]) % MOD;
//        // add
//        for(int i = bj[])
    }
    //powmod(2LL,(n * n + n) / 2)
    cout << "YANS = " << ans << endl;
    ans = ans * mulans[n] % MOD * finv[b[n]] % MOD;
    cout << ans << endl;
}

