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
const int MAXM = 256;
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
int lab[MAXN];
int _next[MAXN][MAXM];
struct node
{
    LL ans;
    int now;
}dp[MAXN][MAXM];
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
    clr(lab, -1);
    clr(_next, -1);
    for(int i = n; i >= 0; i--)
    {
        FOR(j, MAXM)
        {
            _next[i][j] = lab[j];
//            if(~_next[i][j])cout << "_next " << i << " " << j << " " << _next[i][j] << endl;
        }
        lab[a[i]] = i;
    }
    FOR(l,n) FOR(j, MAXM) dp[l][j].ans = -1;
    FOR(j, MAXM)
    {
        if(~_next[0][j])
        {
            dp[0][j].ans = j;
            dp[0][j].now = _next[0][j];
//            cout << "UPD " << j << endl;
        }
    }
    LL tmp;
    int tmpnow;
    for(LL l = 0; l < n - 1; l++)
    {
        FOR(j, MAXM)
        {
            if(~dp[l][j].ans)
            {
//                cout << " L " << l << " " << j << endl;
                FOR(k, MAXM)
                {
                    if(~_next[dp[l][j].now][k])
                    {
                        tmp = (l + 1LL) ^ (LL)k;
                        tmp += dp[l][j].ans;
                        //cout << "TMP " << tmp << ' ';
                        //cout << j << ' ' << k << endl;
                        tmpnow = _next[dp[l][j].now][k];
                        if(tmp > dp[l + 1][k].ans)
                        {
                            dp[l + 1][k].ans = tmp;
                            dp[l + 1][k].now = tmpnow;
                        }
//                        if(tmp == dp[l + 1][k].ans)
//                        {
//                            cmin(dp[l + 1][k].now, tmpnow);
//                        }
                    }
                }
            }
        }
    }
    LL ans = 0;
    FOR(i, n) FOR(j, MAXM) cmax(ans, dp[i][j].ans);
    cout << ans << endl;
    return 0;
}
