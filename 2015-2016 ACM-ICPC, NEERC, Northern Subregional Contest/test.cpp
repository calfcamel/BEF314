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
#define REP(i,x,y) for(int i = (x); i <= (int) (y) ; i++)

const int MAXN = 100000 + 5;
LL cnt1[26];
LL cnt2[26];
char s1[MAXN];
char s2[MAXN];
#define ONLINE_JUDGE
int main()
{
    #ifdef ONLINE_JUDGE
        freopen("concatenation.in","r",stdin);
        freopen("concatenation.out","w",stdout);
    #endif // ONLINE_JUDGE
    scanf("%s%s",s1,s2);
    int n = strlen(s1);
    int m = strlen(s2);
    clr(cnt1,0);
    clr(cnt2,0);
    REP(i,1,n - 1) cnt1[s1[i] - 'a']++;
    REP(i,0,m - 2) cnt2[s2[i] - 'a']++;
    LL ans = (LL)n * m;
    FOR(i,26) ans = ans - cnt1[i] * cnt2[i];
    cout << ans << endl;
    return 0;
}
