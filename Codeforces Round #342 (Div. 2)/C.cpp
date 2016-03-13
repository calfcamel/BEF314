
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
const int MAXN = 505;
int a[MAXN][MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int now = 1;
    REP(i,1,n) FORR(j,k - 1)
    {
        a[i][j] = now++;
    }
    REP(i,1,n) REP(j,k,n)
    {
        a[i][j] = now++;
    }
    int ans = 0;
    FORR(i,n) ans += a[i][k];
    printf("%d\n",ans);
    FORR(i,n)
    {
        FORR(j,n - 1) printf("%d ", a[i][j]);
        printf("%d\n",a[i][n]);
    }
}
