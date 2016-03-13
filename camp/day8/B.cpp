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
const int MAXN = 100004;
LL x[MAXN];
LL y[MAXN];
int n;

int main()
{
    scanf("%d",&n);
    FOR(i,n) scanf("%lld%lld",&x[i],&y[i]);
    LL max1 = x[0] + y[0];
    LL min1 = x[0] + y[0];
    LL max2 = x[0] - y[0];
    LL min2 = x[0] - y[0];
    for(int i = 1; i < n; i++)
    {
        cmax(max1, x[i] + y[i]);
        cmin(min1, x[i] + y[i]);
        cmax(max2, x[i] - y[i]);
        cmin(min2, x[i] - y[i]);
    }
    LL ans = max(max1 - min1, max2 - min2);
    if(max1 - min1 > max2 - min2)
    {
        FOR(i,n) cmin(ans, max(abs(x[i] + y[i] - max1),abs(x[i] + y[i] - min1)));
    }
    if(max1 - min1 < max2 - min2)
    {
        FOR(i,n) cmin(ans, max(abs(x[i] - y[i] - max2),abs(x[i] - y[i] - min2)));
    }
    if(max1 - min1 == max2 - min2)
    {
        LL tmp1 = ans;
        FOR(i,n) cmin(tmp1, max(abs(x[i] + y[i] - max1),abs(x[i] + y[i] - min1)));
        LL tmp2 = ans;
        FOR(i,n) cmin(tmp2, max(abs(x[i] - y[i] - max2),abs(x[i] - y[i] - min2)));
        ans = max(tmp1,tmp2);
    }
    cout << ans << endl;
}
/*
6
1 7
8 5
6 3
10 3
5 2
6 10
4
0 3
1 2
2 1
3 0
*/
