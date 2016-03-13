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
typedef pair<int, int> PII;
#define FOR(i,x) for(int i = 0, _END_ = (int)(x); i < _END_ ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int MAXN = 40;
LL C[MAXN][MAXN];
void init()
{
    FOR(i,MAXN)
    {
        FOR(j,i + 1)
        {
            if(j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}
LL calc(int cnt0, int cnt1, int l)
{
//    cout << "CALC " << cnt0 << " " << cnt1 << " " << l << endl;
    if(l == 0 && cnt0 + cnt1 > 0) return cnt0 >= cnt1 ? 1:0;
    LL ret = 0;
    if(cnt1 == 0)
    {
        cnt1 ++;
        l --;
        if(l < 0) return 0;
    }
    FOR(i, l + 1) if(i + cnt0 >= l - i + cnt1) ret += C[l][i];
//    cout << "\t = " << ret << endl;
    return ret;
}
LL a[40];
LL gao(LL x)
{
    if(x == 0) return 0;
    int lx = 0;
    int xx = x;
    while(x)
    {
        a[lx] = x % 2;
        x /= 2;
        lx++;
    }
    x = xx;
    LL ret = 0;
    FOR(i,lx) ret += calc(0,0,i);
//    cout << "bin: ";
//    for(int i = lx - 1; i >= 0; i--) cout << a[i];
//    cout << endl;
    int cnt0 = 0;
    int cnt1 = 1;
    for(int i = lx - 2; i >= 0; i--)
    {
        if(a[i])
        {
            cnt0++;
            ret += calc(cnt0,cnt1,i);
            cnt0--;
            cnt1++;
        }
        else cnt0++;
    }
    ret += calc(cnt0,cnt1,0);
    return ret;
}
int main()
{
    init();
//    dbg(calc(0,0,4));
//    LL x;
//    while(cin >> x)
//    {
//        cout << gao(x) << endl;
//    }
    LL l, r;
    cin >> l >> r;
    cout << gao(r) - gao(l - 1) << endl;
    return 0;
}
