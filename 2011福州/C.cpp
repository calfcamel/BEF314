#include <cstdio>
#include <algorithm>
#include <deque>
#include <iostream>
typedef long long LL;
//#pragma comment(linker, "/STACK:102400000,102400000")
#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = std::min(x,y)
#define cmax(x,y) x = std::max(x,y)
#define MP std::make_pair
#define AA first
#define BB second
#define PB push_back
#define SZ size()
#define dbg(x) cerr <<#x<<" = " << x << endl
#define all(x) x.begin(), x.end()
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;

#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
#define LL long long
const int MAXN = 50005;
int n,m;
int h[MAXN];
int f[MAXN];
int tot;
struct edge
{
    int v,w;
    int next;
}e[MAXN * 2];
struct dpnode
{
    int up;
    int down, down2;
}dp[50005];
int a[MAXN];
struct mydeque
{
    int l,r;
    int A[MAXN];
    int B[MAXN];
    void init()
    {
        l = r = 0;
    }
}Qmax,Qmin;
void add(int u, int v, int w)
{
    e[tot].v = u; e[tot].w = w; e[tot].next = h[v]; h[v] = tot; tot++;
    e[tot].v = v; e[tot].w = w; e[tot].next = h[u]; h[u] = tot; tot++;
}
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
int getdown(int x, int w)
{
//    dbg(x);
//    dbg(w);
    int nxt = h[x];
    int tmp;
    while(~nxt)
    {
        if(e[nxt].v != f[x])
        {
            tmp = getdown(e[nxt].v, e[nxt].w);
            if(tmp > dp[x].down) {dp[x].down2 = dp[x].down; dp[x].down = tmp;}
            else if(tmp > dp[x].down2) dp[x].down2 = tmp;
        }
        nxt = e[nxt].next;
    }
    return dp[x].down + w;
}
void getup(int x, int w)
{
//    dbg(x);
//    dbg(w);
    int nxt = h[x];
    if(x == 1) dp[x].up = 0;
    else
    {
        dp[x].up = w + dp[f[x]].up;
        cmax(dp[x].up, w + dp[f[x]].down2);
        if(w + dp[x].down != dp[f[x]].down) cmax(dp[x].up, w + dp[f[x]].down);
    }
    while(~nxt)
    {
        if(e[nxt].v != f[x]) getup(e[nxt].v, e[nxt].w);
        nxt = e[nxt].next;
    }
}
void init()
{
    for(int i = 0; i <= n; i++) h[i] = -1;
    tot = 0;
}
void initdp()
{
//    cout << "INITDP" << endl;
    for(int i = 0; i <= n; i++)
    {
        dp[i].down = 0;
        dp[i].down2 = 0;
        dp[i].up = 0;
    }
}
int chk(int l)
{
    Qmax.init();
    Qmin.init();
    int ret = n * 2;
    FORR(i,n)
    {
        while(Qmax.l != Qmax.r && Qmax.A[Qmax.r - 1] <= a[i]) Qmax.r--; Qmax.A[Qmax.r] = a[i]; Qmax.B[Qmax.r] = i; Qmax.r++;
        while(Qmin.l != Qmin.r && Qmin.A[Qmin.r - 1] >= a[i]) Qmin.r--; Qmin.A[Qmin.r] = a[i]; Qmin.B[Qmin.r] = i; Qmin.r++;
        while(Qmax.l != Qmax.r && Qmax.B[Qmax.l] <= i - l) Qmax.l++;
        while(Qmin.l != Qmin.r && Qmin.B[Qmin.l] <= i - l) Qmin.l++;
        if(i >= l && Qmax.l != Qmax.r && Qmin.l != Qmin.r) cmin(ret, Qmax.A[Qmax.l] - Qmin.A[Qmin.l]);
    }
//    cout << "CHK " << l << " = " << ret << endl;
    return ret;
}
//int L, R, mid;
//int query(int Q)
//{
//    L = 1; R = n;
//    while(L < R)
//    {
//        mid = (L + R + 1) / 2;
//        if(chk(mid) <= Q) L = mid;
//        else R = mid - 1;
//    }
//    return L;
//}

std::deque<std::pair<int, int> > Q;

int query(int q)
{
    int ret = 1;
    int now;
    while(!Q.empty()) Q.pop_back();
    now = 1;
    int l = 1;
    Q.push_back(MP(a[1],1));
    REP(i,2,n)
    {
        if(a[i] < Q.front().AA)
        {
            Q.push_front(MP(a[i],i));
            while(Q.back().AA - Q.front().AA > q) {Q.pop_back(); l = std::max(l, std::min(Q.back().BB,Q.front().BB));}
        }
        else if(a[i] > Q.back().AA)
        {
            Q.push_back(MP(a[i],i));
            while(Q.back().AA - Q.front().AA > q) {Q.pop_front(); l = std::max(l, std::min(Q.back().BB,Q.front().BB));}
        }
        ret = std::max(ret, i - l + 1);
    }
    return ret;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n == 0 && m == 0) return 0;
        int u,v,w;
        init();
        FOR(i,n - 1)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
        }
        dfs(1);
//        dbg("HI");
        initdp();
//        dbg("ENDINITDP");
        getdown(1, 0);
        getup(1,0);
        FORR(i,n) a[i] = std::max(dp[i].up, dp[i].down);
        std::cout << "A = "; FORR(i,n) std::cout << a[i] << " " ; std::cout << std::endl;
        int q;
        FOR(i,m)
        {
            scanf("%d",&q);
            printf("ans = %d\n",query(q));
//            dbg(query(Q));
        }
    }
}
