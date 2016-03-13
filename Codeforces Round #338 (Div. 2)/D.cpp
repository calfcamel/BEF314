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
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int MAXN = 200000 + 5;
int a[MAXN];
int b[MAXN];
int cnt[MAXN];
LL c[MAXN];
LL sum1[MAXN];
LL sum2[MAXN];
LL calc(LL a, LL b)
{
    LL ret = 1;
    b = b * (b + 1LL) / 2LL;
    while(b)
    {
        if(b & 1) ret = ret * a % MOD;
        b >>= 1LL;
        a = a * a % MOD;
    }
    return ret;
}
int main()
{
    int n;
    scanf("%d",&n);
    FOR(i,n) scanf("%d",&a[i]);
    LL ans = 1;
    LL now = 1;
    sort(a, a + n);
    int tot = 0;
    FOR(i,n)
    {
        if(i == 0)
        {
            b[tot] = a[i];
            cnt[tot] = 1;
            tot++;
        }
        else if(b[tot - 1] == a[i]){
            cnt[tot - 1] = ++;
        }
        else
        {
            b[tot] = a[i];
            cnt[tot] = 1;
            tot++;s
        }
    }
    n = tot;
    FOR(i,n) c[i + 1] = (calc(b[i],cnt[i]) + 1LL) % MOD;
    sum1[0] = 1;
    FORR(i,n) sum1[i] = sum1[i - 1] * c[i] % MOD;
    FOR(i,n)
}
