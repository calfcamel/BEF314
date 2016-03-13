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
#define all(x) x.begin(),x.end()
const int MAXN = 100000 + 5;
LL W,L,P;
LL ans1;
LL ans2;
int n,m;
LL a[100];
void cccmax(LL& x,LL& y)
{
    if(~x) x = y;
    else x = max(x,y);
}
void cccmin(LL& x,LL& y)
{
    if(~x) x = y;
    else x = min(x,y);
}
void dfs(int k)
{
    if(k == n)
    {
        sort(a,a + n);
        cccmax(ans1, a[n - m - 1]);
        cccmin(ans2, a[n - m - 1]);
        return;
    }
    for(int i = k + 1; i < n; i++)
    {
        a[k] += W;
        a[i] += L;
        dfs(k + 1);
        a[k] -= W;
        a[i] -= L;
        a[k] += L;
        a[i] += W;
        dfs(k + 1);
        a[k] -= L;
        a[i] -= W;
        a[k] += P;
        a[i] += P;
        dfs(k + 1);
        a[k] -= P;
        a[i] -= P;
    }
}
int main()
{
    cin >> n >> m;
    cin >> W >> p >> L;
    if(L > W) swap(L ,W);
    dfs();
}
