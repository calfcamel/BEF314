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

int main()
{
    LL n;
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        LL ans;
        if(n % 2 == 1) ans = (n + 1) / 2 * n;
        else ans = (n / 2) * (n + 1);
        LL x = 1;
        while(x <= n && x > 0)
        {
            ans = ans - 2 * x;
            x = x * 2;
        }
        cout << ans << endl;
    }
    return 0;
}
