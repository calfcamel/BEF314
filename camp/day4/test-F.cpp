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
const int MAXN = 505;
int dp[MAXN][MAXN];
int a[MAXN];
int b[MAXN];
int t[MAXN];
void puty()
{
    puts("Yes");
    exit(0);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    FOR(i,n) scanf("%d",&a[i]);
    FOR(i,m) scanf("%d",&b[i]);
    reverse(b, b + m);
    reverse(a, a + n);
    REP(i,1,n - 1) if(a[i] > a[0]) t[i] = 1;
    else if(a[i] == a[0]) t[i] = 0;
    else t[i] = -1;
    clr(dp, 0);
//    FOR(i,n) cout << t[i] << " "; cout << endl;
    FOR(i,m)
    {
        REP(j,1,m) REP(k,1,m) if(dp[j][k])
        {
            if(dp[j][k] == n) puty();
            if(t[dp[j][k]] == 1 && k < b[i])
                cmax(dp[j][b[i]], dp[j][k] + 1);
            else if(t[dp[j][k]] == -1 && b[i] < j)
                cmax(dp[b[i]][k], dp[j][k] + 1);
        }
        dp[b[i]][b[i]] = 1;
    }
//    REP(j,1,m)
//    {
//        REP(k,1,m) cout << dp[j][k] << " ";cout << endl;
//    }
    REP(j,1,m)
    {
        REP(k,1,m)
            if(dp[j][k] == n) puty();
    }
    puts("No");return 0;
}

/*
3 4
1 2 3
1 3 2 4

3 4
1 2 3
4 4 4 4
*/
