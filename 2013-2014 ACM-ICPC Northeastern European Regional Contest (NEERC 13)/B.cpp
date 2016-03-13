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

const int MAXN = 100000 + 5;

//GYM
//#define ONLINE_JUDGE
LL n,a,b;
double dp[3055][3055];
int vis[3055][3055];
double getdp1(double k, LL x, LL y)
{
    if(x < 1) return 0;
    if(y < 0) return 0;
    if(vis[a - x + 1][b - y + 1]) return k * dp[a - x + 1][b - y + 1];
    double ret;
    double k1 = 2.0 * (double)(x - 1) / (double)(2 * x + y);
    double k2 = (double)y / (double)(2 * x + y);
    if(x + y + n == a + b + 1 + 1)
    {
        ret = 2.0 / (double)(2 * x + y);
    }
    else
    {
        ret = getdp1(k2, x, y - 1) + 2.0 / (double)(2 * x + y);
        if(x > 1) ret += getdp1(k1, x - 1, y);
    }
    dp[a - x + 1][b - y + 1] = ret;
    vis[a - x + 1][b - y + 1] = 1;
    return ret * k;
}
double getdp2(double k, LL x, LL y)
{
    if(x < 0) return 0;
    if(y < 1) return 0;
    if(vis[a - x + 1][b - y + 1]) return k * dp[a - x + 1][b - y + 1];
    double ret;
    double k1 = 2.0 * (double)x / (double)(2 * x + y);
    double k2 = (double)(y - 1) / (double)(2 * x + y);
    if(x + y + n == a + b + 1 + 1)
    {
        ret = 1.0 / (double)(2 * x + y);
    }
    else
    {
        ret = getdp2(k1, x - 1, y) + 1.0 / (double)(2 * x + y);
        if(y > 1) ret += getdp2(k2, x, y - 1);
    }
    dp[a - x + 1][b - y + 1] = ret;
    vis[a - x + 1][b - y + 1] = 1;
    return ret * k;
}
int main()
{
    #ifdef ONLINE_JUDGE
        freopen("bonus.in","r",stdin);
        freopen("bonus.out","w",stdout);
    #endif // ONLINE_JUDGE
    scanf("%I64d%I64d%I64d",&n,&a,&b);
    double ans1;
    double ans2;
    if(n >= a + b + 1)
    {
        ans1 = 1.0;
        ans2 = 1.0;
    }
    else
    {
        clr(dp,0);
        clr(vis,0);
        ans1 = getdp1(1,a + 1,b);
        clr(dp,0);
        clr(vis,0);
        ans2 = getdp2(1,a,b + 1);
    }
    printf("%.10lf\n",ans1);
    printf("%.10lf\n",ans2);
}
