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
LL dpa[MAXN];
LL dpb[MAXN];
int main()
{
    LL n, a, b;
    cin >> n >> a >> b;
    clr(dpa, 0);
    clr(dpb, 0);
    dpa[0] = 1;
    dpb[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        FOR(j,a) if(i - j - 1 >= 0) dpa[i] = (dpa[i] + dpb[i - j - 1]) % MOD;
        FOR(j,b) if(i - j - 1 >= 0) dpb[i] = (dpb[i] + dpa[i - j - 1]) % MOD;
    }
//    for(int i = 1; i <= n; i++)
//        cout << i << ": " << dpa[i] << " " << dpb[i] << endl;
    LL ans = dpb[n] + dpa[n];
    ans %= MOD;
    cout << ans << endl;
    return 0;
}
