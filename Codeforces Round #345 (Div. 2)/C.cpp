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
typedef pair<int, int> PII;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
#define LL long long
const int MAXN = 200005;
vector<PII> v1,v2;
LL s1[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    int x,y;
    FOR(i,n)
    {
        scanf("%d%d",&x,&y);
        v1.PB(MP(x,y));
        v2.PB(MP(y,x));
    }
    sort(all(v1));
    sort(all(v2));
    LL ans = 0;
    clr(s1, 0);
    s1[0] = 1;
    REP(i,1,n - 1)
    {
        if(v1[i].AA == v1[i - 1].AA)
        {
            s1[i] = s1[i - 1] + 1;
        }
        else
        {
            s1[i] = 1;
            ans += s1[i - 1] * (s1[i - 1] - 1) / 2;
        }
    }
    ans += s1[n - 1] * (s1[n - 1] - 1) / 2;
//    dbg(ans);
    clr(s1, 0);
    s1[0] = 1;
    REP(i,1,n - 1)
    {
        if(v2[i].AA == v2[i - 1].AA)
        {
            s1[i] = s1[i - 1] + 1;
        }
        else
        {
            s1[i] = 1;
            ans += s1[i - 1] * (s1[i - 1] - 1) / 2;
        }
    }
    ans += s1[n - 1] * (s1[n - 1] - 1) / 2;
//    dbg(ans);
    clr(s1, 0);
    s1[0] = 1;
    REP(i,1,n - 1)
    {
        if(v2[i].AA == v2[i - 1].AA && v2[i].BB == v2[i - 1].BB)
        {
            s1[i] = s1[i - 1] + 1;
        }
        else
        {
            s1[i] = 1;
            ans -= s1[i - 1] * (s1[i - 1] - 1) / 2;
        }
    }
    ans -= s1[n - 1] * (s1[n - 1] - 1) / 2;
//    dbg(ans);
    cout << ans << endl;
}
