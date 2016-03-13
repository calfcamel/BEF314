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
typedef pair<int, int> PII;
#define FOR(i,x) for(int i = 0, _END_ = (int)(x); i < _END_ ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 45;
char a[MAXN][MAXN];
int n,m;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};

int ex,ey;

inline bool hefa(int x, int y)
{
    if(x < 0 || x >= n) return false;
    if(y < 0 || y >= m) return false;
    return a[x][y] != '#';
//    return true;
}
int ans1,ans2,ans3;
int dfs(int x, int y, int d, int add, int cnt)
{
    if(x == ex && y == ey) return cnt;
    FOR(i,4)
    {
        int td = (d + 8 + add + add * (-1) * i) % 4;
        if(hefa(x + dx[td], y + dy[td])) return(dfs(x + dx[td], y + dy[td],td,add,cnt+1));
    }
}
queue<pair<PII, int> > Q;
int vis[45][45];
int bfs(int sx, int sy)
{
    int xx,yy;
    clr(vis,0);
    while(!Q.empty()) Q.pop();
    Q.push(MP(MP(sx,sy),1));
    int x,y,cnt;
    vis[sx][sy] = 1;
//    int tttt = 1;
    while(!Q.empty())
    {
//        tttt++;
        x = Q.front().AA.AA;
        y = Q.front().AA.BB;
        cnt = Q.front().BB;
        Q.pop();
//        if(tttt < 20) cout << x << " " << y << " " << cnt << endl;
        if(x == ex && y == ey) return cnt;
        FOR(i,4)
        {
            xx = x + dx[i];
            yy = y + dy[i];
            if(hefa(xx, yy) && !vis[xx][yy])
            {
                Q.push(MP(MP(xx,yy),cnt + 1));
                vis[xx][yy] = 1;
            }
        }
    }
}
int main()
{
    int _T;
    scanf("%d",&_T);
    while(_T--)
    {
        scanf("%d%d",&m,&n);
        FOR(i,n) scanf("%s",&a[i]);
        int sx,sy,sd;
        FOR(i,n) FOR(j,m) if(a[i][j] == 'E') {ex = i; ey = j;}
        FOR(i,n) FOR(j,m) if(a[i][j] == 'S')
        {
            sx = i;
            sy = j;
            FOR(k,4) if(hefa(sx + dx[k], sy + dx[k])) sd = k;
        }
        ans1 = dfs(sx,sy,sd,-1,1);
        ans2 = dfs(sx,sy,sd,1,1);
        ans3 = bfs(sx,sy);
        printf("%d %d %d\n", ans1, ans2, ans3);
    }
}
