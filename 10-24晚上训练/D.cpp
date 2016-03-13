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
typedef unsigned long long LL;
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
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)

const int MAXN = 200000 + 5;

LL a[MAXN];
int h[MAXN];
struct
{
    int v;
    int next;
}e[MAXN];
int tot;
LL c[MAXN];
void ADD(int x,int y)
{
    e[tot].v = y;
    e[tot].next = h[x];
    h[x] = tot;
    tot++;
}
LL GCD(LL a,LL b){
	if(b==0)return a;
	return GCD(b,a % b);
}
LL MUL(LL x,LL y)
{
    if(x == 0) x = 1;
    if(y == 0) y = 1;
    return x * y;
}
LL LCM(LL x,LL y)
{
    if(x == 0) x = 1;
    if(y == 0) y = 1;
    return x / GCD(x,y) * y;
}
LL lcm[MAXN];
LL dfs(int i, int fa)
{
//    cout << "dfs " << i << " " << fa << endl;
    LL tmp = 0xFFFFFFFF;
    LL tmplcm = 0;
    if(c[i] == 0) return a[i];
    int next = h[i];
    while(~next)
    {
        if(e[next].v != fa)
        {
            cmin(tmp, dfs(e[next].v, i));
            tmplcm = LCM(tmplcm, lcm[e[next].v]);
        }
        next = e[next].next;
    }
    lcm[i] = MUL(tmplcm, c[i]);
    tmp -= tmp % tmplcm;
    return tmp * c[i];
}
int main()
{
    LL n;
    scanf("%I64u",&n);
    LL sum = 0;
    for(int i = 1; i <= n; i++) scanf("%I64u",&a[i]);
    for(int i = 1; i <= n; i++) sum += a[i];
    tot = 0;
    clr(c,0);
    clr(h, -1);
    clr(lcm,0);
    int x,y;
    FOR(i,n - 1)
    {
        scanf("%d%d",&x,&y);
        ADD(x,y);
        ADD(y,x);
        c[x]++;
        c[y]++;
    }
    for(int i = 2; i <= n; i++)
        c[i]--;
    cout << sum - dfs(1, -1) << endl;
    return 0;
}

