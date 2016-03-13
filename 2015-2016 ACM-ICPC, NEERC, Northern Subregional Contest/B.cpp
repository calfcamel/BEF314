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
char sb[MAXN];
char sw[MAXN];
char s1[MAXN];
char s2[MAXN];
#define ONLINE_JUDGE
int main()
{
    #ifdef ONLINE_JUDGE
        freopen("black.in","r",stdin);
        freopen("black.out","w",stdout);
    #endif // ONLINE_JUDGE
    int n = 6;
    int m = 5000;
    int b,w;
    scanf("%d%d",&b,&w);
    sb[m] = 0;
    sw[m] = 0;
    s1[m] = 0;
    s2[m] = 0;
    FOR(i,m) sb[i] = '@';
    FOR(i,m) s1[i] = '@';
    FOR(i,m) sw[i] = '.';
    FOR(i,m) s2[i] = '.';
    FOR(i,w - 1) s1[i * 2 + 1] = '.';
    FOR(i,b - 1) s2[i * 2 + 1] = '@';
    printf("%d %d\n",n,m);
    puts(sb);
    puts(s1);
    puts(sb);
    puts(sw);
    puts(s2);
    puts(sw);
    return 0;
}
