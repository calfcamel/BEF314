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
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;


const int MAXN = 10000 + 5;
const int MAXM = 100 + 5;
const int inf = 1 << 30;
int n,m;
int dp[MAXN][MAXM];
int f[MAXN];
int cost[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
        scanf("%d",&cost[i]);
    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXM; j++)
            dp[i][j] = inf;
    for(int i = 0; i < MAXN; i++)
        f[i] = inf;
    for(int i = 0; i < n)
    return 0;
}
