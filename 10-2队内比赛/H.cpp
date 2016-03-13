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
//#define MY_DEBUG
//#define FILE_DEBUG
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
const LL three_two = (MOD / 2LL + 1LL) * 3LL % MOD;

const int MAXN = 100000 + 5;

LL qpow(LL x, LL y)
{
    LL ret = 1;
    if(y < 0) return ret;
    while(y)
    {
        if(y & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        y = y >> 1LL;
    }
    return ret;
}

int a[MAXN];
LL ans = 0;
LL maxf = 0;
LL cnt0 = 0;
LL cnt1 = 0;
LL cnt2 = 0;
LL minz = 0;
LL cntf = 0;
LL n,m;
LL need;
void calc()
{
    if(m <= 1) return;
    if(m == 2)
    {
        ans = ans * 2LL % MOD;
        m = 0;
        return;
    }
    if(m == 3)
    {
        ans = ans * 3LL % MOD;
        m = 0;
        return;
    }
    m = m - 4;
    need = m / 3;
    ans = ans * qpow(3, need) % MOD;
    m = m % 3;
    if(m == 0) ans = ans * 2LL % MOD * 2LL % MOD;
    if(m == 1) ans = ans * 2LL % MOD * 3LL % MOD;
    if(m == 2) ans = ans * 3LL % MOD * 3LL % MOD;
    m = 0;
}
void solve()
{
    if(cntf)
    {
        need = -maxf;
        if(m >= need)
        {
            m -= need;
            cnt0++;
        }
        else
        {
            maxf += m;
            ans = ans * maxf % MOD;
            m = 0;
        }
    }
    else
    {
        if(maxf != 0)
        {
            ans = ans * maxf % MOD;
        }
    }
    if(m == 0) return;
#ifdef MY_DEBUG
    cout << "cnt0 = " << cnt0 << " m = " << m << endl;
#endif MY_DEBUG
    if(cnt0)
    {
        need = cnt0;
        if(m >= need)
        {
            m -= need;
            cnt1 += need;
            cnt0 = 0;
        }
        else
        {
            // sui bian la ..
            m = 0;
            ans = 0;
        }
    }
    if(m == 0) return;
#ifdef MY_DEBUG
    cout << "cnt1 = " << cnt1 << " m = " << m << endl;
#endif MY_DEBUG
    if(cnt1)
    {
        need = cnt1;
        if(m >= need)
        {
            m -= need;
            cnt2 += need;
            cnt1 = 0;
        }
        else
        {
            need = m;
            m = 0;
            cnt2 += need;
            cnt1 -= need;
        }
    }
    if(m == 0) return;
#ifdef MY_DEBUG
    cout << "cnt2 = " << cnt2 << " m = " << m << endl;
#endif MY_DEBUG
    if(cnt2)
    {
        need = cnt2;
        if(m >= need)
        {
            ans = ans * qpow(3, need - 1) % MOD;
            m -= need - 1;
            cnt2 = 1;
        }
        else
        {
            ans = ans * qpow(2,need) % MOD;
            need = m;
            ans = ans * qpow(three_two, need) % MOD;
            m = 0;
            cnt2 = 0;
        }
    }
    if(m == 0) return;
    if(cnt2) m += 2LL;
    cnt2 = 0;
    //calc(m);

#ifdef MY_DEBUG
    cout << "before calc - ans = " << ans << " m = " << m << endl;
#endif MY_DEBUG
    if(m > 1)
    {
        calc();
    }
#ifdef MY_DEBUG
    cout << " end   calc - ans = " << ans << " m = " << m << endl;
#endif MY_DEBUG
}
int main()
{
#ifdef FILE_DEBUG
    freopen("input.txt","r",stdin);
#endif // FILE_DEBUG
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        scanf("%I64d %I64d",&n,&m);
        ans = 1;
        maxf = 0;
        cnt0 = 0;
        cnt1 = 0;
        cnt2 = 0;
        minz = 0;
        cntf = 0;
        LL x;
        for(int i = 0; i < n; i++)
        {
            scanf("%I64d",&x);
            if(x == 0) cnt0++;
            if(x == 1) cnt1++;
            if(x == 2) cnt2++;
            if(x < 0)
            {
                cntf++;
                if(maxf == 0)
                {
                    maxf = x;
                }
                else
                {
                    if(maxf < x)
                    {
                        ans = maxf % MOD * ans % MOD;
                        maxf = x;
                    }
                    else
                    {
                        ans = x % MOD * ans % MOD;
                    }
                }
            }
            if(x > 2)
            {
                if(minz == 0)
                {
                    minz = x;
                }
                else
                {
                    if(minz > x)
                    {
                        ans = minz % MOD * ans % MOD;
                        minz = x;
                    }
                    else
                    {
                        ans = x % MOD * ans % MOD;
                    }
                }
            }
        }
        cntf &= 1LL;
        solve();
        if(cnt0) ans = 0;
        if(cnt2) ans = ans * qpow(2LL, cnt2) % MOD;
        if(m == 1) minz++;
        if(minz != 0) ans = ans * minz % MOD;
        printf("Case %d: %I64d\n",CAS, ans);
    }
    return 0;
}
