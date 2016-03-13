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
const int MAXN = 5005;
int dp[2][MAXN];
char str[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",&str);
    clr(dp,0);
    int cur = 0;
    int nxt = 1;
    for(int i = 1; i < n; i++)
    {
        clr(dp[nxt],0);
//        dbg(i);
        for(int j = i - 1; j >= 0; j--)
        {
            dp[nxt][j] = min(dp[cur][j] + 1, dp[nxt][j + 1] + 1);
            if(str[j] == str[i]) cmin(dp[nxt][j], dp[cur][j + 1]);
//            dbg(j);
//            dbg(dp[nxt][j]);
        }
//        cout << endl;
        swap(cur, nxt);
    }
    cout << dp[cur][0] << endl;
}

