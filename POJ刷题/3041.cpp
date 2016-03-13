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
#include <iomanip>
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
typedef pair<int, int> PII;
#define FOR(i,x) for(int i = 0, _END_ = (int)(x); i < _END_ ; i++)
#define REP(i,x,y) for(int i = x,  _END_ = (int)(y); i <= _END_ ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int N = 505 * 2;
const int M = N * N;
int n,m;
struct node
{
    int v;
    int nxt;
}E[M];
int tot;
int h[M];
int vis[N];
int link[N];
void init()
{
    tot = 0;
    clr(h, -1);
}
void add(int u,int v)
{
    E[tot].v = v;
    E[tot].nxt = h[u];
    h[u] = tot++;
}
bool dfs(int u)
{
    for(int i = h[u]; ~i; i = E[i].nxt)
    {
        int v = E[i].v;
        if(!vis[v])
        {
            vis[v] = 1;
            if(link[v] == -1 || dfs(link[v]))
            {
                link[v] = u;
                return true;
            }
        }
    }
    return false;
}

int match()
{
    int ans = 0;
    clr(link, -1);
    FOR(i,n)
    {
        clr(vis,0);
        if(dfs(i)) ans++;
    }
    return ans;
}
int main()
{
    init();
    scanf("%d%d",&n,&m);
    int x,y;
    FOR(i,m)
    {
        scanf("%d%d",&x,&y);
        add(x - 1,y + n - 1);
    }
    n *= 2;
    cout << match() << endl;
}
/*
3 4
1 1
1 3
2 2
3 2
*/
