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
const int MAXN = 101;
int n;
int x;
int dp[5001];
int main()
{
    clr(dp,0);
    dp[0] = 1;
    scanf("%d",&n);
    int sum = 0;
    FOR(i,n)
    {
        scanf("%d",&x);
        sum += x;
        for(int j = 5000; j >= x; j--) if(dp[j - x]) dp[j] = 1;
    }
    int ans = sum;
    for(int i = 1; i <= min(5000, sum); i++) if(dp[i])
    {
        int j = sum - i;
        cmin(ans, max(i,j) - min(i,j));
    }
    cout << ans << endl;
}


