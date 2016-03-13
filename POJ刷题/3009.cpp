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
const int MAXN = 105;
int n,m;
int a[MAXN][MAXN];
int sx,sy;
int ex,ey;
int ans;
bool hefa(int x, int y)
{
    if(x < 0 || x >= n) return false;
    if(y < 0 || y >= m) return false;
    return true;
}
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
void dfs(int x,int y, int cnt)
{
//    cout << x << " " << y << " " << cnt << endl;
//    FOR(i,n)
//    {
//        FOR(j,m) cout << a[i][j];
//        cout << endl;
//    }
    if(cnt > 10) return;
    int tx,ty;
    FOR(i,4)
    {
//        dbg(i);
        tx = x + dx[i];
        ty = y + dy[i];
        if(hefa(tx,ty) && a[tx][ty] == 0) while(1)
        {
//            dbg(tx);
//            dbg(ty);
            if(!hefa(tx,ty)) break;
            if(tx == ex && ty == ey){cmin(ans, cnt); return;}
            if(hefa(tx + dx[i], ty + dy[i]) && a[tx + dx[i]][ty + dy[i]] == 1)
            {
                a[tx + dx[i]][ty + dy[i]] = 0;
                dfs(tx,ty,cnt + 1);
                a[tx + dx[i]][ty + dy[i]] = 1;
                break;
            }
            tx += dx[i];
            ty += dy[i];
        }
    }
}
int main()
{
    while(scanf("%d%d",&m,&n),n|m)
    {
        FOR(i,n) FOR(j,m) scanf("%d",&a[i][j]);
        FOR(i,n) FOR(j,m) if(a[i][j] == 2) {sx = i; sy = j; a[i][j] = 0;}
        FOR(i,n) FOR(j,m) if(a[i][j] == 3) {ex = i; ey = j; a[i][j] = 0;}
        ans = 50;
        dfs(sx,sy,1);
        if(ans == 50) ans = -1;
        printf("%d\n", ans);
    }
}
