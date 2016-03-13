
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
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
int a[2001];
int mod = 2017;
int f[2001];
int main()
{
    int n;
    scanf("%d",&n);
    FORR(i,n) scanf("%d",&a[i]);
    clr(f,0);
    f[0] = 1;
    FORR(i,n) FOR(j,i) if(a[j] <= a[i]) f[i] = (f[i] + f[j]) % mod;
    int ans = 0;
    FORR(i,n) ans = (ans + f[i]) % mod;
    cout << ans << endl;
}
