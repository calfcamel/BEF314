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
const int MAXN = 10;
char str[MAXN][MAXN];
int l[MAXN];
int ans;
int n,k;
void dfs(int i, int cnt)
{
    if(k == cnt)
    {
        ans++;
        return;
    }
    if(i == n) return;
    FOR(j,n) if(l[j] && str[i][j] == '#')
    {
        l[j] = 0;
        dfs(i + 1, cnt + 1);
        l[j] = 1;
    }
    dfs(i + 1, cnt);
}
int main()
{
    FOR(i,8) l[i] = 1;
    while(~scanf("%d%d",&n,&k))
    {
        if(n == -1) return 0;
        FOR(i,n) scanf("%s",&str[i]);
        ans = 0;
        dfs(0, 0);
        printf("%d\n", ans);
    }
}
