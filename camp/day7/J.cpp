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
const int MAXN = 500001;
int n,L;
int h[MAXN];
int tot;
struct edge
{
    int v;
    int next;
    char ch;
}e[MAXN];
void add(int u, int v, char s)
{
    e[tot].v = u; e[tot].ch = s; e[tot].next = h[v]; h[v] = tot; tot++;
    e[tot].v = v; e[tot].ch = s; e[tot].next = h[u]; h[u] = tot; tot++;
}
int f[MAXN];
struct dpnode
{
    int firstvalue;
    int secondvalue;
    int from;
    int secondfrom;
    int bef;
}dp1[MAXN],dp2[MAXN];
void dfs(int x)
{
    int nxt = h[x];
    f[x] = -1;
    while(~nxt)
    {
        if(f[e[nxt].v]) f[x] = e[nxt].v;
        else dfs(e[nxt].v);
        nxt = e[nxt].next;
    }
}
char str[MAXN];
void getdp(int x)
{
    int nxt = h[x];
    int fi;
    dp1[x].firstvalue = 0;
    dp1[x].secondvalue = 0;
    dp1[x].from = x;
    while(~nxt)
    {
        if(e[nxt].v != f[x]) getdp(e[nxt].v);
        else fi = nxt;
        nxt = e[nxt].next;
    }
    if(x == 1) return;
    int my = dp1[x].firstvalue + ((e[fi].ch == str[dp1[x].firstvalue]) ? 1 : 0);
    if(dp1[e[fi].v].firstvalue < my)
    {
        dp1[e[fi].v].secondvalue = dp1[e[fi].v].firstvalue;
        dp1[e[fi].v].firstvalue = my;
        dp1[e[fi].v].secondfrom = dp1[e[fi].v].from;
        dp1[e[fi].v].from = dp1[x].from;
        dp1[e[fi].v].bef = x;
    }
    else if(dp1[e[fi].v].secondvalue < my)
    {
        dp1[e[fi].v].secondvalue = my;
        dp1[e[fi].v].secondfrom = dp1[x].from;
    }
}
char s[10];
void putans(int x,int y)
{
    cout << x << " " << y << endl;
    exit(0);
}
int main()
{
    tot = 0;
    scanf("%d%d",&n,&L);
    FORR(i,n) h[i] = -1;
    FORR(i,n) f[i] = 0;
    int u,v;
    FOR(i,n)
    {
        scanf("%d%d%s",&u,&v,&s);
        add(u,v,s[0]);
    }
    scanf("%s",str);
    str[L] = '#';
    f[1] = -1;
    dfs(1);
    getdp(1);
    reverse(str,str + L);
    swap(dp1,dp2);
    getdp(1);
//    FORR(i,n) cout << i << " FA = " << f[i] << endl;
//    FORR(i,n) cout << i << ": " << dp1[i].firstvalue << " " << dp2[i].firstvalue << " FROM : " << dp1[i].from << " " << dp2[i].from << endl;
    FORR(i,n)
    {
        if(dp1[i].bef == dp2[i].bef)
        {
            if(dp1[i].firstvalue + dp2[i].secondvalue >= L) putans(dp1[i].from, dp2[i].secondfrom);
            if(dp2[i].firstvalue + dp1[i].secondvalue >= L) putans(dp2[i].from, dp1[i].secondfrom);
        }
        else if(dp1[i].firstvalue + dp2[i].firstvalue >= L) putans(dp1[i].from, dp2[i].from);
    }
    puts("-1 -1");
    return 0;
}
