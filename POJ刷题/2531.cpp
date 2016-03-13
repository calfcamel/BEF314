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
int a[30][30];
int main()
{
    int n;
    scanf("%d",&n);
    int ans = 0;
    FOR(i,n) FOR(j,n) scanf("%d",&a[i][j]);
    FOR(mask, 1 << (n - 1))
    {
        int now = 0;
        FOR(j,n - 1)
            if(!(mask & (1 << j))) now += a[n - 1][j];
        FOR(i, n - 1) if(mask & (1 << i)) FOR(j, n - 1) if(!(mask & (1 << j))) now += a[i][j];
        cmax(ans, now);
    }
    printf("%d\n",ans);
}
