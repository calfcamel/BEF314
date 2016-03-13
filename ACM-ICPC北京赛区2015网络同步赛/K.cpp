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
const LL MOD = 105225319;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
LL g[65537];
LL gg[2][65537];
LL g655[65][65540];
//LL g257[62][65537];
LL calcans(LL top, LL deep, LL k)
{
//    if(k == 257LL)
//    {
//        FOR(i,k) g[i] += g655[deep][(i * top) % k];
//        return 0;
//    }
    if(k == 65537LL)
    {
        FOR(i,k) g[i] += g655[deep][(i * top) % k];
        return 0;
    }
    deep++;
//    cout << "!!!!!!!!!!!!!!!!CALC ANS " << deep << endl;
    clr(gg,0);
    int cur = 0;
    int next = 1;
    gg[cur][top] = 1;
    LL tmp = 0;
    FOR(j,deep)
    {
        FOR(i,k)
        {
            g[i] += gg[cur][i];
            gg[next][(i * 3) % k] += gg[cur][i];
            gg[next][(i * 3 + 1) % k] += gg[cur][i];
            gg[cur][i] = 0;
            tmp += gg[cur][i];
        }
        swap(cur, next);
    }
//    cout << "!!!!!!!!!!!!!!!!CALC ADD " << tmp << endl;
//    FOR(i,k) g[i] += gg[cur][i];
}
LL calcansinit(LL top, LL deep, LL k)
{
    deep++;
//    cout << "!!!!!!!!!!!!!!!!CALC ANS " << deep << endl;
    clr(gg,0);
    int cur = 0;
    int next = 1;
    gg[cur][top] = 1;
    LL tmp = 0;
    FOR(j,deep)
    {
        FOR(i,k)
        {
            for(int p = j - 1; p <= deep; p++)g655[p][i] += gg[cur][i];
            gg[next][(i * 3) % k] += gg[cur][i];
            gg[next][(i * 3 + 1) % k] += gg[cur][i];
            gg[cur][i] = 0;
            tmp += gg[cur][i];
        }
        swap(cur, next);
    }
//    cout << "!!!!!!!!!!!!!!!!CALC ADD " << tmp << endl;
//    FOR(i,k) g[i] += gg[cur][i];
}
LL init655()
{
    clr(g655,0);
    calcansinit(1LL,60LL,65537LL);
}
LL a[100];
LL sum[100];
LL MAXM2 = 62;
//LL ___tot = 0;
void calc(LL top, LL n, LL k)
{
    LL ltop = top * 3 % k;
    LL rtop = (ltop + 1) % k;
//    ___tot ++;
//    if(___tot< 50) cout << "CALC " << n << endl;
    if(n == 0) return;
    g[top]++;
    if(n == 1) return;
    if(n == 2)
    {
        g[ltop]++;
        return;
    }
    if(n == 3)
    {
        g[ltop]++;
        g[rtop]++;
        return;
    }
//    cout << "no return" << endl;
    for(int i = MAXM2 - 1; i >= 0; i--) if(n >= sum[i])
    {
        LL tmp = n - sum[i];
//        if(___tot < 50) dbg(tmp);
//        dbg(sum[i]);
        if(tmp <= a[i])
        {
            calcans(rtop, i - 1, k);
//            if(___tot < 50) cout << "\tGOA" << n - 1LL - sum[i - 1] << endl;
//            if(___tot < 50) cout << "\tn = " << n << " sum[" << i - 1 << "]" << endl;
            calc(ltop, n - 1LL - sum[i - 1], k);
        }
        else
        {
            calcans(ltop, i, k);
//            if(___tot < 50) cout << "\tGO" << n - 1LL - sum[i] << endl;
//            if(___tot < 50) cout << "\tn = " << n << " sum[" << i << "]" << endl;
            calc(rtop, n - 1LL - sum[i], k);
        }
        break;
    }
}
LL gao(LL n, LL k)
{
    FOR(i,k) g[i] = 0;
    calc(1LL, n, k);
    LL ret = 0;
    FOR(i, k) ret ^= g[i];
//    cout << "\tG:" << endl;
//    FOR(i,k) cout << g[i] << " ";
//    cout << endl;
    return ret;
}
int main()
{
    init655();
//    return 0;
    a[0] = 1;
    for(int i = 1; i < MAXM2; i++)
        a[i] = a[i - 1] * 2LL;
    sum[0] = 1;
    for(int i = 1; i < MAXM2; i++)
        sum[i] = sum[i - 1] + a[i];
    int _T;
    scanf("%d",&_T);
    while(_T--)
    {
        LL n,k;
        scanf("%I64d%I64d",&n,&k);
        if(k > 3)
            printf("%I64d\n",gao(n,k));
        else printf("%I64d\n",(n / 2LL)^(n - n / 2LL));
    }
    return 0;
}

