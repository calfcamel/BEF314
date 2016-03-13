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

LL S(LL n)
{
    LL ret = 0;
    while(n)
    {
        n /= 10;
        ret++;
    }
    return ret;
}
LL M(LL s)
{
    LL ret = 1;
    FOR(i,s) ret *= 10LL;
    return ret;
}
int main()
{
    LL w,m,k;
    cin >> w >> m >> k;
    w /= k;
    LL s = S(m);
    LL ans = 0;
    while(1)
    {
        if(s > 18) break;
        LL cnt = M(s) - m;
        if(cnt * s <= w)
        {
            w -= cnt * s;
            ans += cnt;
        }
        else
        {
            LL R = cnt;
            LL L = 0;
            while(L < R)
            {
                LL mid = (L + R) / 2 + (L + R) % 2;
                if(mid * s > w) R = mid - 1;
                else L = mid;
            }
            ans += L;
            w -= L * s;
            break;
        }
        m = M(s);
        s++;
    }
    cout << ans << endl;
}
