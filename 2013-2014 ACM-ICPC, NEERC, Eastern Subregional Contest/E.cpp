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

const int MAXN = 100000 + 5;
double dp[300][300];
int vis[300][300];
double C[300][300];
void init()
{
    clr(C,0);
    C[0][0] = 1;
    for(int i = 1; i <= 249; i++)
    {
        C[i][0] = 1;
        C[i][i] = 1;
        for(int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
}
double getdp(double p, int n, int k)
{
//    cout << p << " " << n << " " << k << endl;
    if(k == 0) return p * (double)n;
    n -= k;
    if(n <= 0) return 0;
    if(vis[n][k]) return p * dp[n][k];
//    dbg(k1);
//    dbg(k2);
    double ret = 0;
    for(int i = 1; i < n + k; i++)
    {
        double tmp = 0;
        for(int j = 0; j <= i; j++) if(n - j >= 0 && k - (i - j) >= 0)
        {
            double k1 = C[n][j] * C[k][i - j] / C[n + k][i];
            tmp += getdp(k1, n - j, k - (i - j));
//            dbg(j);
//            cout << n << j << k << i - j << n + k << i << endl;
//            cout << C[n][j] << " ";
//            cout << C[k][i - j] << " ";
//            cout << C[n + k][i] << " "; puts("");
//            dbg(k1);
//            dbg(tmp);
//            puts("");
        }
//        cout << n << " " << k << " " << i <<" = " << tmp << endl;
        ret = max(ret, tmp);
    }
    vis[n][k] = 1;
    dp[n][k] = ret;
//    cout << n << " " << k << " = " << ret << endl;
    return ret * p;
}
int main()
{
    init();
    int n,k;
    clr(dp,0);
    clr(vis,0);
    cin >> n >> k;
    printf("%.10lf\n",getdp(1.0,n - k,k));
}
