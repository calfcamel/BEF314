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
const int MAXN = 105;
const int MAX20 = 1 << 20;
const int MAX10 = 1 << 10;
int dp[MAXN][MAXN][MAXN];
int a[MAXN];
char s[20];
int tot;
int mask[MAX10];
int n,m;
//const int mov[10] = {0,2,4,6,8,10,12,14,16,18};
//inline int get(int x, int i)
//{
//    return (x >> mov[i]) && 3;
//}
//inline int modify(int x,int i, int y)
//{
//    x &= ~(3 << mov[i]);
//    return x | (y << mov[i]);
//}
//inline int down(int x)
//{
//    FOR(i,m) if(get(x,i)) x = modify(x,i,get(x,i) - 1);
//    return x;
//}
//inline int hebing(int x,int y) // y is transfer
//{
//    x = down(x);
//    FOR(i,m) if(y & (1 << i)) x = modify(x, i, 2);
//    return x;
//}
//inline int getplace(int x)
//{
//    int ret = 0;
//    FOR(i,m) if(get(x,i)) ret += 1 << i;
//    return ret;
//}
bool hefa(int x)
{
    int t = 3;
    FOR(i,10) if((x & (t << i)) == (t << i)) return false;
    t = 5;
    FOR(i,10) if((x & (t << i)) == (t << i)) return false;
    return true;
}
bool chk(int i, int j, int k)
{
    if(mask[i] & mask[j]) return false;
    if(mask[k] & mask[j]) return false;
    if(mask[i] & mask[k]) return false;
    return true;
}
int main()
{
    tot = 0;
    scanf("%d%d",&n,&m);
    FOR(now, 1 << m) if(hefa(now)) mask[tot++] = now;
//    dbg(tot);
    FOR(i,n)
    {
        int tmp = 0;
        scanf("%s",s);
        FOR(j,m) if(s[j] == 'P')tmp += 1 << j;
        a[i + 1] = tmp;
    }
//    FORR(i,n) dbg(a[i]);
//    int cur = 0;
//    int nxt = 1;
    clr(dp,0);
//    __builtin_popcount(x);
    FORR(i,n) FOR(now,tot) if((mask[now] | a[i]) == a[i]) FOR(j,tot) FOR(k,tot) if(chk(j,k,now))
    {
        cmax(dp[i][k][now], dp[i - 1][j][k] + __builtin_popcount(mask[now]));
    }
    int ans = 0;
    FOR(j,tot) FOR(k,tot) cmax(ans,dp[n][j][k]);
    cout << ans << endl;
}
