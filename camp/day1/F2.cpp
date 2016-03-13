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
const int MAXN = 200005;
const int MAX16 = 65536;
LL dp[MAXN];
char s[MAXN][20];
int a[MAXN];
int n,d;
//bool dayu(int x, int y)
//{
//    FOR(i,d) if(s[x][i] > s[y][i]) return true;
//    return false;
//}
LL sum[MAX16];
LL tmp[MAX16];
int getnum(int x)
{
    int ret = 0;
    FOR(i,d) if(s[x][i] == '1') ret += 1 << (d - 1 - i);
    return ret;
}
bool cmp(int x, int y)
{
//    cout << "CMP " << x << " " << y << endl;
    FOR(i,d) if(s[x][i] > s[y][i]) return false;
//    cout << "T" << endl;
    return true;
}
LL add(LL a, LL b)
{
    if(a + b >= MOD) return a + b - MOD;
    return a + b;
}
int main()
{
//    bin[0] = 1;
//    FORR(i,16)  bin[i] = bin[i - 1] * 2;
    clr(dp,0);
    scanf("%d%d",&n,&d);
    int L = 1024;
    FOR(i,n) scanf("%s",&s[i]);
//    FOR(i,n) puts(s[i]);
    FOR(i,n) a[i] = getnum(i);
//    FOR(i,n) cout << a[i] << endl;
    int bef = 0;
    FOR(i,n)
    {
        if(i % L  == 0)
        {
            bef = i;
            clr(sum, 0);
            FOR(j,i) sum[a[j]] = add(sum[a[j]], dp[j]);
            FOR(j,d) for(int mask = (1 << d) - 1; mask >= 0; mask--) if(((mask >> j) & 1) == 1) sum[mask] = add(sum[mask], sum[mask ^ (1 << j)]);
        }
        dp[i] = add(dp[i], sum[a[i]]);
        for(int j = bef; j < i; j++) if((a[i] | a[j]) ==  a[i]) dp[i] = add(dp[i], dp[j]);
        dp[i] = add(dp[i], 1LL);
    }
    LL ans = 0;
    FOR(i,n) ans = (ans + dp[i]) % MOD;
    cout << ans << endl;
}

/*
3 2
00
00
11

4 3
110
100
011
101
*/
