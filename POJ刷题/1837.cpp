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
const int MAXN = 15001;
int n,m;
int a[20];
int b[20];
LL dp[21][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    FOR(i,n) scanf("%d",&a[i]);
    FOR(i,m) scanf("%d",&b[i]);
    clr(dp, 0);
    dp[0][7500] = 1;
    FOR(i,m)
    {
        FOR(k, MAXN) if(dp[i][k]) FOR(j,n) dp[i + 1][k + a[j] * b[i]] += dp[i][k];
//        FOR(k, MAXN) dp[i + 1][k] += dp[i][k];
//        FOR(j,n) dp[i + 1][7500 + a[j] * b[i]] += 1;
    }
//    FORR(i,m)
//    {
//        FOR(k, MAXN) if(dp[i][k]) cout << k << " ";cout << endl;
//    }
    cout << dp[m][7500] << endl;
}
