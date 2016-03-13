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
typedef unsigned long long ULL;
//#pragma comment(linker, "/STACK:102400000,102400000")
#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define ccmin(x,y) if(x == -1) x = y; else x = min(x,y)
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

const int MAXN = 24 + 5;
int a[3][MAXN];
int n,m,p;
LL dp[MAXN][MAXN][MAXN];
LL found(int i, int j, int k)
{
    if(i && a[0][i - 1]) return found(i - 1, j, k);
    if(j && a[1][j - 1]) return found(i, j - 1, k);
    if(k && a[2][k - 1]) return found(i, j, k - 1);
    if(i < 0) cout << "cao" << endl;
    if(j < 0) cout << "cao" << endl;
    if(k < 0) cout << "cao" << endl;
    if(i + j + k == 0) return 1;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    LL ret = 0;
    if(i >= j && i >= k)
    {
        if(i) ret += found(i - 1,j,k);
        if(i >= 2 && a[0][i - 2] == 0) ret += found(i - 2,j,k);
        if(i && i == j) ret += found(i - 1,j - 1,k);
    }
    else if(j >= k)
    {
        if(j) ret += found(i,j - 1,k);
        if(j >= 2 && a[1][j - 2] == 0) ret += found(i,j - 2,k);
        if(j && j == k) ret += found(i,j - 1,k - 1);

    }
    else
    {
        if(k) ret += found(i,j,k - 1);
        if(k >= 2 && a[2][k - 2] == 0) ret += found(i,j,k - 2);
    }
    dp[i][j][k] = ret;
//    cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
    return ret;
}
int main()
{
    n = 3;
    FOR(i,MAXN) FOR(j,MAXN) FOR(k,MAXN) dp[i][j][k] = -1;
    scanf("%d%d",&m,&p);
    double x,y;
    int tx,ty;
    clr(a,0);
    FOR(i,p)
    {
        scanf("%lf%lf",&x,&y);
        tx = x;
        ty = y;
        a[ty][tx] = 1;
//        cout << tx << ty << endl;
    }
    cout << found(m,m,m) << endl;
    return 0;
}
