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
const int MAXN = 100001;
double a[MAXN];
double b[MAXN];
double c[MAXN];
int n,k;
bool chk(double r)
{
    double ret = 0.0;
    FOR(i,n) c[i] = a[i] - b[i] * r;
    sort(c, c + n);
    for(int i = k; i < n; i++) ret += c[i];
    return ret > 0.0;
}
int main()
{
    while(scanf("%d%d",&n,&k) != EOF)
    {
        if(n == 0) return 0;
        FOR(i,n) scanf("%lf",&a[i]);
        FOR(i,n) scanf("%lf",&b[i]);
        double l = 0.0; double r = 1.0;
        FOR(cnt, 200)
        {
            double mid = (l + r) / 2.0;
            if(chk(mid)) l = mid;
            else r = mid;
        }
        printf("%.0f\n",100.0 * l);
    }
}
