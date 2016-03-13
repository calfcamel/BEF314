
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

const int MAXN = 100 + 10;
int a[MAXN];
int sum[MAXN];
int dp[MAXN][MAXN][2];
int main()
{
    int _T;scanf("%d",&_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        int n;
        scanf("%d",&n);
        FORR(i,n) scanf("%d",&a[i]);
        clr(dp,0);
        sum[0] = 0;
        FORR(i,n) sum[i] = sum[i - 1] + a[i];
        FORR(i,n)
        {
            dp[i][i][0] = a[i];
            dp[i][i][1] = a[i];
        }
        int j;
        for(int l = 2; l <= n; l++) FORR(i,n - l + 1)
        {
            j = i + l - 1;
            dp[i][j][0] = max(a[i] + dp[i + 1][j][0], a[i] + sum[j] - sum[i] - max(dp[i + 1][j][0],dp[i + 1][j][1]));
            dp[i][j][1] = max(a[j] + dp[i][j - 1][1], a[j] + sum[j - 1] - sum[i - 1] - max(dp[i][j - 1][0],dp[i][j - 1][1]));
        }
        int ans = max(dp[1][n][0] - (sum[n] - dp[1][n][0]),dp[1][n][1] - (sum[n] - dp[1][n][1]));
        printf("Case %d: %d\n",CAS,ans);
    }
}
