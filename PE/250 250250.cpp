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
const int MAXN = 1005;
LL MOD16 = 10000000000000000LL;
LL MOD3 = 1000;
LL ADD3(LL a, LL b)
{
    return (a + b) % MOD3;
}
LL MUL3(LL a, LL b)
{
    return (a * b) % MOD3;
}
LL MI3(LL a, LL b)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1LL) ret = ret * a % MOD3;
        a = a * a % MOD3;
        b >>= 1LL;
    }
    return ret;
}
LL ADD16(LL a, LL b)
{
    return (a + b) % MOD16;
}
LL MUL16(LL a, LL b)
{
//    cout << "MUL16 " << a << " " << b << endl;
    LL ret = 0;
    LL bit;
    LL mul = 1;
    LL tmp;
    while(b)
    {
//        dbg(a);
//        dbg(b);
        if(mul == MOD) break;
        bit = b % 10;
//        dbg(bit);
        a = a % (MOD16 / mul);
//        dbg(a);
        tmp = a * bit * mul;
//        dbg(tmp);
        ret = ADD16(ret, tmp);
//        dbg(ret);
        b = b / 10;
//        dbg(b);
        mul *= 10;
//        dbg(mul);
//        cout << "  " << endl;
    }
//    cout << "EXIT MUL" << endl;
    return ret;
}
LL MI16(LL a, LL b)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1LL) ret = MUL16(ret, a);
        a = MUL16(a, a);
        b >>= 1LL;
    }
    return ret;
}
int cnt[1000];
LL a[250];
LL b[250];
void gao(int x)
{
    FOR(i,250) b[i] = ADD16(a[i], a[(i - x + 250) % 250]);
    FOR(i,250) a[i] = b[i];
    a[x] = ADD16(a[x],1LL);
}
int main()
{
//    LL ans = 0;
//    dbg(MI16(20LL,20LL));
//    for(int i = 1; i <= 25025; i++) ans = ADD16(ans,MI16(10LL * i, 10LL * i));
//    cout << ans << endl;
    clr(cnt,0);
    for(int i = 1; i <= 250250; i++) cnt[MI3(i,i) % 250]++;
//    FOR(i,250) cout << "cnt[" << i << "] = " << cnt[i] << endl;
    clr(a,0);
    FOR(i,250) FOR(j,cnt[i]) gao(i);
    cout << a[0] << endl;
    FOR(i,250) cout << "a[" << i << "] = " << a[i] << endl;
}


