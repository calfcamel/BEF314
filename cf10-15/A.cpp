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
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
const int MAXN = 1000000 + 5;

int main()
{
    LL x,y;
    LL ans = 0;
    int n;
    cin >> n;
    LL m;
    FOR(i,n)
    {
        cin >> x >> y;
        if(!i) m = y;
        m = min(m, y);
        ans = ans + m * x;
    }
    cout << ans << endl;
}
