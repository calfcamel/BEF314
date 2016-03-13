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
//LL tiaokong(int x)
//{
//    LL Max = 0;
//    LL Min = 0;
//    LL ret = 0;
//    REP(i,x + 1,y)
//}
int main()
{
    while(~scanf("%d%lld",&n,&m))
    {
        FORR(i,n) scanf("%lld",&a[i]);
        a[0] = 0;
        sa[0] = 0;
        FORR(i,n) sa[i] = sa[i - 1] + a[i];
        FORR(i,n) b[i] = 0;
        LL c = 0;
        LL Max = 0;
        LL Min = 0;
        int bef = 0;
        LL sum = 0;
        FORR(i,n)
        {
            sum += a[i];
            if(sum > c) cmax(Max, sum - c);
            if(sum < c) cmin(Min, c - sum);
            dbg(i);cout << Max << " " << Min << endl;
            if(Max - Min > m)
            {
                LL tmpinit = -(c + sa[i] - sa[bef]); /// become 0
                LL tmp = tmpinit;
                dbg(tmp);
                Max = 0;
                Min = 0;
                LL tmpc = 0;
                LL sum = 0;
                REP(j,i + 1,n)
                {
                    sum += a[j];
                    if(sum > tmpc) cmax(Max, sum - tmpc);
                    if(sum < tmpc) cmin(Min, tmpc - sum);
                    cout << "MM " << Max << " " << Min << endl;
                    if(Min + m <= Max)
                    {
                        tmp = tmpinit - Min;
                        dbg(tmp);
                    }
                    else break;
                }
                dbg(tmp);
                b[i] = tmp;
                c += sa[i] - sa[bef] + b[i];
                Max = 0;
                Min = 0;
                sum = 0;
            }
        }
        FORR(i,n - 1) printf("%lld ", b[i]);
        printf("%lld\n",b[n]);
    }
}
/*
5 3 1 2 3 3 3
5 5 3 0 5 -3 -2

*/
