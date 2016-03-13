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
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define REP(i,x,y) for(int i = (x); i <= (int) (y) ; i++)

const int MAXN = 100000 + 5;
const int MAX2 = 61;
const int MAX3 = 39;
LL p2[MAX2];
LL p3[MAX3];
//#define ONLINE_JUDGE
vector<LL> v[MAX2];
LL check(LL x)
{
//    cout << "chk" << x << endl;
    LL ret = 0;
    LL p = 0;
    LL q = 0;
    FOR(i,MAX2) FOR(j,MAX3) REP(n,1,i - 1) REP(m,0,j - 1) if(m < v[n].SZ && p2[i] + p3[j] + v[n][m] == x) return 1;
    FOR(i,MAX2) FOR(j,MAX3) if(p2[i] + p3[j] == x) return 1;
    return -1;
}
int main()
{
    #ifdef ONLINE_JUDGE
        freopen("hash.in","r",stdin);
        freopen("hash.out","w",stdout);
    #endif // ONLINE_JUDGE
//    cout << 1000000000000000000LL << endl;
    p2[0] = 1;
    p3[0] = 1;
    FOR(i,MAX2) if(i) p2[i] = p2[i - 1] * 2LL;
    FOR(i,MAX3) if(i) p3[i] = p3[i - 1] * 3LL;
//    cout << p2[MAX2 - 1] << endl;
//    cout << p3[MAX3 - 1] << endl;
//    for(LL i = 2; i <= 100; i++) if(i % 2 && i % 3) cout << i << endl;
    FOR(i,MAX2) v[i].clear();
    REP(i,1,MAX2)
    {
        REP(j,1,MAX3)
        {
            if(p2[i] * p3[j] > 1000000000000000000LL) break;
            v[i].PB(p2[i] * p3[j]);
        }
    }
    for(LL i = 2; i <= 1000; i++) if(i % 2 && i % 3) if(check(i) == -1) cout << i << endl;
    return 0;
}
