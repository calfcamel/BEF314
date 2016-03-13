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
typedef pair<int, int> PII;
#define FOR(i,x) for(int i = 0, _END_ = (int)(x); i < _END_ ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
int n,m;
LL ans[13][13];
vector<PII> v;
void dfs(int l, int pre, int now)
{
    if(l > m) return;
    if(l == m)
    {
        v.PB(MP(pre,now));
        return;
    }
    dfs(l + 2, pre << 2, now << 2);
    dfs(l + 1, (pre << 1) | 1, now << 1);
    dfs(l + 1, pre << 1, (now << 1) | 1);
}
LL dp[2][1 << 12];
int main()
{
    clr(ans,0);
    for(int i = 2; i <= 11; i += 2)
    {
        v.clear();
        m = i;
        dfs(0,0,0);
        int cur = 0;
        int nxt = 1;
        FOR(k,1 << i) dp[cur][k] = 0;
        dp[cur][0] = 1;
        int ed = 0;
        FORR(j,11)
        {
            FOR(k,1 << i) dp[nxt][k] = 0;
            FOR(k,v.SZ) dp[nxt][v[k].BB] += dp[cur][v[k].AA];
            swap(cur, nxt);
            ans[i][j] = dp[cur][ed];
            ans[j][i] = dp[cur][ed];
        }
    }
    while(scanf("%d%d",&n,&m),n)
    {
        printf("%I64d\n",ans[n][m]);
    }
}
