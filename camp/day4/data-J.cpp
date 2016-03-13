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
#define LL long long
const int MAXN = 6601;
int a[MAXN];
const int MAXJ = 30;
const int LOOPJ = MAXJ - 1;
int dp1[MAXJ][2016];
int dp2[MAXJ][2016];
int l1[MAXJ][2016];
int l2[MAXJ][2016];
int add(int x, int y)
{
    if(x + y >= 2016) return x + y - 2016;
    return x + y;
}
int vis[2017];
void outputdp2(int j, int k)
{
    while(j)
    {
        printf("%d\n",dp2[j][k]);
        k -= a[dp2[j][k]];
        if(k < 0) k += 2016;
        j--;
    }
}
void notvisdp1(int j, int k)
{
    while(j)
    {
        vis[dp1[j][k]] = 1;
        k -= a[dp1[j][k]];
        if(k < 0) k += 2016;
        j--;
    }
}
int main()
{
    freopen("D:/intput.txt","w",stdout);
    FOR(i,1667) cout << 1 << endl;
    FOR(i,1667) cout << 2 << endl;
    FOR(i,1666) cout << 9 << endl;
    FOR(i,1666) cout << 10 << endl;
}
