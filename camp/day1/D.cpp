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

typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
#define MOD 0x3f3f3f3f
const int Maxn = 600;
const int Maxm = 100000;
struct edge
{
    int u, v, c, w, next;
}e[Maxm];
int last[Maxn];
int tot;
int flow, cost, value;
int dist[Maxn], visit[Maxn], src, des;
deque<int> Q;
int n, m;

void adde(int u, int v, int c, int w) {
    cout << "ADD " << u << " " << v << " " << c << " " << w << endl;
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].w = w; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].w = -w; e[tot].next = last[v]; last[v] = tot++;
}

int Aug(int u, int m) {
    if(u == des) {
        cost += value * m;
        flow += m;
        return m;
    }
    visit[u] = true;
    int l = m;
    int j, v, c, w;
    for(j = last[u]; j != -1; j = e[j].next) {
        v = e[j].v; c = e[j].c; w = e[j].w;
        if(c && !w && !visit[v]) {
            int del = Aug(v, l < c ? l : c);
            e[j].c -= del; e[j ^ 1].c += del; l -= del;
            if(!l) return m;
        }
    }
    return m - l;
}

bool Modlabel(int src, int des, int n) {
    int i, j, u, v, c, w, del;
    memset(dist, 0x3f, sizeof(dist[0])*(n + 3));
    dist[src] = 0;
    while(!Q.empty()) Q.pop_back();
    Q.push_back(src);
    while(!Q.empty()) {
        u = Q.front(); Q.pop_front();
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v; c = e[j].c; w = e[j].w;
            if(c && (del = dist[u] + w) < dist[v]) {
                dist[v] = del;
                if(Q.empty() || del <= dist[Q.front()]) {
                    Q.push_front(v);
                }
                else {
                    Q.push_back(v);
                }
            }
        }
    }
    for(i = 0; i < n; i++) {
        for(j = last[i]; j != -1; j = e[j].next) {
            e[j].w -= dist[e[j].v] - dist[i];
        }
    }
    value += dist[des];
    return dist[des] < MOD;
}

void zkw(int src, int des, int n) {
   value = cost = flow = 0;
//   cost = -100000000;
   while(Modlabel(src, des, n)){
       do {
//            dbg(cost);
            memset(visit, 0, sizeof(visit[0]) * (n + 3));
       }while(Aug(src, MOD));
   }
}
const int MAXN = 600;
int p[MAXN][MAXN];
int q[MAXN][MAXN];
LL g[MAXN][MAXN];
char s[MAXN];
int K;
int main()
{
    freopen("input.txt", "r", stdin);
    clr(last,0xff);
//    dbg(last[0]);
    scanf("%d%d",&n, &K);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s);
        for(int j = 1; j <= n; j++) if(s[j - 1] == '1') g[i][j] = 1; else g[i][j] = n + 1;
    }
    for(int i = 1; i <= n; i++) g[i][i] = 0;
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
        cmin(g[i][j], g[i][k] + g[k][j]);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) cout << g[i][j] << " ";
        cout << endl;
    }
    tot = 0;
    for(int i = 1; i <= n; i++) adde(i, n + i, 1, 0);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(i != j) if(g[i][j] <= K) adde(i + n, j, 1, -g[i][j]);
    des = 2 * n + 1;
    src = 0;
    adde(n + n, des, 2, 0);
    adde(0, 1, 2, 0);
    zkw(src, des, des + 3);
    printf("%d\n", cost);
}
