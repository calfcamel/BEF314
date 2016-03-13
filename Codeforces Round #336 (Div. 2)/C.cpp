
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
int chk(int x,int i)
{
//    if(i == 0) return 0;
//    cout << "CHK" << x << endl;
    if(x < a[0]) return 0;
    if(i == 0) return 0;
    int l = 0;
    int r = i - 1;
    int mid;
    if(x >= a[i - 1]) return f[i - 1];
    while(l < r)
    {
        mid = (l + r) / 2;
        if(x <= a[mid]) r = mid;
        else l = mid + 1;
    }
//    cout << "   GET " << l << " " << f[l] << endl;
    return f[l];
}
vector<pii> v;
int main()
{
    scanf("%d",&n);v.clear();
    FOR(i,n) scanf("%d%d",&a[i],&p[i]);
    FOR(i,n) v.PB(MP(a[i],p[i]));
    sort(all(v));
    FOR(i,n) a[i] = v[i].AA;
    FOR(i,n) p[i] = v[i].BB;
    FOR(i,n)
    {
        f[i] = chk(a[i] - p[i] - 1, i) + 1;
        if(i) cmax(f[i],f[i - 1]);
    }
//    FOR(i,n) cout << i << " " << f[i] << endl;
    int ans = n;
    FOR(i,n) ans = min(ans, n - f[i]);
    cout << ans << endl;
}
