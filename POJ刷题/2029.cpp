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
const int MAXN = 205;
int sum[MAXN][MAXN];
int dp[MAXN][MAXN];
int a[MAXN][MAXN];
int main()
{
    int n;
    clr(sum,0);
    while(scanf("%d",&n),n)
    {
        int w,h;
        scanf("%d%d",&w,&h);
        clr(a,0);
        int x,y;
        FOR(i,n)
        {
            scanf("%d%d",&x,&y);
            a[x][y] = 1;
        }
        FORR(i,w) FORR(j,h)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
        clr(dp,0);
        int s,t;
        int ans = 0;
        scanf("%d%d",&s,&t);
        FORR(i,w) if(i >= s) FORR(j,h) if(j >= t)
        {
            cmax(ans, sum[i][j] - sum[i - s][j] - sum[i][j - t] + sum[i - s][j - t]);
        }
        printf("%d\n",ans);
//        dbg(ans);
    }
}
