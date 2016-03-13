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
#define MP make_pair
#define AA first
#define BB second
#define PB push_back
#define SZ size()
#define dbg(x) cerr <<#x<<" = " << x << endl
const double PI = acos(-1.0);
const LL MOD = 105225319;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 1000 + 5;
int a[MAXN];
int b[MAXN];
LL f[MAXN][10];
LL dp[MAXN][1024];
int m2[11];
const int N = MAXN;
LL inv[N];
void init()
{
    inv[0] = inv[1] = 1;
    for(int i = 2; i < N; i++)
        inv[i] = ((MOD - MOD / i) * inv[MOD % i]) % MOD;
}
LL A(LL n,LL m)
{
    LL ret = 1;
    for(LL i = 1; i <= n; i++) ret = ret * i % MOD;
    for(LL i = 1; i <= n - m; i++) ret = ret * inv[i] % MOD;
    return ret;
}
int main()
{
    init();
    m2[0] = 1;
    for(int i = 1; i < 11; i++)
        m2[i] = m2[i - 1] * 2;
    int _T;
    scanf("%d",&_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        LL ans = 0;
        int tot = 0;
        int n;
        scanf("%d",&n);
        int x,y;
        FOR(i,n) scanf("%d%d",&a[i],&b[i]);
        FOR(i,n) if(a[i] != 1 || b[i] != n) tot++;
        if(tot <= 10)
        {
            clr(f,0);
            tot = 0;
            FOR(i,n) if(a[i] != 1 || b[i] != n)
            {
                for(int j = a[i]; j <= b[i]; j++) f[j][tot] = 1;
                tot++;
            }
//            cout << "F:" << endl;
//            FORR(i,n)
//            {
//                FOR(j,tot) cout << f[i][j];
//                cout << endl;
//            }
            clr(dp,0);
            dp[0][0] = 1;
            FOR(i,n) FOR(j,m2[tot]) if(dp[i][j])
            {
                FOR(k,tot) if(f[i + 1][k] && (j & m2[k]) == 0)
                {
                    dp[i + 1][j | m2[k]] = (dp[i + 1][j | m2[k]] + dp[i][j]) % MOD;
                }
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            }
            ans = 1;
            ans = ans * dp[n][m2[tot] - 1] % MOD;
            ans = ans * A(n,n - tot) % MOD;
        }
        printf("Case #%d: %I64d\n",CAS,ans);
    }
    return 0;
}
/*

2
2
1 2
1 2
2
1 1
2 2

*/
