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
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
#define FOR3(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define REP(i,x,y) for(int i = x; i >= (int) (y) ; i--)
const int MAX16 = 65536;
const int MAX8 = 512;
const int MAXN = 200005;
//char s[MAXN][20];
LL a[MAXN];
int pre[MAX8];
LL dp[MAX16];
int n, d;
int getval(LL x)
{
    int ret = 0;
    int tmp = 1;
    while(x)
    {
        if(x % 10) ret += tmp;
        tmp *= 2;
        x /= 10;
    }
    return ret;
}
int getpre(LL x)
{
    int ret = 0;
    int tmp = 1;
    FOR(i,8)
    {
        if(x % 10) ret += tmp;
        tmp *= 2;
        x /= 10;
    }
    return ret;
}
int fj[20];
int fjtot;
void fenjie(LL x)
{
    fjtot = 0;
    while(x)
    {
        if(x % 10) fj[fjtot++] = 0;
        else fj[fjtot] = 1;
        x /= 10;
    }
}
int main()
{
    FOR(i,MAX8) pre[i] = 512 * i;
    clr(dp,0);
    scanf("%d%d",&n,&d);
    FOR(i, n) scanf("%lld", a[i]);
    LL ans = 0;
    if(d <= 8)
    {
        FOR(i,n) FOR()
    }
    FOR(i,MAX16) ans += dp[i]; ans %= MOD;
    cout << ans << endl;
}
