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
#define LL long long
const int MAXN = 1000;
int dp[2][MAXN][3];
int ans[MAXN];
int main()
{
    clr(dp,0);
    dp[0][0][2] = 1;
    clr(ans,0);
    int cur = 0;
    int nxt = 1;
    int n = 100;
    for(int i = 3; i <= n; i++)
    {
        clr(dp[nxt],0);
        for(int j = 0; j <= 100; j++) for(int k = 2; k <= 2; k++)
        {
            if(j) dp[nxt][j - 1][k] += dp[cur][j][k] * j;
            if(k) dp[nxt][j + 1][k] += dp[cur][j][k] * 2;
        }
        for(int j = 0; j <= 100; j++) ans[i] += dp[nxt][j][2];
        swap(cur, nxt);
    }
    FOR(i,20) cout << i << " " << ans[i] << endl;
}
