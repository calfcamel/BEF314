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
#define LL long long
const int MAXN = 100001;
int tot;
int dp[MAXN];
int a[MAXN];
void add(int num, int v)
{
    a[tot++] = num * v;
}
int main()
{
    int V;
    while(~scanf("%d",&V))
    {
        int m;
        tot = 0;
        scanf("%d",&m);
        int num,v,now;
        FOR(i,m)
        {
            scanf("%d%d",&num,&v);
            now = 1;
            while(num)
            {
                if(num <= now)
                {
                    add(num, v);
                    break;
                }
                num -= now;
                add(now, v);
                now *= 2;
            }
        }
        int n = tot;
        clr(dp,0);
        dp[0] = 1;
        FOR(i,n) for(int j = V; j >= a[i]; j--) if(dp[j - a[i]]) dp[j] = 1;
        int ans = 0;
        FORR(j,V) if(dp[j]) ans = j;
        printf("%d\n",ans);
    }
}
