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
typedef unsigned long long ULL;
//#pragma comment(linker, "/STACK:102400000,102400000")
#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define ccmin(x,y) if(x == -1) x = y; else x = min(x,y)
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
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 100 + 5;
int a[MAXN][MAXN];
int ans[MAXN][MAXN];
char s[MAXN][MAXN];
LL calc(LL x, LL y)
{
    if(x == 0 || y == 0) return 0;
    if(x == y) return 1;
    if(x > y) swap(x,y);
    return 1 + calc(max(y - x, x), x);
}
int main()
{
    int _T;
    scanf("%d",&_T);
    FOR(CAS,_T)
    {
        LL x,y;
        scanf("%lld%lld",&x,&y);
        LL ans = 1;
        if(x != y) ans ++;
        if(x > y) swap(y,x);
        x = max(x, y - x);
        ans += calc(x,y);
        printf("%lld\n",ans);
    }
}
