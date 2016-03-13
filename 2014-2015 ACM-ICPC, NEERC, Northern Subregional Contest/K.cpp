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
typedef unsigned long long ULL;
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

const int T = 260;
LL f[T][T];
LL a[1005];
LL b[1005];
int main()
{
    freopen("kebab.in","r",stdin);
    freopen("kebab.out","w",stdout);
    LL n,t;
    scanf("%I64d%I64d",&n,&t);
    FOR(i,n) scanf("%I64d%I64d",&a[i],&b[i]);
    FOR(i,n) b[i] = a[i] - b[i];
//    FOR(i,n) cout << i << " " << a[i] << " " << b[i] << endl;
    clr(f,0);
    int now = 0;
    LL maxj;
    FOR(l,n)
    {
        FOR(i,T) FOR(j,T) if(j) f[i][0] = (f[i][0] + f[i][j]) % MOD;
        FOR(i,T) FOR(j,T) if(j) f[i][j] = 0;
        FOR(i,a[l])
        {
            now++;
            now %= T;
            FOR(j, T) f[now][j] = 0;
            maxj = min(b[l] + 1, (LL)T);
            FOR(j, maxj) if(j) f[now][j] = (f[now][j] + f[(now - t - 1 + T + T) % T][j - 1]) % MOD;
            if(1 < maxj) f[now][1] = (f[now][1] + 1) % MOD;
            FOR(j,T) f[(now - t + T + T) % T][j] = (f[(now - t + T + T) % T][j] + f[(now - t - 1 + T + T) % T][j]) % MOD;
            FOR(j,T) f[(now - t - 1 + T + T) % T][j] = 0;
//            cout << now << ": ";
//            FOR(j,10) cout << f[now][j] << " ";
//            cout << endl;
//            dbg(b[l]);
        }
    }
    LL ans = 1;
    FOR(i,t + 1) FOR(j,T)
        ans = (ans + f[(now - i + T + T) % T][j]) % MOD;
    cout << ans << endl;
    return 0;
}
