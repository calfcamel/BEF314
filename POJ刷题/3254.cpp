#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
//#include <unordered_map>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <assert.h>
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
#define all(x) x.begin(), x.end()
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<LL, LL> PII;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int MAXN = 2005;
const int MAX12 = 1 << 12;
const LL mod = 100000000;
int n,m;
LL dp[2][MAX12];
int a[13];
bool chk(int now)
{
    int x = 3;
    FOR(i,10) if((now & (x << i)) == (x << i)) return false;
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    FOR(i,n)
    {
        int tmp = 0;
        int x;
        FOR(i,m)
        {
            scanf("%d",&x);
            tmp += x << i;
        }
        a[i] = tmp;
    }
//    FOR(i,n) dbg(a[i]);
    clr(dp,0);
    dp[0][0] = 1;
    int cur = 0;
    int nxt = 1;
    FOR(i,n)
    {
        clr(dp[nxt],0);
        FOR(mask, MAX12) if(dp[mask]) FOR(now, MAX12) if((mask & now) == 0 && (now | a[i]) == a[i] && chk(now))
        {
            dp[nxt][now] += dp[cur][mask];
            dp[nxt][now] %= mod;
        }
//        cout << "DP " << i << endl;
//        FOR(mask, MAX12) if(dp[nxt][mask]) cout << mask << " = " << dp[nxt][mask] << endl;
        swap(cur,nxt);
    }
    LL ans = 0;
    FOR(mask, MAX12) ans = (ans + dp[cur][mask]) % mod;
    cout << ans << endl;
}
