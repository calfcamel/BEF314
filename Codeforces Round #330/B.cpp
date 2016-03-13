
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

const int MAXN = 1000000 + 5;

const LL x[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int n;
int a[MAXN];
int b[MAXN];
LL solve(LL a, LL b, LL k)
{
    LL ret,tmp;
    ret = (x[k] - 1) / a + 1;
//    dbg(ret);
    if(k == 1)
    {
        if(b % a == 0) ret--;
    }
    else
    {
        tmp = (x[k - 1] * (b + 1) - 1) / a;
        if(b) tmp -= (x[k - 1] * b - 1) / a;
        ret -= tmp;
        if(b == 0) ret --;
    }
//    cout << ret << endl;
    return ret;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    FOR(i,n / k) scanf("%d",&a[i]);
    FOR(i,n / k) scanf("%d",&b[i]);
    LL ans = 1;
    FOR(i,n / k) ans = ans * solve(a[i],b[i],k) % MOD;
    cout << ans << endl;
    return 0;
}
