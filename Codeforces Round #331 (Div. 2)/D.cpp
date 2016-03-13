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
const int MAXN = 100000 + 5;
double dp[2001][2001];
double p;
int n,h;
int a[2001];
inline int getLL(int l, int r)
{
    if(l == 0) return h;
    else return min(h, a[l] - a[l - 1]);
}
inline int getLR(int l, int r)
{
    if(r == n - 1) return h;
    else return min(h, a[r + 1] - a[r]);
}
inline int getRL(int l, int r)
{
    if(l == n - 1) return h;
    else return min(h, a[l + 1] - a[l]);
}
inline int getRR(int l, int r)
{
    if(r == 0) return h;
    else return min(h, a[r] - a[r - 1]);
}
inline bool booLR(int l, int r)
{
    if(l == n - 1 || l == r) return false;
    if(a[l + 1] - a[l] < h) return true;
    return false;
}
inline bool booRL(int l, int r)
{
    if(r == 0 || l == r) return false;
    if(a[r] - a[r - 1] < h) return true;
    return false;
}
double solve(int l, int r)
{
    if(l > r) return 0;
    if(l == r) return 0.5 * p * getLL(l,r) + 0.5 * (1.0 - p) * getRR(l, r);
    cout << l << " " << r << endl;
    LL ret = 0;
    if(dp[l][r] != -1.0) return dp[l][r];
    // LL
    ret += 0.5 * p * getLL(l,r) + solve(l + 1, r);
    double sum = getLR(l,r);
    int j = l;
    while(booLR(j, r))
    {
        j++;
        sum += getLR(j,r);
    }
    ret += 0.5 * (1.0 - p) * sum + solve (j, r);
    sum = getRL(l,r);
    j = r;
    while(booRL(l, j))
    {
        j--;
        sum += getRL(l, j);
    }
    ret += 0.5 * p * sum + solve(l, j);
    ret += 0.5 * (1.0 - p) * getRR(l, r) + solve(l, r - 1);
    dp[l][r] = ret;
    return ret;
}
int main()
{
    scanf("%d%d%lf",&n,&h,&p);
    FOR(i,n) scanf("%d",&a[i]);
    FOR(i,n) FOR(j,n) dp[i][j] = -1.0;
    printf("%.10lf\n",solve(0,n - 1));
    return 0;
}
