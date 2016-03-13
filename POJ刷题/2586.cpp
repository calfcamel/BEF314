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
const int MAXN = 200005;
LL s,d;
LL a[13];
LL get5(int x)
{
    LL ret = 0;
    FOR(i,5) ret += a[x + i];
    return ret;
}
bool chk()
{
    FORR(i,8) if(get5(i) >= 0) return false;
    return true;
}
int main()
{
    while(cin >> s >> d)
    {
        FORR(i,12) a[i] = -d;
        FORR(i,12)
        {
            a[i] = s;
            if(!chk()) a[i] = -d;
        }
        LL sum = 0;
        FORR(i,12) sum += a[i];
        if(sum >= 0)cout << sum << endl;
        else cout << "Deficit" << endl;
    }
}


