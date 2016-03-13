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
const int MAXINT = 0x3FFFFFFF; // INF / 2
const int MAXN = 100000 + 5;
priority_queue<LL> q;
char s[MAXN];
int a[MAXN];
int dp[MAXN][2][3];
int main()
{
    int n;
    scanf("%d%s",&n,s + 1);
//    clr(dp,0x80);
    clr(dp,0);
//    dbg(dp[0][0][0]);
    for(int i = 1; i <= n; i++)
        a[i] = s[i] - '0';
//    dp[1][a[0]][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        cmax(dp[i][a[i]][0], dp[i - 1][a[i] ^ 1][0] + 1);
        cmax(dp[i][a[i]][1], dp[i - 1][a[i]][0] + 1);
        cmax(dp[i][a[i]][1], dp[i - 1][a[i] ^ 1][1] + 1);
        cmax(dp[i][a[i]][2], dp[i - 1][a[i]][1] + 1);
        cmax(dp[i][a[i]][2], dp[i - 1][a[i] ^ 1][2] + 1);
        FOR(x,3) cmax(dp[i][0][x], dp[i - 1][0][x]);
        FOR(x,3) cmax(dp[i][1][x], dp[i - 1][1][x]);
    }
    int ans = 0;
    ans = max(ans, dp[n][0][0]);
    ans = max(ans, dp[n][1][0]);
    ans = max(ans, dp[n][0][1]);
    ans = max(ans, dp[n][1][1]);
    ans = max(ans, dp[n][0][2]);
    ans = max(ans, dp[n][1][2]);
    cout << ans << endl;
}
