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
#define dbg(x) cerr <<#x<<" = " << x << endl
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define REP(i,x,y) for(int i = (int)(x); i <= (int)(y); i++)
#define REPP(i,x,y) for(int i = (int)(x); i <= (int)(y); i--)
#define all(x) x.begin(),x.end()
const int MAXN = 100000 + 5;

int c[11];
int s[11];
LL dp[11][101][101];
LL inv[MAXN];
LL fac[MAXN];

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
void init()
{
    fac[0] = 1;
    REP(i,1,100000) fac[i] = fac[i - 1] * (LL) i % MOD;
    REP(i,0,100000) inv[i] = getinv(fac[i]);
}
LL C(LL n, LL m)
{
    LL ret = 1;
    if(m <= n)ret = fac[n] * inv[m] % MOD * inv[n - m] % MOD;
//    cout << "\tGET C " << n << " " << m << " : " << ret << endl;
    return max(ret,1LL);
}
int main()
{
    init();
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        LL ans = 0;
        clr(dp,-1);
        dp[0][0][0] = 1;
        int n,m,t;
        scanf("%d%d%d",&n,&m,&t);
        n = n;
        REP(i,1,m) scanf("%d",&c[i]);
        s[0] = 0;
        REP(i,1,m) s[i] = s[i - 1] + c[i];
        LL leftn = 0;
        REP(i,1,m) REP(j,0,t) REP(k,0,j) if(dp[i - 1][j][k] != -1)
        {
            leftn = n + 2 * j - k - s[i - 1] - 2 * t;
            REP(addj,0,t - j)
            {
                if(addj > c[i]) break;
                REP(deck,0,addj + k) if(addj + deck <= c[i] && leftn + addj + deck >= c[i])
                {
                    if(dp[i][j + addj][k + addj - deck] == -1) dp[i][j + addj][k + addj - deck] = 0;
                    dp[i][j + addj][k + addj - deck] = (
                                                          dp[i][j + addj][k + addj - deck]
                                                        + dp[i - 1][j][k] * C(leftn, c[i] - addj - deck) % MOD
                                                                          * C(t - j, addj) % MOD
                                                                          * C(addj + k, deck) % MOD
                                                       ) % MOD;
//                    cout << i - 1 << " " << j << " " << k << " " << addj << " " << deck << " " << leftn << endl;
//                    cout << "NOW " << dp[i -1][j][k] << " " << endl;
//                    cout << "UPDATE " << i << " " << j + addj << " " << k + addj - deck << " : " << dp[i][j + addj][k + addj - deck] << endl;
                }
            }
        }
        printf("Case #%d: %lld\n",CAS,dp[m][t][0]);
    }
    return 0;
}
