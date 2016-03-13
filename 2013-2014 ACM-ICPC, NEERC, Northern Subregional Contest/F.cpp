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
#define ccmin(x,y) if(x == -1) x = y; else x = min(x,y)
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

const int MAXN = 1000 + 2;
//GYM
//#define ONLINE_JUDGE
int a[MAXN];
int b[MAXN][MAXN];
int sum[MAXN][MAXN];
int dp[MAXN][MAXN];
int q[MAXN][MAXN];
int n,s,t;
vector<int> v[MAXN];
int getsum(int i, int j)
{
    int ret = 0;
//    cout << "GETSUM " << i << " " << j << " " << ret << endl;
//    FOR(k,v[i].SZ)
//    {
//        cout << v[i][k] << endl;
//        ret += sum[j][s] - sum[i][s] - sum[j][v[i][k]] + sum[i][v[i][k]];
//    }
    FOR(k,v[i].SZ)
    {
        ret += sum[1000][j] - sum[1000][i] - sum[v[i][k]][j] + sum[v[i][k]][i];
    }
//    cout << "GETSUM " << i << " " << j << " " << ret << endl;
    return ret;
}
int query(int i, int j)
{
    if(i == j) return 0;
    if(q[i][j] != -1) return q[i][j];
    int ret;
    ret = getsum(i,j) + query(i + 1, j);
    q[i][j] = ret;
    return ret;
}
int main()
{
    #ifdef ONLINE_JUDGE
        freopen("flight.in","r",stdin);
        freopen("flight.out","w",stdout);
    #endif // ONLINE_JUDGE
    FOR(i,1001) v[i].clear();
    clr(q, -1);
    scanf("%d%d%d",&n,&s,&t);
    FORR(i,n) scanf("%d",&a[i]);
    clr(b,0);
    clr(sum,0);
    FORR(i,n) b[i][a[i]] = 1;
    FORR(i,n) v[a[i]].PB(i);
    FORR(i,1000) FORR(j,1000)
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + b[i][j];
    clr(dp, -1);
    FORR(i,s)
    {
        dp[i][1] = query(1,i);
        FORR(j, t - 1) if(dp[i][j] != -1)
        for(int ii = i + 1; ii <= s; ii++)
            ccmin(dp[ii][j + 1],dp[i][j] + query(i + 1, ii));
    }
//    dbg(query(1,s));
    cout << dp[s][t] << endl;
}

