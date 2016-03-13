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
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)

const LL MAXN = 1000000000000000000LL;
LL a[20];
set<LL> S;
void dfs(int k, LL now)
{
    if(k == 20)
    {
        S.insert(now);
        return;
    }
    dfs(k + 1, now);
    while(MAXN / now / a[k])
    {
        now = now * a[k];
        dfs(k + 1, now);
    }
}
void init()
{
    a[0] = 1;
    for(LL i = 1; i <= 19; i++) a[i] = a[i - 1] * i;
    S.clear();
    dfs(2,1);
}
bool calc(LL x)
{
    if(S.find(x) != S.end()) return true;
    return false;
}
int main()
{
    init();
    int _T;
    scanf("%d",&_T);
    while(_T--)
    {
        LL n;
        scanf("%I64d",&n);
        if(calc(n)) puts("YES"); else puts("NO");
    }
    return 0;
}
