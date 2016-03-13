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
#define dbg(x) cerr <<#x<<" = " << x << endl
const double PI = acos(-1.0);
const LL MOD = 105225319;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 1000 + 5;
int a[MAXN];
int b[MAXN];
LL f[MAXN][10];
LL dp[MAXN][1024];
int m2[11];
const int N = MAXN;
LL inv[N];
void init()
{
    inv[0] = inv[1] = 1;
    for(int i = 2; i < N; i++)
        inv[i] = ((MOD - MOD / i) * inv[MOD % i]) % MOD;
}
LL A(LL n,LL m)
{
    LL ret = 1;
    for(LL i = 1; i <= n; i++) ret = ret * i % MOD;
    for(LL i = 1; i <= n - m; i++) ret = ret * inv[i] % MOD;
    return ret;
}
char s[10];
int main()
{
    int n;
    while(scanf("%d",&n)!= EOF)
    {
        int ans = 0;
        int l = -1;
        int now;
        FOR(i,n)
        {
            scanf("%s",&s);
            if(s[0] == 'S')  now = -1;
            else scanf("%d",&now);
            if(l != now - 1) ans++;
            l = now;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*

2
2
1 2
1 2
2
1 1
2 2

*/
