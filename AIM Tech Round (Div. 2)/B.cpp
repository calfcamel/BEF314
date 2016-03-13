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
const int MAXN = 500005;
vector<LL> v;
int main()
{
    LL x;
    int n;
    cin >> n;
    FOR(i,n)
    {
        cin >> x;
        v.PB(-x);
    }
    LL ans = 0;
    sort(all(v));
    FOR(i,n) v[i] = -v[i];
    FOR(i,n)
    {
        if(v[i] > 0) for(int j = i + 1; j < n; j++)
            if(v[i] == v[j]) v[j]--;
    }
    FOR(i,n) if(v[i] > 0) ans += v[i];
    cout << ans << endl;
}

