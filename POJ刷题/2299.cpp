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
const int MAXN = 500005;
struct BIT
{
    LL a[MAXN];
    void init()
    {
        clr(a,0);
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    void ins(int x, LL c)
    {
        while(x < MAXN)
        {
            a[x] += c;
            x += lowbit(x);
        }
    }
    LL qry(int x)
    {
        LL ret = 0;
        while(x)
        {
            ret += a[x];
            x -= lowbit(x);
        }
        return ret;
    }
}bit;
int n;
int a[MAXN];
vector<PII> v;
int main()
{
    while(scanf("%d",&n),n)
    {
        v.clear();
        FOR(i,n) scanf("%d",&a[i]);
        FOR(i,n) v.PB(MP(a[i],i));
        int tot = 1;
        sort(all(v));
        FOR(i,n)
        {
            if(i && v[i].AA != v[i - 1].AA) tot++;
            a[v[i].BB] = tot;
        }
        bit.init();
        LL ans = 0;
        FOR(i,n)
        {
            ans += i - bit.qry(a[i]);
            bit.ins(a[i],1);
        }
        printf("%lld\n",ans);
    }
}

