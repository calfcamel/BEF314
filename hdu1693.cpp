
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
const int MAXN = 12;
int a[MAXN][MAXN];
LL dp[2][1 << MAXN];
int main()
{
    int _T;
    scanf("%d",&_T);
    FORR(CAS, _T)
    {
        scanf("%d%d",&n,&m);
        FOR(i,n) FOR(j,m) scanf("%d",&a[i][j]);
        clr(dp,0);
        int cur = 0;
        dp[0][0] = 1;
        int nxt = 1;
        int t1,t2;
        int k1,k2;
        FOR(i,n) FOR(j,m + 1)
        {
            clr(dp[nxt], 0);
            if(j < m)
            {
                t1 = 1 << j;
                t2 = 2 << j;
                if(a[i][j]) FOR(mask, 2 << m)
                {
                    k1 = mask & t1;
                    k2 = mask & t2;
                    if(k1 && k2) dp[nxt][mask - t1 - t2] += dp[cur][mask];
                    else if(k1 + k2 == 0) dp[nxt][mask + t1 + t2] += dp[cur][mask];
                    else
                    {
                        dp[nxt][mask] += dp[cur][mask];
                        dp[nxt][mask^t1^t2] += dp[cur][mask];
                    }
                }
                if(!a[i][j]) FOR(mask, 2 << m)
                {
                    if((mask & t1) + (mask & t2) == 0) dp[nxt][mask] += dp[cur][mask];
                }
            }
            else
            {
                t2 = 1 << j;
                FOR(mask, 2 << m) if(!(mask & t2))
                {
                    dp[nxt][mask << 1] += dp[cur][mask];
                }
            }
            swap(cur, nxt);
        }
        printf("Case %d: There are %I64d ways to eat the trees.\n", CAS, dp[0][0]);
    }
}
