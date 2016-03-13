
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <unordered_map>
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
#define all(x) x.begin(), x.end()
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 200000 + 10;
int a[MAXN];
int p[MAXN];
int f[MAXN];
int n;
vector<pii> v;
int main()
{
    scanf("%d",&n);
    v.clear();
    FORR(i,n) scanf("%d%d",&a[i],&p[i]);
    FORR(i,n) a[i]++;
    FORR(i,n) v.PB(MP(a[i],p[i]));
    sort(all(v));
    FORR(i,n) a[i] = v[i - 1].AA;
    FORR(i,n) p[i] = v[i - 1].BB;
    a[0] = -100000090;
    f[0] = 0;
    FORR(i,n)
    {
        dbg(a[i]);
        f[i] = f[i - 1];
        int tmp = lower_bound(a,a + i, a[i] - p[i]) - a;
        f[i] = max(f[i], f[max(0, tmp - 1)] + 1);
//        cout << i << ": " << tmp << " " << f[i] << endl;
    }
    int ans = n - 1;
    FORR(i,n) ans = min(ans, n - f[i]);
    cout << ans << endl;
}
