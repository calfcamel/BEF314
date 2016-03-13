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
typedef pair<int, int> PII;
#define FOR(i,x) for(int i = 0, _END_ = (int)(x); i < _END_ ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 505;
int r[MAXN][MAXN];
int c[MAXN][MAXN];
int dp[MAXN][MAXN];
int n,m;
int main()
{
    clr(r,0);
    clr(c,0);
    clr(dp,0);
    while(~scanf("%d%d",&n,&m))
    {
        if(n == 0 && m == 0) return 0;
        FORR(i,n) FORR(j,m)
        {
            scanf("%d",&r[i][j]);
            r[i][j] += r[i][j - 1];
        }
        FORR(i,n) FORR(j,m)
        {
            scanf("%d",&c[i][j]);
            c[i][j] += c[i - 1][j];
        }
        FORR(i,n) FORR(j,m)
        {
            dp[i][j] = max(dp[i][j - 1] + c[i][j], dp[i - 1][j] + r[i][j]);
        }
        printf("%d\n",dp[n][m]);
    }
}

