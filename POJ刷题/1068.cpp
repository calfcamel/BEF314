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
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int MAXN = 100;
int a[MAXN];
int n;
int p[MAXN];
int w[MAXN];
int pre;
int tot;
int wtot;
int add(int x, int cnt)
{
    FOR(i,cnt) a[tot++] = x;
}
int ztot;
int z[MAXN];
void solve()
{
    scanf("%d",&n);
    FOR(i,n) scanf("%d",&p[i]);
    tot = 0;
    pre = 0;
    FOR(i,n)
    {
        add(0,p[i] - pre);
        add(1,1);
        pre = p[i];
    }
    wtot = 0;
    clr(w,0);
    FOR(i,tot) if(a[i])
    {
        int cnt = 0;
        for(int j = i; j >= 0; j--)
        {
            if(a[j]) cnt++;
            else
            {
                cnt--;
                w[wtot]++;
            }
            if(!cnt) break;
        }
        wtot++;
    }
    FOR(i,n - 1) printf("%d ",w[i]);
    printf("%d\n",w[n - 1]);
}
int main()
{
    int _T;
    scanf("%d",&_T);
    FOR(i,_T)
    {
        solve();
    }
}
