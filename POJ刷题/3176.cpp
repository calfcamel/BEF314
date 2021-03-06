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
const int MAXN = 500;
int dp[2][MAXN];
char str[MAXN];
int a[MAXN][MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    clr(a,0);
    FORR(i,n) FORR(j,i) scanf("%d",&a[i][j]);
    FORR(i,n) FORR(j,i) a[i][j] = max(a[i - 1][j - 1], a[i - 1][j]) + a[i][j];
    int ans = 0;
    FORR(i,n) FORR(j,i) cmax(ans, a[i][j]);
    cout << ans << endl;
}

