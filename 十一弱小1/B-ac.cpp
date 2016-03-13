
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


const int MAXN = 200000 + 5;

LL ans = 0;
LL a[MAXN];
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {

        for(int i = 0; i < n; i++)
        {
            scanf("%lld",&a[i]);
        }
        ans = 0;
        LL now;
        for(LL mod = 1000000000; mod > 1; mod /= 10)
        {
            for(int i = 0; i < n; i++) a[i] %= mod;
            sort(a,a + n);
            for(LL i = 0; i < n; i++)
            {
                now = lower_bound(a, a + n, mod - a[i]) - a;
//                cout << "mod = " << mod << " i = " << i << " a[i]= "<< a[i] << " " << now << " add " << min(n - i - 1, n ==now ? 0:n - now + 1) <<endl;
                if(now != n) ans += min(n - i - 1, n - now);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
