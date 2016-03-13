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
#define FOR(i,x) for(int i = 0 ; i < (int)(x) ; i ++)
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;

const int inf = 0x7F;
const int MAXN = 100000 + 5;
struct{int d,f;}a[18][18];
void display_mid(int i, int j)
{
    if(a[i][j].f == -1) return;
    display_mid(i,a[i][j].f);
    printf(" %d",a[i][j].f);
    display_mid(a[i][j].f,j);
}
void display_path(int i, int j)
{
    printf("%d",i);
    display_mid(i,j);
    printf(" %d",j);
}
int bc[1 << 18];
int dp[1 << 18][18];
int p[1 << 18][18];
struct{int t, i;}t[1 << 18];
struct{int mask, i;}ans1,ans2;
vector<int> bit[18];
int main()
{
    FOR(i,18) bit[i].clear();
    FOR(mask, 1 << 18) bc[mask] = __builtin_popcount(mask);
    FOR(mask, 1 << 18) bit[bc[mask]].push_back(mask);
    int n,m;
    scanf("%d%d",&n,&m);
    FOR(i,18) FOR(j,18) a[i][j].d = 200000;
    FOR(i,18) FOR(j,18) a[i][j].f = -1;
    int x,y,z;
    FOR(i,m)
    {
        scanf("%d%d%d",&x,&y,&z);
        a[x - 1][y - 1].d = z;
        a[y - 1][x - 1].d = z;
    }
    FOR(k,n) FOR(i,n) FOR(j,n)
    {
        if(a[i][j].d >= a[i][k].d + a[k][j].d)
        {
            a[i][j].d = a[i][k].d + a[k][j].d;
            a[i][j].f = k;
        }
    }
    clr(dp, inf);
    clr(p, -1);
    dp[0][0] = 0;
    int mask;
    FOR(l,n)
    {
        FOR(mm, bit[l].size()) FOR(i,n) if(dp[mask = bit[l][mm]][i] != inf)
        {
            FOR(j, n) if(!(mask & 1 << j) && dp[mask | 1 << j][j] < dp[mask][i] + a[i][j].d)
            {
                dp[mask | 1 << j][j] = dp[mask][i] + a[i][j].d;
                p[mask | 1 << j][j] = i;
            }
        }
    }
    FOR(mask, 1 << 18) t[mask].t = inf;
    int ans = inf;
    FOR(mask, 1 << n) FOR(i, n)
    {
        if(t[mask].t > dp[mask][i])
        {
            t[mask].t = dp[mask][i];
            t[mask].i = i;
        }
    }
    return 0;
}
