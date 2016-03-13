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
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 200 + 5;
int n;
int a[MAXN][MAXN];
LL dp[MAXN][MAXN];
int main()
{
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        scanf("%d",&n);
        clr(a,0);
        FORR(i,n) FORR(j,i) scanf("%d",&a[i][j]);
        FORR(i,n - 1) FORR(j,n - i) scanf("%d",&a[n + i][j]);
        clr(dp, 0);
        FORR(i,n) FORR(j,i) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
        FORR(i,n - 1) FORR(j,n - i) dp[n + i][j] = max(dp[n + i - 1][j], dp[n + i - 1][j + 1]) + a[n + i][j];
        printf("Case %d: %d\n",CAS,dp[2 * n - 1][1]);
    }
    return 0;
}
