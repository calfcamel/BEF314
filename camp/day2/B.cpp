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
LL b[MAXN];
int main()
{
    while(~scanf("%d",&n))
    {
        FORR(i,n) scanf("%lld",&a[i]);
        REP(i,1,n - 1) b[i] = a[i + 1] - a[i];
        REP(i,2,n)
        {
            LL tmp = b[i];
            if(b[i] >= a[i] - a[i - 1]) continue;
            bool boo = false;
            REP(j, i + 1, n) if(a[i - 1] + b[j] >= a[j])
            {
                if(b[i] == 0)
                {
                    b[i] = min(a[i + 1] - a[i], a[i] - a[i - 1]);
                    REP(j, i + 1, n) if(a[i] + b[i] >= a[j] + b[j]) b[j] = 0;
                }
                else{
                    cmin(b[i], a[i + 1] - a[i]);
                }
                boo = true;
                break;
            }
            if(boo) continue;
            b[i] = a[i] - a[i - 1];
//            if(b[i] > tmp)
            {
                REP(j, i + 1, n) if(a[i] + b[i] >= a[j] + b[j]) b[j] = 0;
            }
        }
        LL ans = 0;
        FORR(i,n) ans += b[i] * b[i];
        cout << ans << endl;
//        b[n] = a[n] - a[n - 1];
    }
}
/*
4
1 4 5 10
4
1 6 7 10
5
1 4 5 6 10
3
1 2 6

*/
