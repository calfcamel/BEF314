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
const LL MOD = 100000007;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 15000 + 5;
int n,k,s;
LL dp[2][MAXN];
LL sum;
int main()
{
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        scanf("%d%d%d",&n,&k,&s);
        clr(dp,0);
        int cur = 0;
        int next = 1;
        dp[cur][0] = 1;
        FORR(i,n)
        {
            clr(dp[next],0);
            sum = 0;
            FOR(j,s + 1)
            {
                if(j > k) sum += MOD - dp[cur][j - k - 1]; sum %= MOD;
                dp[next][j] += sum; dp[next][j] %= MOD;
                sum += dp[cur][j]; sum %= MOD;
            }
            swap(cur,next);
        }
        printf("Case %d: %lld\n",CAS,dp[cur][s]);
    }
    return 0;
}
