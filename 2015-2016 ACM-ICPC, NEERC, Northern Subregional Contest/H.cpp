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
void putha(int k)
{
    FOR(i,15)
    {
        if(k & 1) printf("ed");
        else printf("fE");
        k >>= 1;
    }
    printf("\n");
}
int main()
{
    #ifdef ONLINE_JUDGE
        freopen("hash.in","r",stdin);
        freopen("hash.out","w",stdout);
    #endif // ONLINE_JUDGE
    int n;
    scanf("%d",&n);
    FOR(i,n) putha(i);
    return 0;
}
