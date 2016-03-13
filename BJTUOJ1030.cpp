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
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int MAXN = 44800;
const int MAXDP = 2000000;
long long ans;
long long dp[MAXDP];
int solve(int n)
{
    if(n < MAXDP) if(dp[n] != -1) return dp[n];
//    cout << "SOLVE  " << n << endl;
    long long ret = 1;
    int mini = min(MAXN, n);
    for(int i = 2; i < mini; i++)
        if(n % i == 0)
        {
//            cout << "GOTO" << i << " " << n / i << endl;
            ret += solve(n / i);
        }
    if(n < MAXDP) dp[n] = ret;
//    cout << "RETURN " << n << endl;
    return ret;
}
int main()
{
    int n;
    clr(dp, -1);
    dp[1] = 1;
//    FOR(i,MAXN) if(i) solve(i);
    while(scanf("%d", &n) != EOF)
    {
        ans = solve(n);
        printf("%I64d\n",ans);
    }
    return 0;
}
