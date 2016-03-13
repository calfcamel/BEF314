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
const int dx[8] = {-1,1,-2,2,-2,2,-1,1};
const int dy[8] = {-2,-2,-1,-1,1,1,2,2};
char str[200];
bool flag;
int n,m;
int vis[20][20];
inline bool hefa(int x, int y)
{
    if(x < 0 || x >= n) return false;
    if(y < 0 || y >= m) return false;
    return true;
}
void dfs(int k, int x, int y)
{
//    cout << k << " " << x << " " << y << endl;
    if(flag) return;
    if(k == n * m)
    {
        flag = true;
        return;
    }
    if(hefa(x,y) && !vis[x][y])
    {
        vis[x][y] = 1;
        str[2 * k] = 'A' + y;
        str[2 * k + 1] = '1' + x;
        FOR(i,8) dfs(k + 1, x + dx[i], y + dy[i]);
        if(flag) return;
        vis[x][y] = 0;
    }
}
int main()
{
    int _T;
    scanf("%d",&_T);
    FORR(CAS,_T)
    {
        scanf("%d%d",&n,&m);
        printf("Scenario #%d:\n",CAS);
        flag = false;
        clr(str,0);
        clr(vis,0);
        dfs(0,0,0);
        if(flag) puts(str);
        else puts("impossible");
        puts("");
    }
}
