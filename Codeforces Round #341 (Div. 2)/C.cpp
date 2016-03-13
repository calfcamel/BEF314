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
#define LL long long
const int MAXN = 100001;
double p[MAXN][2];
int n;
double E[MAXN];
int main()
{
    int pri;
    scanf("%d%d",&n,&pri);
    int l, r;
    FOR(i,n)
    {
        scanf("%d%d",&l,&r);
        p[i][1] = ((double)(r / pri - (max(l - 1, 0)) / pri))/((double)(r - l + 1));
        p[i][0] = 1.0 - p[i][1];
//        dbg(p[i][0]);
    }
//    clr(dp,0);
//    dp[0][0] = 1 - p[0];
//    dp[0][1] = p[0];
    E[0] = 0;
    p[n][0] = p[0][0];
    p[n][1] = p[0][1];
    p[n + 1][0] = p[1][0];
    p[n + 1][1] = p[1][1];
    for(int i = 1; i < n + 1; i++)
    {
//        E[i] = E[i - 1] + p[i - 1][0] * p[i][1] * 1000.0 + p[i - 1][1] * p[i][0] * 1000 + p[i - 1][1] + p[i][1] * 1000.0;
//        E[i] = E[i - 1] + p[i][1] * (1 + p[i - 1][1] + p[i + 1][1]) * 1000.0 + p[i][0] * (p[i - 1][1] + p[i + 1][1]) * 1000;
        E[i] = E[i - 1] + (1.0 - p[i - 1][0] * p[i][0]) * 2000.0;
    }
    printf("%.16lf\n",E[n]);
}
