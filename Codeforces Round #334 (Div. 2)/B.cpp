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
const int MAXINT = 0x3FFFFFFF; // INF / 2
const int MAXN = 1000000 + 5;
priority_queue<LL> q;
LL a[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    FOR(i,n)
    {
        int x;
        scanf("%d",&x);
        a[i] = x;
    }
    FOR(i,n) a[i] = -a[i];
    sort(a, a + n);
    while(!q.empty()) q.pop();
    if(k >= n)
    {
        cout << -a[0] << endl;
        return 0;
    }
    LL ans = 0;
    FOR(i,n) a[i] = -a[i];
    FOR(i,k)
    {
        q.push(-a[i]);
    }
    for(int i = k; i < n; i++)
    {
        LL tmp = -q.top();
        q.pop();
        ans = max(-(tmp + a[i]),ans);
    }
    while(!q.empty())
    {
        ans = max(ans, -q.top());
        q.pop();
    }
    cout << ans << endl;
}
