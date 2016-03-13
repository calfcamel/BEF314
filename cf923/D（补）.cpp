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
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;


const int MAXN = 10000 + 5;
LL dp[262144 * 2][19];
LL e[18][18];
LL a[18];
int b[19];
int n,m,x,y,z,k;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < n; i++)
        scanf("%I64d",&a[i]);
    clr(e, 0);
    clr(dp, 0);
    for(int i = 0; i < k; i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        e[x - 1][y - 1] = z;
    }
    b[0] = 1;
    for(int i = 1; i <= 18; i++)
        b[i] = b[i - 1] * 2;
    for(int i = 0; i < n; i++)
        dp[b[i]][i] = a[i];
    for(int mask = 0; mask < b[n]; mask++)
        for(int i = 0; i < n; i++)
            if(mask & b[i])
            {
                for(int j = 0; j < n; j++)
                    if((mask & b[j]) == 0)
                        dp[mask | b[j]][j] = max(dp[mask | b[j]][j], dp[mask][i] + e[i][j] + a[j]);
            }
    LL ans = 0;
    for(int mask = 0; mask < b[n]; mask++)
        if(__builtin_popcount(mask) == m)
        {
            for(int i = 0; i < n; i++)
                ans = max(ans, dp[mask][i]);
        }
    cout << ans << endl;
    return 0;
}
