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

LL a[MAXN];
int main()
{
    LL n;
    scanf("%I64d",&n);
    LL maxnum = 0;
    FOR(i,n)
    {
        scanf("%I64d",&a[i]);
        cmax(maxnum, a[i]);
    }
    LL sum = 0;
    FOR(i,n)
    {
        sum += maxnum - a[i];
    }
    LL ans = 0;
    LL need = maxnum - sum;
//    dbg(need);
    if(need <= 0)
    {
        cout << maxnum << endl;
        return 0;
    }
    ans = (need + n - 2) / (n - 1);
    cout << maxnum + ans << endl;
    return 0;
}
