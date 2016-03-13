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
#include <iomanip>
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
#define REP(i,x,y) for(int i = x,  _END_ = (int)(y); i <= _END_ ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int N = 2016;
LL inv[N];
LL C[N];
LL dp[N][N];
void init()
{
    inv[0] = inv[1] = 1;
    for(int i = 2; i < N; i++)
        inv[i] = ((MOD - MOD / i) * inv[MOD % i]) % MOD;
    C[0] = 1;
    for(int i = 0; i < 2008; i++)
        C[i + 1] = C[i] * (4 * i + 2) % MOD * inv[i + 2] % MOD;
    clr(dp,0);
    FOR(i,N)
    {
        FOR(j,i + 1)
        {
            if(j) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            else dp[i][j] = 1;
        }
    }
    FOR(i,10)
    {
        FOR(j,10) cout << dp[i][j] << " ";cout << endl;
    }
}
int n,m;
char s[100005];
int x,y;
LL cal1(int x, int y)
{
    if(x < 0 || y < 0) return 0;
    return dp[x][y];
//    cout << "CAL LEFT " << x << " " << y << endl;
    if(x < y) return 0;
    if(x < 0 || y < 0) return 0;
    y = x - y;
    LL ret = C[x];
    y /= 2;
    if(y) ret -= C[y];
//    cout << "\t = " << ret << endl;
    return ret;
}
LL cal2(int x, int y)
{
//    cout << "CAL RIGHT " << x << " " << y << endl;
    swap(x,y);
    if(x < 0 || y < 0) return 0;
    return dp[x][y];
    if(x < y) return 0;
    if(x < 0 || y < 0) return 0;
    y = x - y;
    LL ret = C[x];
    y /= 2;
    if(y) ret -= C[y];
//    cout << "\t = " << ret << endl;
    return ret;
}
int main()
{
    init();
//    dbg(cal1(10,0));
    scanf("%d%d",&n,&m);
    if(n & 1)
    {
        puts("0");
        return 0;
    }
    scanf("%s",s);
    x = 0;
    y = 0;
    FOR(i,m) if(s[i] == '(') x++; else y++;
    int now = 0;
    int must = 0;
    FOR(i,m)
    {
        if(s[i] == '(') now++;
        else now--;
        cmin(must, now);
    }
    must = -must;
    int r;
    LL ans = 0;
    int y1,x2,y2;
    REP(l,max(0,must),n - m)
    {
        r = n - m - l;
        REP(x1,max(0, must), min(n / 2 - x, l))
        {
            y1 = l - x1;
            x2 = n / 2 - x1 - x;
            y2 = n / 2 - y1 - y;
            ans = (ans + cal1(x1,y1) * cal2(x2, y2)) % MOD;
        }
    }
    cout << ans << endl;
}
