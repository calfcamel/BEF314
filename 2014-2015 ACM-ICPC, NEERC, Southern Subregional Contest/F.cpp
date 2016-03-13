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
const int MAXINT = 0x3FFFFFFF; // INF / 2
const int MAXN = 200000 + 5;
int n,k;
int a[MAXN];
int sum[MAXN];
int f[MAXN];
int g[MAXN];
int getsum(int l, int r)
{
    if(r >= n) r = n;
    l --;
    if(l <= 0) l = 0;
    return sum[r] - sum[l];
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    sum[0] = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for(int i = 1; i <= n; i++) f[i] = getsum(i - k + 1, i);
    for(int i = 1; i <= n; i++) g[i] = getsum(i, i + k - 1);
//    for(int i = 1; i <= n; i++) cout << i << " :" << g[i] << endl;
    for(int i = 2; i <= n; i++) f[i] = max(f[i],f[i - 1]);
    for(int j = n - 1; j >= 1; j--) g[j] = max(g[j], g[j + 1]);
    for(int i = 1; i < n; i++) ans = max(ans, f[i] + g[i + 1]);
    if(n == 1) ans = a[1];
    cout << ans << endl;
}
