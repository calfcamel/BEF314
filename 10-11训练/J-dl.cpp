#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define LL long long
#define u32  unsigned int
#define AA first
#define BB second
typedef pair<int, int> PII;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define INS(x) insert(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define MEM(a) memset(a, 0, sizeof a)
#define ECH(x) for(__typeof x.OP it = x.OP; it != x.ED; it++)
/*===========================================================*/
#define N 6000000

struct rec
{
    int xL, yL, xR, yR;
    rec() {};
    rec(int xL, int yL, int xR, int yR) : xL(xL), xR(xR), yL(yL), yR(yR){};
};

int cnt;

struct Node
{
    rec s;
    int L, R;
    Node() { L = -1; R = -1; }
    Node(int xL, int yL, int xR, int yR) { s = rec(xL, yL, xR, yR); L = -1; R = -1; }
}f[N];


int newNode(int xL, int yL, int xR, int yR)
{
    f[++cnt] = Node(xL, yL, xR, yR);
    return cnt;
}

int xR, yR, xL, yL;
int n, Q;
int rt;
const int POW = 20;
int p[N][POW];
int d[N];
int c[N];


void dfs(int u, int fa)
{
    if(u == -1) return;
    c[u] = 0;
    d[u] = d[fa]+1;
    p[u][0] = fa;
    for(int i = 1; i < POW; i++) p[u][i] = p[p[u][i - 1]][i - 1];
    dfs(f[u].L, u);
    dfs(f[u].R, u);
    if(f[u].L != -1)
    {
        c[u] += c[f[u].L];
        c[u] += c[f[u].R];
    }
    else c[u] = 1;
}

int lca( int a, int b ){
    if( d[a] > d[b] ) a ^= b, b ^= a, a ^= b;
    if( d[a] < d[b] ){
        int del = d[b] - d[a];
        for( int i = 0; i < POW; i++ ) if(del&(1<<i)) b=p[b][i];
    }
    if( a != b ){
        for( int i = POW-1; i >= 0; i-- )
            if( p[a][i] != p[b][i] )
                 a = p[a][i] , b = p[b][i];
        a = p[a][0], b = p[b][0];
    }
    return a;
}

bool contain(rec& s, int x, int y)
{
    if(x < s.xL || s.xR < x) return false;
    if(y < s.yL || s.yR < y) return false;
    return true;
}

void build(int x, int xL, int yL, int xR, int yR)
{
    if(!contain(f[x].s, xL, yL) && !contain(f[x].s, xR, yR)) return;
    if(f[x].L == -1 && f[x].R == -1)
    {
        if(xL == xR) { f[x].L = newNode(f[x].s.xL, f[x].s.yL, xR, f[x].s.yR); f[x].R = newNode(xR, f[x].s.yL, f[x].s.xR, f[x].s.yR); }
        else { f[x].L = newNode(f[x].s.xL, f[x].s.yL, f[x].s.xR, yR); f[x].R = newNode(f[x].s.xL, yR, f[x].s.xR, f[x].s.yR); }
        return ;
    }
    build(f[x].R, xL, yL, xR, yR); build(f[x].L, xL, yL, xR, yR);
}

int find(int x, int X, int Y)
{
    if(f[x].L == -1 && f[x].R == -1) return x;
    if(!contain(f[x].s, X, Y)) return -1;
    int L = find(f[x].R, X, Y); int R = find(f[x].L, X, Y);
    return max(L, R);
}


int main()
{
    freopen("input.txt", "r", stdin);
    while(~scanf("%d%d%d%d", &xL, &yL, &xR, &yR))
    {
        cnt = 0;
        rt = newNode(xL, yL, xR, yR);
        scanf("%d%d", &n, &Q);
        FOR(i, n)
        {
            int xL, yL, xR, yR; scanf("%d%d%d%d", &xL, &yL, &xR, &yR);
            if(xL > xR) swap(xL, xR);
            if(yL > yR) swap(yL, yR);
            build(rt, xL, yL, xR, yR);
        }
        FOR(i, POW) p[rt][i] = rt;
        FORR(i, cnt) cout << f[i].s.xL << " " << f[i].s.yL << " " << f[i].s.xR << " " << f[i].s.yR << " "  << i << endl;
        dfs(rt, 1);
        cout << "TOT " << c[rt] << endl;
        FOR(i, Q)
        {
            int p1, p2;
            int x, y;
            scanf("%d%d", &x, &y);
            p1 = find(rt, x, y);
            scanf("%d%d", &x, &y);
            p2 = find(rt, x, y);
            int fa = lca(p1, p2);
            printf("%d\n", c[rt] - c[fa] + 1);
        }
    }
    return 0;
}
