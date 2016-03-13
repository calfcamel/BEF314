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
typedef unsigned long long ULL;
//#pragma comment(linker, "/STACK:102400000,102400000")
#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define ccmin(x,y) if(x == -1) x = y; else x = min(x,y)
#define MP make_pair
#define AA first
#define BB second
#define PB push_back
#define SZ size()
#define dbg(x) cerr <<#x<<" = " << x << endl
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 100 + 2;

vector<int> v[MAXN];
void add(int x,int y)
{
    v[x].PB(y);
    v[y].PB(x);
}
LL dp[2][MAXN];
int main()
{
    int n,m,s,t;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&s);
    scanf("%d",&t);
    int x,y;
    FOR(i,m)
    {
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    clr(dp,0);
    int cur = 0;
    int next = 1;
    dp[cur][s] = 1;
    FOR(ii,t)
    {
        clr(dp[next],0);
        FOR(i,n)
        {
            FOR(j,v[i].SZ)
            {
                dp[next][v[i][j]] += dp[cur][i];
            }
        }
        swap(cur, next);
    }
    LL ans = 0;
    FOR(i,n) ans += dp[cur][i];
    cout << ans << endl;
    return 0;
}
