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
const int MAXN = 1005;
double a[MAXN];
int f1[MAXN];
int f2[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    a[0] = 0.;
    FORR(i,n) scanf("%lf",&a[i]);
    clr(f1,0);
    clr(f2,0);
    for(int i = 0; i < n; i++) for(int j = i + 1; j <= n; j++) if(a[i] < a[j]) cmax(f1[j], f1[i] + 1);
    reverse(a + 1, a + n + 1);
    for(int i = 0; i < n; i++) for(int j = i + 1; j <= n; j++) if(a[i] < a[j]) cmax(f2[j], f2[i] + 1);
    FORR(i,n) cmax(f1[i], f1[i - 1]);
    FORR(i,n) cmax(f2[i], f2[i - 1]);
//    FORR(i,n) cout << f1[i] << " ";cout << endl;
//    FORR(i,n) cout << f2[i] << " ";cout << endl;
    int ans = 0;
    for(int i = 1; i < n; i++)
    {
        int j = n - i;
        cmax(ans, f1[i] + f2[j]);
    }
    printf("%d\n",n - ans);
}
