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
const int N = 105;
const int M = N * 2;
struct node
{
    int v,nxt;
}E[M];
int h[N];
int a[N];
int n,k;
int dp[2][N];
void init()
{
    tot = 0;
    clr(h,-1);
}
void add(int u, int v)
{
    E[tot].v = v;
    E[tot].nxt = h[u];
    h[u] = tot++;
}
void DP()
{
    FORR(i,n) dp[i] = a[i]
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        FORR(i,n) scanf("%d",&a[i]);
        int x,y;
        init();
        FOR(i,n - 1) {scanf("%d%d",&x,&y); add(x,y);}
        cout << DP() << endl;
    }
}
