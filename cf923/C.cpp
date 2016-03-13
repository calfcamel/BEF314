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
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;


const int MAXN = 100000 + 5;
vector<int>G[MAXN];
int c[MAXN];
int fa[MAXN];
int n, m;

int dfs(int x, int cnt)
{
    if(c[x]) cnt++; else cnt = 0;
    if(cnt > m) return 0;
    if(G[x].SZ == 1 && G[x][0] == fa[x]) return 1;
    int tot = 0;
    for(int i = 0; i < G[x].SZ; i++)
    if(G[x][i] != fa[x])
    {
        fa[G[x][i]] = x;
        tot += dfs(G[x][i], cnt);
    }
    return tot;
}

int main()
{
    int p = 0;
    p++;
    if(p)scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for(int i = 1; i <= n; i++) G[i].clear();
    for(int i = 1; i < n; i++)
    {
        int x, y; scanf("%d%d", &x, &y);
        G[x].PB(y); G[y].PB(x);
    }
    cout << dfs(1, 0) << endl;
	return 0;
}
