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

char str[60];
int a[60];
int n;
bool chk()
{
    FOR(i,n) if(a[i] == 1) return true;
    return false;
}
void opt()
{
    int t = 0;
    while(t < n)
    {
        if(a[t] == 1) break;
        t++;
    }
    if(t > n) return;
    a[t] = 0;
    FOR(i,t) a[i] = 1;
}
int main()
{
    scanf("%d%s",&n,str);
    clr(a,0);
    FOR(i,n) if(str[i] == 'B') a[i] = 1;
//    FOR(i,n) cout << a[i] << endl;
    LL ans = 0;
    FOR(i,n) if(a[i]) ans += 1LL << (LL)i ;
    cout << ans << endl;
}
