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
const LL MOD = 100000007;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 1000 + 5;
int n,V;
LL dp[2][MAXN];
LL sum;
int a[MAXN];
int c[MAXN];
int main()
{
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        scanf("%d%d",&n,&V);
        FOR(i,n) scanf("%d",&a[i]);
        FOR(i,n) scanf("%d",&c[i]);
        clr(dp,0);
        int w;
        int cur = 0;
        int next = 1;
        dp[cur][0] = 1;
        LL ans = 0;
        FOR(i,n)
        {
            clr(dp[next],0);
            FORR(j,c[i])
            {
                w = a[i] * j;
//                cout << w << endl;
//                dbg(V - w);
                for(int k = 0; k <= V - w; k++) dp[next][k + w] = (dp[next][k + w] + dp[cur][k]) % MOD;
            }
            for(int k = 0; k <= V; k++) dp[next][k] = (dp[next][k] + dp[cur][k]) % MOD;
            swap(cur,next);
        }
        printf("Case %d: %lld\n",CAS,dp[cur][V]);
    }
    return 0;
}
