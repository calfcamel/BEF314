
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

int n,m;
const int MAXN = 15;
int a[MAXN][MAXN];
const int HASH = 10007;
const int STATE = 1000010;
struct HASHMAP
{
    int head[HASH],next[STATE],state[STATE],tot;
    LL dp[STATE];
    void init()
    {
        tot = 0;
        clr(head, -1);
    }
    void push(int st, LL ans)
    {
        int h = st % HASH;
        for(int i = head[h]; i != -1; i = next[i]) if(st == state[i])
        {
            dp[i] += ans;
            return;
        }
        dp[tot] = ans;
        state[tot] = st;
        next[tot] = head[h];
        head[h] = tot;
        tot++;
    }
}hm[2];
void init()
{
    scanf("%d%d",&n,&m);
    clr(a, 0);
    FOR(i,n) FOR(j,m) scanf("%d",&a[i][j]);
}
int t1,t2;
int k1,k2;
void dplock(int j, int cur)
{
    FOR(k, hm[cur].tot)
    {
        k1 = hm[cur].state[k] & (1 << j);
        k2 = hm[cur].state[k] & (2 << j);
        if(k1 + k2 == 0) hm[cur ^ 1].push(hm[cur].state[k], hm[cur].dp[k]);
    }
}
void dpblank(int j, int cur)
{
    t1 = 1 << j;
    t2 = 2 << j;
    FOR(k, hm[cur].tot)
    {
        k1 = hm[cur].state[k] & t1;
        k2 = hm[cur].state[k] & t2;
        if(k1 && k2) hm[cur ^ 1].push(hm[cur].state[k] - t1 - t2, hm[cur].dp[k]);
        else if(k1 + k2 == 0) hm[cur ^ 1].push(hm[cur].state[k] + t1 + t2, hm[cur].dp[k]);
        else
        {
            hm[cur ^ 1].push(hm[cur].state[k], hm[cur].dp[k]);
            hm[cur ^ 1].push(hm[cur].state[k] ^ t1 ^ t2, hm[cur].dp[k]);
        }
    }
}
void shift(int cur)
{
    t1 = 2 << m;
    FOR(k, hm[cur].tot) if(!(hm[cur].state[k] & t1))
    {
        hm[cur ^ 1].push(hm[cur].state[k] << 1, hm[cur].dp[k]);
    }
}
void solve()
{
    LL ans = 0;
    int cur = 0;
    hm[cur].init();
    hm[cur].push(0,1);
    FOR(i,n) FOR(j,m + 1)
    {
        hm[cur ^ 1].init();
        if(j < m)
        {
            if(a[i][j]) dpblank(j,cur);
            else dplock(j,cur);
        }
        else shift(cur);
        cur ^= 1;
    }
    FOR(i,hm[cur].tot) if(hm[cur].state[i] == 0) ans += hm[cur].dp[i];
    printf("There are %I64d ways to eat the trees.\n",ans);
}
int main()
{
    int _T;
    scanf("%d",&_T);
    FORR(CAS, _T)
    {
        init();
        printf("Case %d: ", CAS);
        solve();
    }
}
