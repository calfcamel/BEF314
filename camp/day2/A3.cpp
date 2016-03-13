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
#define AA firstx
#define BB second
#define PB push_back
#define SZ size()
#define dbg(x) cerr <<#x<<" = " << x << endl
#define all(x) x.begin(), x.end()
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int MAXN = 1000005;
int n;
LL m;
LL a[MAXN];
LL sa[MAXN];
LL b[MAXN];
LL sb[MAXN];
inline bool hefa(LL x)
{
    return x <= m && x >= 0;
}
LL now;
LL Max;
LL Min;
void init()
{
    now = 0;
    Max = 0;
    Min = 0;
}
bool add(LL x)
{
    now += x;
    LL befMax = Max;
    LL befMin = Min;
    if(now > 0) cmax(Max, now);
    if(now < 0) cmin(Min, now);
    if(Max - Min > m)
    {
        now -= x;
        Max = befMax;
        Min = befMin;
        return false;
    }
    return true;
}
int main()
{
    while(~scanf("%d%lld",&n,&m))
    {
        FORR(i,n) scanf("%lld",&a[i]);
        FORR(i,n) b[i] = 0;
        LL befc = 0;
        LL c = 0;
        int bao = n + 1;
        int befi = 0;
        FORR(i,n)
        {
            c += a[i];
            if(!hefa(c))
            {
                bao = i;
                break;
            }
        }
        c = 0;
        if(bao <= n) do
        {
            int nowi = bao;
            bao = n + 1;
            REP(i,befi + 1, nowi) c += a[i];
            init();
            REP(i,nowi + 1, n)
            {
                if(add(a[i]))
                {

                }
                else
                {
                    bao = i;
                    break;
                }
            }
//            dbg(c);
//            dbg(Min);
            b[nowi] = - c - Min;
            c += b[nowi];
            befi = nowi;
        }while(bao <= n);
        FORR(i,n - 1) printf("%lld ", b[i]);
        printf("%lld\n",b[n]);
    }
}
/*
5 3 1 2 3 3 3
5 5 3 0 5 -3 -2
8 3 1 2 3 -3 -3 3 2 -3
*/


