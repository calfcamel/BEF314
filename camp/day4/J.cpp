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
const int MAXN = 6700;
int a[MAXN];
int w[MAXN];
const int MAXJ = 120;
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
        printf("%d\n",w[dp2[j][k]]);
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
//        dbg(k);
//        dbg(dp1[j][k]);
        k -= a[dp1[j][k]];
        if(k < 0) k += 2016;
        j--;
    }
}
vector<PII> vp;
int main()
{
//    freopen("D:/intput.txt","r",stdin);
//    freopen("D:/output.txt","w",stdout);
    int n = 6666;
    FORR(i,n) scanf("%d",&a[i]);
    FORR(i,n) if(a[i] == 2016) a[i] = 0;
    int sum = 0;
    vp.clear();
    FORR(i,n) vp.PB(MP(a[i],i));
//    random_shuffle(all(vp));
    FOR(i,n) a[i + 1] = vp[i].AA;
    FOR(i,n) w[i + 1] = vp[i].BB;
    FORR(i,2016) sum = add(sum, a[i]);
    if(sum == 0)
    {
//        dbg(sum);
        FORR(i,2016) printf("%d\n",w[i]);
        return 0;
    }
    clr(dp1,0);
    clr(vis,0);
    clr(dp2,0);
    dp1[0][0] = -1;
    dp2[0][0] = -1;
    FORR(i,2016) for(int j = LOOPJ - 1; j >= 0; j--) FOR(k,2016) if(dp1[j][k] != 0 && dp1[j + 1][add(k, a[i])] == 0)
    {
        dp1[j + 1][add(k, a[i])] = i;
    }
    REP(i,2017,n) for(int j = LOOPJ - 1; j >= 0; j--) FOR(k,2016) if(dp2[j][k] != 0 && dp2[j + 1][add(k, a[i])] == 0)
    {
        dp2[j + 1][add(k, a[i])] = i;
    }
    FORR(j,LOOPJ) FOR(k,2016) if(dp1[j][k] && dp2[j][(k + 2016 - sum) % 2016])
    {
//        dbg(sum);
//        dbg(k);
//        dbg((k + 2016 - sum) % 2016);
//        dbg(j);
//        dbg(k);
        outputdp2(j,(k + 2016 - sum) % 2016);
        notvisdp1(j,k);
        FORR(i,2016) if(!vis[i])printf("%d\n",w[i]);
        return 0;
    }
}
