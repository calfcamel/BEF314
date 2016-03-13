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
const int MAXN = 25;

char str[MAXN];
int getd(char ch)
{
    if(ch == 'N') return 0;
    if(ch == 'E') return 1;
    if(ch == 'S') return 2;
    if(ch == 'W') return 3;
}
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
int a[MAXN][MAXN];
int vis[MAXN][MAXN];
int main()
{
    int n,m,st;
    while(scanf("%d%d%d",&n,&m,&st),n)
    {
        clr(a,-1);
        FORR(i,n)
        {
            scanf("%s",str);
            FORR(j,m) a[i][j] = getd(str[j - 1]);
        }
//        REP(i,0,n + 1)
//        {
//            REP(j,0, m + 1) printf("%d",a[i][j]); puts("");
//        }
        int x,y;
        x = 1;
        y = st;
        int cnt = 1;
        int flag = 0;
        int ans1,ans2;
        clr(vis,0);
        int tx,ty;
        while(1)
        {
            if(a[x][y] == -1)
            {
                flag = -1;
                ans1 = cnt - 1;
                break;
            }
            if(vis[x][y])
            {
                flag = 1;
                ans1 = vis[x][y] - 1;
                ans2 = cnt - vis[x][y];
                break;
            }
            vis[x][y] = cnt++;
            tx = x + dx[a[x][y]];
            ty = y + dy[a[x][y]];
            x = tx;
            y = ty;
        }
        if(flag == -1) printf("%d step(s) to exit\n",ans1);
        if(flag == 1) printf("%d step(s) before a loop of %d step(s)\n",ans1,ans2);
    }
}
