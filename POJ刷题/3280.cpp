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
const int MAXN = 2005;
char str[MAXN];
int n,l;
char ch[MAXN];
int cost[26];
int dp[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&l);
    scanf("%s",str);
    int x,y;
    FOR(i,n)
    {
        scanf("%s%d%d",ch,&x,&y);
        cost[ch[0] - 'a'] = min(x,y);
    }
    clr(dp,0);
    FOR(i,l) for(int j = i - 1; j >= 0; j--)
    {
        dp[j][i] = min(dp[j + 1][i] + cost[str[j] - 'a'], dp[j][i - 1] + cost[str[i] - 'a']);
        if(str[i] == str[j]) cmin(dp[j][i], dp[j + 1][i - 1]);
    }
    cout << dp[0][l - 1] << endl;
}
