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
typedef pair<int, int> PII;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
#define LL long long
int n,a,b,T;
const int MAXN = 500005;
char str[MAXN];
int dp1[MAXN];
int dp2[MAXN];
int sumdp2[MAXN];
int add[MAXN];
int chk(int x)
{
    if(x < 0) return 0;
    else return dp2[x];
}
int efdp2(int t, int limit)
{
    if(t < 0) return 0;
    int L = -1; int R = n - limit - 1 - 1;
    while(L < R)
    {
//        if(R == 0 && chk(R) <= t) return 1; else return 0;
//dbg(L);dbg(R);
        int mid = (L + R + 1) / 2;
        if(chk(mid) <= t) L = mid;
        else R = mid - 1;
    }
    return L + 1;
}
int chkdp1(int x)
{
    if(x == 0) return 0;
    else return dp1[x];
}
int efdp1(int t, int limit)
{
    if(t < 0) return 0;
    int L = 0; int R = n - limit - 1 - 1;
    while(L < R)
    {
//        if(R == 1 && chkdp1(R) <= t) return 1; else return 0;
        int mid = (L + R + 1) / 2;
        if(chkdp1(mid) <= t) L = mid;
        else R = mid - 1;
    }
    return L;
}
int main()
{
    scanf("%d%d%d%d",&n,&a,&b,&T);
    scanf("%s",&str);
    FOR(i,n) if(str[i] == 'w') add[i] = b + 1; else add[i] = 1;
    add[0] = 0;
    if(str[0] == 'w' && T < b + 1)
    {
        puts("0");
        return 0;
    }
    T -= 1;
    if(str[0] == 'w') T-= b;
    if(T < a)
    {
        puts("1");
        return 0;
    }
    clr(dp1,0);
    clr(dp2,0);
    dp1[0] = 0;
    REP(i,1, n - 1) dp1[i] = dp1[i - 1] + a + add[i];
    reverse(add, add + n);
    dp2[0] = a + add[0];
    REP(i,1, n - 2) dp2[i] = dp2[i - 1] + a + add[i];
    sumdp2[0] = dp2[0];
    REP(i,1, n - 2) sumdp2[i] = sumdp2[i - 1] + dp2[i];
    int ans = 1;
//    cout << " HI" << endl;
    REP(i,1,n - 1)
    {
        if(dp1[i] > T) break;
        cmax(ans, i + 1);
        cmax(ans, i + 1 + efdp2(T - dp1[i] - (a ) * (i), i));
    }
//    dbg(T);
//    dbg(dp1[2]);
    REP(i,0,n - 2)
    {
        if(dp2[i] > T) break;
        cmax(ans, i + 2);
        cmax(ans, i + 2 + efdp1(T - dp2[i] - (a ) * (i + 1), i));
    }
    cout << ans << endl;
}
