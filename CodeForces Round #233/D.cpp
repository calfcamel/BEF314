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
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int N = 2004;
int a[N];
int b[N];
double dp[N][N];
int main()
{
    clr(a,0);
    clr(b,0);
    int del;
    clr(dp,0);
    int n,m;
    scanf("%d%d",&n,&del);
    int x,y;
    FOR(i,del)
    {
        scanf("%d%d",&x,&y);
        a[x] = 1;
        b[y] = 1;
    }
    int p = 0;
    int q = 0;
    FORR(i,n) if(a[i]) p++;
    FORR(i,n) if(b[i]) q++;
    for(int i = n; i >= 0; i--) for(int j = n; j >= 0; j--)
    {
        if(n == i && j == n) continue;
        double k = (double)(n * n - i * j);
        double a = (double)(i * (n - j));
        double b = (double)((n - i) * j);
        double c = (double)((n - i) * (n - j));

        dp[i][j] = (a * dp[i][j + 1] + b * dp[i + 1][j] + c * dp[i + 1][j + 1] + n * n) / k;
    }
    printf("%.10f\n",dp[p][q]);
}
