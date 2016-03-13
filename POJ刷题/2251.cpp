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
const int MAXN = 30;
int l,n,m;
int sz,sx,sy;
int ez,ex,ey;
int a[MAXN][MAXN][MAXN];
int vis[MAXN][MAXN][MAXN];
const int dx[6] = {-1,1,0,0,0,0};
const int dy[6] = {0,0,-1,1,0,0};
const int dz[6] = {0,0,0,0,-1,1};
queue<pair<PII, PII> > Q;
bool hefa(int z, int x, int y)
{
    if(z < 0 || z >= l) return false;
    if(x < 0 || x >= n) return false;
    if(y < 0 || y >= m) return false;
    return a[z][x][y] && !vis[z][x][y];
}
int bfs()
{
    int x,y,z,cnt;
    while(!Q.empty()) Q.pop();
    clr(vis,0);
    Q.push(MP(MP(sz,sx),MP(sy,0)));
    vis[sz][sx][sy] = 1;
    while(!Q.empty())
    {
        z = Q.front().AA.AA;
        x = Q.front().AA.BB;
        y = Q.front().BB.AA;
        cnt = Q.front().BB.BB;
//        cout << z << " " << x << " " << y << " " << cnt << endl;
        Q.pop();
        if(z == ez && y == ey && x == ex) return cnt;
        FOR(i,6)
        {
            if(hefa(z + dz[i], x + dx[i], y + dy[i]))
            {
                vis[z + dz[i]][x + dx[i]][y + dy[i]] = 1;
                Q.push(MP(MP(z + dz[i], x + dx[i]),MP(y + dy[i], cnt + 1)));
            }
        }
    }
    return -1;
}
char str[33];
int main()
{
    while(scanf("%d%d%d",&l,&n,&m),l)
    {
        FOR(k,l) FOR(i,n)
        {
            scanf("%s",str);
            FOR(j,m)
            {
                if(str[j] == 'S') {sz = k; sx = i; sy = j;}
                if(str[j] == 'E') {ez = k; ex = i; ey = j;}
                if(str[j] == '#') a[k][i][j] = 0;
                else a[k][i][j] = 1;
            }
        }
//            cout << sz << sx << sy << endl;
//            cout << ez << ex << ey << endl;
        int ans = bfs();
        if(~ans) printf("Escaped in %d minute(s).\n", ans);
        else puts("Trapped!");
    }
}
