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
int dp[35][35][55];
int solve(int n, int m, int k)
{
    if(dp[n][m][k] != MAXINT) return dp[n][m][k];
    if(n * m < k) return MAXINT;
    if(n * m == k || k == 0) return 0;
    for(int i = 1; i < n; i++)
    {
        for(int p = 0; p <= k; p++)
        {
            dp[n][m][k] = min(dp[n][m][k], solve(n - i, m, k - p) + solve(i, m, p) + m * m);
        }
    }
    for(int j = 1; j < m; j++)
    {
        for(int p = 0; p <= k; p++)
        {
            dp[n][m][k] = min(dp[n][m][k], solve(n, m - j, k - p) + solve(n, j, p) + n * n);
        }
    }
    return dp[n][m][k];
}
int main()
{
//    cout << MAXINT << endl;
    FOR(i,35) FOR(j,35) FOR(k,55) dp[i][j][k] = MAXINT;
    int _T;
    int n,m,k;
    scanf("%d",&_T);
    while(_T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        cout << solve(n,m,k) << endl;
    }
    return 0;
}
