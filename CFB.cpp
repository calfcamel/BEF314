// calfcamel
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
const int MAXN = 100000 + 5;
int a[MAXN];
int f[MAXN];
int g[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    a[0] = 0;
    a[n + 1] = 0;
    clr(f,0);
    clr(g,0);
    f[0] = 0;
    for(int i = 1; i <= n; i++)
        f[i] = min(f[i - 1] + 1, a[i]);
    g[n + 1] = 0;
    for(int i = n; i >= 1; i--)
        g[i] = min(g[i + 1] + 1, a[i]);
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, min(f[i],g[i]));
    cout << ans << endl;
}

