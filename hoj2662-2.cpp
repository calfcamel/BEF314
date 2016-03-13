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
#define cadd(x,y) if(! ~(x)) (x) = (y); else (x) += (y);
#define MP make_pair
#define AA first
#define BB second
#define PB push_back
#define SZ size()
#define dbg(x) cerr <<#x<<" = " << x << endl
#define FOR(i,x) for(int i = 0; i < (int)(x); i++)
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;


const int MAXN = 100000 + 5;
int n,m,c;
LL bin(LL x)
{
    LL ret = 2;
    FOR(i,m)
    {
        ret = ret * 10 + (x & 1);
        x >>= 1LL;
    }
    return ret;
}
LL bc[1 << 10];
LL dp[2][21][1 << 10];
int main()
{
    FOR(i,1 << 10) bc[i] = __builtin_popcount(i);
    while(scanf("%d%d%d", &n, &m, &c) != EOF)
    {
        if(m > n) swap(n, m);
        clr(dp, -1);
        dp[0][0][0] = 0;
        int cur = 0;
        int next = 1;

        FOR(i, n) FOR(j, m)
        {
            cout << i + j << " :" << endl;
            clr(dp[next], -1);
            FOR(k, c + 1)
            {
                FOR(bit, 1 << m) if(dp[cur][k][bit] >= 0)
                {
                    // fang
                    if(bc[bit & (1 << j) - 1] + k <= c)
                    if(k + 1 <= c && 0 == (bit & 1 << j))
                    {
                        if(j == 0 ||(j && 0 == (bit & 1 << (j - 1))))
                        {
                            cadd(dp[next][k + 1][bit | 1 << j], min(dp[cur][k][bit] + 1LL, 1LL));
                            cout << "FANG " << i + j << " k = " << k << " " << bin(bit) << " k = " << k + 1 << " " << bin(bit | 1 << j) << " " << dp[next][k + 1][bit | 1 << j] <<endl;
                        }
                    }
                    {
                        cadd(dp[next][k][bit & ~(1 << j)], dp[cur][k][bit]);
                        cout << "NOTF " << i + j << " k = " << k << " " << bin(bit) << " k = " << k << " " << bin(bit & ~(1 << j)) << " " << dp[next][k][bit & ~(1 << j)] << endl;
                    }
                }
            }
            swap(cur, next);
        }
        LL ans = 0;
        FOR(bit, 1 << m)
            if(~dp[cur][c][bit])
                ans +=dp[cur][c][bit];
        printf("%I64d\n",ans);
    }
    return 0;
}

