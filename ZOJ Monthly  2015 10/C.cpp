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
#define REP(i,x,y) for(int i = (x); i <= (int) (y) ; i++)


vector<pii> v;
int a[805];
int dp[805][805];
int main()
{
    int _T;
    scanf("%d",&_T);
    while(_T--)
    {
        int n;
        scanf("%d",&n);
        v.clear();
        int x,y;
        FOR(i,n)
        {
            scanf("%d%d",&x,&y);
            v.PB(MP(-y,x));
        }
        sort(v.begin(), v.end());
        FOR(i,n) v[i].AA = -v[i].AA;
        clr(dp,0);
        int maxj = 0;
        int maxv = 0;
        int ans = 0;
//        FOR(i,n) cout << v[i].AA << " " << v[i].BB << endl;
        for(int i = 1; i <= n; i++)
            a[i] = v[i - 1].BB;
        for(int i = 1; i <= n; i++) for(int j = 1; j < n; j++)
        {
            if(j * 2 > i) break;
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
//            cout << i << " " << j << " " << dp[i][j] << endl;
        }
        cout << dp[n][n / 2] << endl;
    }
    return 0;
}

