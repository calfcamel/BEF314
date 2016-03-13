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
const int MAXN = 205;
const int MAXDP = 405;
int a[MAXN][MAXN];
int dp[MAXDP][MAXN][MAXN];
int b[MAXDP][MAXN];
int lb[MAXDP];
int n,m;
bool hefa(int x, int y)
{
    if(x < 1 || x > n) return false;
    if(y < 1 || y > m) return false;
    return true;
}
int ttt = 0;
void gao(int k, int x, int y)
{
    assert(k < MAXDP);
//    cout << "GAO " << x << " " << y << endl;
    lb[k] = 1;
    while(hefa(x,y))
    {
//        if(ttt <=20)cout << "x,y = " << x << " " << y<< endl;
        ttt++;
        b[k][lb[k]++] = a[x][y];
        x++;
        y--;
    }
}
int main()
{
    scanf("%d%d",&m,&n);
    FORR(i,n) FORR(j,m) scanf("%d",&a[i][j]);
//    dbg(a[1][0]);
//    dbg(a[1][1]);
//    dbg(a[1][2]);
//    dbg(a[1][3]);
//    dbg(a[2][0]);
//    dbg(a[2][1]);
//    dbg(a[2][2]);
//    dbg(a[2][3]);
    int tmpk = 1;
    for(int i = 1; i <= m; i++) gao(tmpk++, 1, i);
    for(int i = 2; i <= n; i++) gao(tmpk++, i, m);
//    FORR(i, n + m - 1)
//    {
//        cout << i << ": ";
//        FOR(j, lb[i]) cout << b[i][j] << " ";
//        cout << endl;
//    }
    lb[0] = 0;
    clr(dp,0);
    FORR(k, n + m - 1) for(int i = 1; i < lb[k]; i++) for(int j = i; j < lb[k]; j++)
    {
//        if(!i && !j)dbg(lb[k]);
        if(lb[k] >= lb[k - 1])
        {
//            if(!i && !j) cout << "hi" << endl;
            if(i == j) dp[k][i][j] = b[k][i];
            else dp[k][i][j] = b[k][i] + b[k][j];
            dp[k][i][j] += max(max(dp[k - 1][i - 1][j - 1],j - 1 >= i ?dp[k - 1][i][j - 1]: 0),
                               max(dp[k - 1][i][j],dp[k - 1][i - 1][j]));
        }
        else
        {
            if(i == j) dp[k][i][j] = b[k][i];
            else dp[k][i][j] = b[k][i] + b[k][j];
            dp[k][i][j] += max(max(dp[k - 1][i + 1][j + 1],dp[k - 1][i][j + 1]),
                               max(dp[k - 1][i][j],i + 1 <= j? dp[k - 1][i + 1][j]: 0));
        }
//        if(k <= 3)cout << k << " " << i << " " << j << " " << dp[k][i][j] << endl;
    }
    cout << dp[n + m - 1][1][1] << endl;
}


