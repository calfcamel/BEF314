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
const int MAXN = 501;
int n;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int c[MAXN][MAXN];

vector<PII> vp;
bool chk()
{
//    int t = 0;
    FOR(i, n * n)
    {
//        t++;
        int ii = vp[i].AA;
        int jj = vp[i].BB;
        int ret = 0;
        FOR(k,n) ret += a[ii][k] * b[k][jj];
        if(ret != c[ii][jj]) return false;
//        if(t > n * n * 6 / 10) return true;
    }
    return true;
}
int main()
{
    while(scanf("%d",&n)!= EOF)
    {

        FOR(i,n) FOR(j,n) scanf("%d",&a[i][j]);
        FOR(i,n) FOR(j,n) scanf("%d",&b[i][j]);
        FOR(i,n) FOR(j,n) scanf("%d",&c[i][j]);
        vp.clear();
        FOR(i,n) FOR(j,n) vp.PB(MP(i,j));
        random_shuffle(all(vp));
        if(chk()) puts("YES"); else puts("NO");
    }
}
