
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
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
#define LL long long

LL dist[3000][3000];
LL g[3000][3000];
char s[3000];
int n;

deque<PII>Q;
bool vis[3000];
void cal(int x)
{
    memset(vis, 0, sizeof vis);
    Q.clear();
    Q.push_back(MP(x, 0));
    vis[x] = true;
    while(Q.SZ)
    {
        PII p = Q.front();
        dist[x][p.AA] = p.BB;
        Q.pop_front();
        for(int i = 1; i <= n; i++) if(g[p.AA][i] && !vis[i])
            {
                Q.push_back(MP(i, p.BB + 1));
                vis[i] = true;
            }
    }
}

int main()
{
    scanf("%d", &n);
    memset(g, 0, sizeof g);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        for(int j = 0; j < n; j++) if(s[j] == '1') g[i][j + 1] = 1;
    }
    for(int i = 1; i <= n; i++) for(int j = 0; j <= n; j++) dist[i][j] = n;
    for(int i = 1; i <= n; i++) dist[i][i] = 0;
    for(int i = 1; i <= n; i++) cal(i);
    LL ans = 0;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) ans += dist[i][j] * dist[i][j];
    printf("%I64d\n", ans);
    return 0;
}
