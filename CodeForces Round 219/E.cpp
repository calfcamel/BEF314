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
#include <iomanip>
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
#define REP(i,x,y) for(int i = x,  _END_ = (int)(y); i <= _END_ ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)


LL dp[2][150005];
int main()
{
    LL n,m;
    LL d;
    scanf("%I64d%I64d%I64d",&n,&m,&d);
    int cur = 0;
    clr(dp,0);
    LL a,b,t;
    LL pret = -250000;
    LL L, R;
    LL ans = 0;
    FOR(l,m)
    {
        deque<pair<LL, int> > Q;
        scanf("%I64d%I64d%I64d",&a,&b,&t);
        ans += b;
        L = 1LL - (t - pret) * d;
        R = 1LL + (t - pret) * d;
        REP(i,max(L,1LL),min(R,n))
        {
            while(!Q.empty() && -Q.back().AA > dp[cur][i]) Q.pop_back();
            Q.push_back(MP(-dp[cur][i],-i));
        }
        clr(dp[cur ^ 1], 0);
        FORR(i,n)
        {
            dp[cur ^ 1][i] = -Q.front().AA + abs(a - i);
            L += 1LL;
            if(L > 0) while(!Q.empty() && -Q.front().BB < L) Q.pop_front();
            if(R < n)
            {
                R++;
                while(!Q.empty() && -Q.back().AA > dp[cur][R]) Q.pop_back();
                Q.push_back(MP(-dp[cur][R],-R));
            }
        }
        pret = t;
        cur ^= 1;
    }
    LL tmp = dp[cur][1];
    FORR(i,n) cmin(tmp, dp[cur][i]);
    cout << ans - tmp << endl;
}
