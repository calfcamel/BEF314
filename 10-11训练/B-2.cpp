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
//#pragma comment(linker, "/STACK:102400000,102400000")
#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define cmaxmod(x,y) x = max((x) % MOD,(y) % MOD)
#define caddmod(x,y) x = ((x) + (y)) % MOD;
#define MP make_pair
#define AA first
#define BB second
#define PB push_back
#define SZ size()
#define dbg(x) cerr <<#x<<" = " << x << endl
#define FOR(x,y) for(int x = 0; x < (int)(y); x ++)
#define FORR(x,y) for(int x = 1; x <= (int)(y); x ++)
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;


const int MAXN = 100000 + 5;
const LL Linf = 10000000000000000LL;
int GCD(int a, int b){
	if(b==0)return a;
	return GCD(b,a % b);
}
int tot;
int a[1005];
LL dp[2][1001][1001];
int gcd[1001][1001];
int lcm[1001][1001];
int main()
{
//    int ma = 0;
//    FORR(i,1000)
//    {
//        int tot = 0;
//        FORR(j,i) if(i % j == 0) tot++;
//        cout << i << " " << tot << endl;
//        ma = max(ma, tot);
//    }
//    cout << ma << endl; // ma = 32
    FORR(i,1000) FORR(j,1000) gcd[i][j] = GCD(i,j);
    FORR(i,1000) FORR(j,1000) lcm[i][j] = i * j / gcd[i][j];
//    FORR(i,1000) lcm[i][0] = i;
//    FORR(i,1000) lcm[0][i] = i;
    int n,m,s;
    while(scanf("%d%d%d",&n,&m,&s)!= EOF)
    {
        tot = 0;
        FORR(i,m) if(m % i == 0) a[tot++] = i;
//        cout << tot << endl;
        clr(dp,0);
        dp[0][0][1] = 1;
        int cur = 0;
        int next = 1;
        FOR(k,s)
        {
            for(int v = 0; v <= n; v++) FOR(l,tot) dp[next][v][a[l]] = 0;
            FOR(i,tot) for(int v = n; v >= a[i]; v --) FOR(l,tot)
            {
                dp[next][v][lcm[a[l]][a[i]]] += dp[cur][v - a[i]][a[l]];
                //dp[next][v][lcm[a[l]][a[i]]] = (dp[next][v][lcm[a[l]][a[i]]] + dp[cur][v - a[i]][a[l]]) % MOD;
                //if(dp[next][v][lcm[a[l]][a[i]]] > Linf) dp[next][v][lcm[a[l]][a[i]]] %= MOD;
            }
            for(int v = 0; v <= n; v++) FOR(l,tot)
                dp[next][v][a[l]] %= MOD;
            swap(cur, next);
        }
        printf("%lld\n",dp[cur][n][m] % MOD);
    }
    return 0;
}
