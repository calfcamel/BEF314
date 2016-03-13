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
const int MAXN = 20005;
int n;
int a[MAXN];
queue<LL> q1,q2;
LL get()
{
    LL ret;
    if(q2.empty())
    {
        ret = q1.front();
        q1.pop();
    }
    else if(q1.empty())
    {
        ret = q2.front();
        q2.pop();
    }
    else
    {
        if(q1.front() < q2.front())
        {
            ret = q1.front();
            q1.pop();
        }
        else
        {
            ret = q2.front();
            q2.pop();
        }
    }
    return ret;
}
int main()
{
    scanf("%d",&n);
    FOR(i,n) scanf("%d",&a[i]);
    sort(a, a + n);
    FOR(i,n) q1.push(a[i]);
    LL ans = 0;
    LL tmp;
    FOR(i,n - 1)
    {
        tmp = get();
        tmp += get();
        ans += tmp;
        q2.push(tmp);
    }
    cout << ans << endl;
}
