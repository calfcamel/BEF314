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
const int MAXN = 200005;
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
    while(~scanf("%d%I64d",&n,&m))
    {
        FORR(i,n) scanf("%I64d",&a[i]);
        FORR(i,n) b[i] = 0;
        /// NO
        LL c = 0;
        int bao = n + 1;
        FORR(i,n) if(hefa(c + a[i])) c += a[i]; else {bao = i; break;}
        c += a[bao];
        c = 0;
        int befi = 0;
        do
        {
//            LL befc = c;
////            dbg(befc);
//            dbg(bao);
            int i = bao;
            REP(j,befi,i - 1) c += a[i];
            bao = n + 1;
            init();
            REP(j, i + 1, n) if(add(a[j]))
            {
//
            }
            else
            {
                bao = j;
                break;
            }
            cout << "ADD " << "" << " " << now << " " << Max << " " << Min << endl;
            b[i] = - c - Min;
            c = now + b[i];
            dbg(c);
            befi = i;
        } while(bao <= n);
        FORR(i,n - 1) printf("%I64d ", b[i]);
        printf("%I64d\n",b[n]);
    }
}
/*
5 3 1 2 3 3 3
5 5 3 0 5 -3 -2

*/

