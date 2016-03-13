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

const int inf = 100000000;

int n,m,k;
int d[55][55];
int p[10];
int t[10];
int ft[10];
int l[10];
int f[10][55];
int piao[55];
int isatt[55];
void floyd()
{
    FORR(k,n) FORR(i,n) FORR(j,n) cmin(d[i][j], d[i][k] + d[k][j]);
}
int dp[2][1 << 8][1 << 8][55];
void dp()
{
    int st_ed = (1 << k) - 1;
    clr(dp,-1);
    int cur = 0;
    dp[cur][0][0][1] = 0;
}
int main()
{
    int _T;
    int x,y,z;
    scanf("%d",&_T);
    FORR(CAS,_T)
    {
        scanf("%d%d%d",&n,&m,&k);
        FORR(i,n) FORR(j,n) d[i][j] = inf;
        FORR(i,n) d[i][i] = 0;
        FOR(i,m) {scanf("%d%d%d",&x,&y,&z);d[x][y] = z; d[y][x] = z;}
        clr(isatt,-1);
        clr(piao,0);
        FOR(i,k)
        {
            scanf("%d%d%d%d",&p[i],&t[i],&ft[i],&l[i]);
            isatt[p[i]] = k;
            FOR(j,l[i])
            {
                scanf("%d",&f[i][j]);
                piao[f[i][j]] |= 1 << k;
            }
        }
        floyd();
        dp();
        printf("Case #%d: %d\n",CAS,ans);
    }
}
