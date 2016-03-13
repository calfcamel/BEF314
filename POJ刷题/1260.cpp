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
const int MAXN = 1005;
int a[MAXN];
int p[MAXN];
int dp[MAXN];
int n;
int main()
{
    int _T;
    scanf("%d",&_T);
    a[0] = 0;
    dp[0] = 0;
    while(_T--)
    {
        scanf("%d",&n);
        FORR(i,n) scanf("%d%d",&a[i],&p[i]);
        FORR(i,n) a[i] += a[i - 1];
        FORR(i,n)
        {
            dp[i] = dp[i - 1] + (a[i] - a[i - 1] + 10) * p[i];
            FOR(j,i - 1) cmin(dp[i], dp[j] + (a[i] - a[j] + 10) * p[i]);
        }
        printf("%d\n",dp[n]);
    }
}
