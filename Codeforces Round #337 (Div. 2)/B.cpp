
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
int n;
int a[MAXN];
int dp[MAXN];
int main()
{
    scanf("%d",&n);
    FORR(i,n) scanf("%d",&a[i]);
    LL ans = 0;
    int m = a[1];
    FORR(i,n) cmin(m, a[i]);
    FORR(i,n) a[i] -= m;
    ans = (LL) n * m;
    dp[0] = 0;
    int add = 0;
    FORR(i,n) if(a[i]) dp[i] = dp[i - 1] + 1; else dp[i] = 0;
    FORR(i,n) if(a[i] == 0) {add = dp[n] + dp[i - 1]; break;}
    FORR(i,n) cmax(add, dp[i]);
    cout << ans + add << endl;
}
