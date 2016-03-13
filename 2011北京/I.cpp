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
#include <iomanip>
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
#define REP(i,x,y) for(int i = x,  _END_ = (int)(y); i <= _END_ ; i++)
#define REP_D(i,x,y) for(int i = x,  _END_ = (int)(y); i >= _END_ ; i--)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
double dp[2005][2005];
double A[2005];
double C[2005];
int main()
{
    int n,m,k;
    double p1,p2,p3,p4;
    while(~scanf("%d%d%d%lf%lf%lf%lf",&n,&m,&k,&p1,&p2,&p3,&p4))
    {
//        swap(p2,p3);
        if(p4 == 0.0 || p1 == 1.0)
        {
            puts("0.00000");
            continue;
        }
        double self = 1.0 - p1;
        dp[1][1] = p4 / self / (1.0 - p2/self);
//        dbg(dp[1][1]);
        double X;
        REP(i,2,n)
        {
            A[0] = 1.0;
            A[1] = p2 / self;
            C[1] = p4 / self;
            REP(j,2,i)
            {
                A[j] = p2 / self * A[j - 1];
                C[j] = p3 / self * dp[i - 1][j - 1];
                if(j <= k) C[j] += p4 / self;
            }
//            FORR(j,i) cout << "C " << j << " = " << C[j] << endl;
//            dbg(i);
//            REP(j,1,i) printf("%d : A = %.5f , C = %.5f\n", j, A[j], C[j]);
//            X = C[1] * A[i];
            X = C[1] * A[i - 1];
//            C[i] = 0;
            REP(j,2,i) X += A[i - j] * C[j];
//            dbg(X);
            X = X / (1.0 - A[i]);
//            dbg(X);
            dp[i][i] = X;
            dp[i][1] = X * p2 / self + p4 / self;
            REP(j,2,i - 1) dp[i][j] = p2 / self * dp[i][j - 1] + C[j];
//            REP(j,1, i - 1) dp[i][j] = A[j] * X + C[j];
        }
//        REP(i,1,n) REP(j,1,i) printf("DP %d %d = %.5f A = %.5f C = %.5f\n",i,j,dp[i][j], A[j], C[j]);
        printf("%.5f\n", dp[n][m]);
    }
}
