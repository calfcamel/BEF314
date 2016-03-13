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
LL dp[1000][2][2];
int main()
{
    clr(dp[0], 0);
    dp[0][0][0] = 1;
    REP(i,1,100)
    {
        dp[i][0][0] = dp[i - 1][0][0] * 2
                    + dp[i - 1][1][0]
                    + dp[i - 1][0][1];
        dp[i][1][0] = dp[i - 1][1][0] * 2
                    + dp[i - 1][0][0]
                    + dp[i - 1][1][1];
        dp[i][0][1] = dp[i - 1][0][1] * 2
                    + dp[i - 1][0][0]
                    + dp[i - 1][1][1];
        dp[i][1][1] = dp[i - 1][1][1] * 2
                    + dp[i - 1][1][0]
                    + dp[i - 1][0][1];
    }
    REP(i,1,20)
    {
        cout << i << " " << dp[i][0][0]<< endl;
    }
}
