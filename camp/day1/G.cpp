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
#define FORi(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define REP(i,x,y) for(int i = x; i >= (int) (y) ; i--)
const int MAXN = 505;
int n, m;
int w[MAXN];
int r[MAXN];
int dp[MAXN][MAXN][MAXN];
int main()
{
    int ans = 1000000000;
    scanf("%d%d",&n,&m);
    FORR(i,n) scanf("%d",&w[i]);
    sort(w + 1, w + n + 1);
//    reverse(w + 1, w + n + 1);
//    dbg(w[1]);
    FORR(i,m) scanf("%d",&r[i]);
    clr(dp, -1);
    dp[1][n][r[1]] = 0;
    FORR(i,m) REP(j,n,0) REP(k,500,0) if(dp[i][j][k] != -1)
    {
//        cout << i << " " << j << " " << k << " = " << dp[i][j][k] << endl;
        if(j == 0)
        {
            cmin(ans, dp[i][j][k]);
            continue;
        }
        if(i != m)
        {
            if(dp[i + 1][j][min(k * r[i + 1],500)] != -1) cmin(dp[i + 1][j][min(k * r[i + 1],500)], dp[i][j][k]);
            else dp[i + 1][j][min(k * r[i + 1],500)] = dp[i][j][k];
        }
        if(k > 0)
        {
            if(dp[i][j - 1][k - 1] != -1) cmin(dp[i][j - 1][k - 1], dp[i][j][k] + w[j] * i);
            else dp[i][j - 1][k - 1] = dp[i][j][k] + w[j] * i;
        }
    }
    cout << ans << endl;
}

/*
2 2 4 3 2 1

3 2 1 2 4 2 2

*/
