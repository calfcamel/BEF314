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
typedef pair<LL, LL> PII;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
#define LL long long
const int MAXN = 5001;
int a[MAXN];
int b[MAXN];
LL get(int x)
{
    LL ret = x - 1;
    return ret * (ret + 1) / 2;
}
int main()
{
    clr(a,0);
    clr(b,0);
    int n;
    scanf("%d",&n);
    int x,y;
    int d = 2000;
    FOR(i,n)
    {
        scanf("%d%d",&x,&y);
        a[x + y]++;
        b[x - y + d]++;
    }
    LL ans = 0;
    FOR(i,5000) if(a[i]) ans += get(a[i]);
    FOR(i,5000) if(b[i]) ans += get(b[i]);
    cout << ans << endl;
}
