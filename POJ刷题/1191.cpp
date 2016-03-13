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
const int MAXN = 15;
int k;
const int n = 8;
int a[MAXN][MAXN];
LL dp[16][10][10][10][10];
const LL TOPLL = 1000000000000000LL;
LL getsum(int x1, int y1, int x2, int y2)
{
    LL ret = 0;
    for(int i = x1; i < x2; i++) for(int j = y1; j < y2; j++) ret += a[i][j];
    return ret;
}
LL sum;
LL sqr(LL x) {return (k * x - sum) * (k * x - sum);}
LL getdp(int k, int x1, int y1, int x2, int y2)
{
//    dbg(k);
    if(k == 1) return sqr(getsum(x1,y1,x2,y2));
//    cout << "HI1" << endl;
    if(x1 == x2 && y1 == y2 && k > 1) return TOPLL;
//    cout << "HI2" << endl;
    if(dp[k][x1][y1][x2][y2] != TOPLL) return dp[k][x1][y1][x2][y2];
//    cout << "HI3" << endl;
    for(int i = x1; i < x2; i++)
    {
        cmin(dp[k][x1][y1][x2][y2], getdp(k - 1,x1,y1,i,y2) + sqr(getsum(i,y1,x2,y2)));
        cmin(dp[k][x1][y1][x2][y2], getdp(k - 1,i,y1,x2,y2) + sqr(getsum(x1,y1,i,y2)));
    }
    for(int i = y1; i < y2; i++)
    {
        cmin(dp[k][x1][y1][x2][y2], getdp(k - 1,x1,i,x2,y2) + sqr(getsum(x1,y1,x2,i)));
        cmin(dp[k][x1][y1][x2][y2], getdp(k - 1,x1,y1,x2,i) + sqr(getsum(x1,i,x2,y2)));
    }
//    cout << "GETDP " << k << x1 << y2 << x2 << y2 << "  = " << dp[x1][y1][x2][y2] << endl;
    return dp[k][x1][y1][x2][y2];
}
int main()
{
    FOR(l, 16) FOR(i,10) FOR(j,10) FOR(k,10) FOR(p,10) dp[l][i][j][k][p] = TOPLL;
    scanf("%d",&k);
    FOR(i,n) FOR(j,n) scanf("%d",&a[i][j]);
    sum = 0;
    FOR(i,n) FOR(j,n) sum += a[i][j];
    printf("%.3f\n",sqrt((double)getdp(k,0,0,n,n)/(double)(k * k * k)));
}
