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
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)

const int MAXN = 100000 + 5;
const int MAXM = 301;
char str[5];
int getnum()
{
    int ret = 0;
    if(str[0]>= '0' && str[0] <= '9') ret += 16 * (str[0] - '0');
    else ret += 16 * (str[0] - 'A' + 10);
    if(str[1]>= '0' && str[1] <= '9') ret += 1 * (str[1] - '0');
    else ret += 1 * (str[1] - 'A' + 10);
    return ret;
}
int a[MAXN];

LL dp[MAXN][MAXM];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s",str);
        a[i] = getnum();
//        cout << getnum() << endl;
    }
    clr(dp,0);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= i && j <= 300; j++)
        {
            if(j < i)dp[i][j] = max(dp[i][j], dp[i - 1][j] + (a[i] ^ ((LL)i - (LL)j - 1LL)));
            if(j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
//            cout << i << ' ' << j << " : " << dp[i][j] << endl;
        }
    }
    LL ans = 0;
    for(int j = 0; j <= n && j <= 300; j++)
        ans = max(ans, dp[n][j]);
    cout << ans << endl;
    return 0;
}

