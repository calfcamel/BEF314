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
const int MAXINT = 0x3FFFFFFF; // INF / 2
const int MAXN = 200000 + 5;
int n;
int f[MAXN];
LL fu[MAXN];
LL fd[MAXN];
LL ans[MAXN];
vector<int> c[MAXN];
LL Exgcd(LL a,LL b,LL &x,LL &y){
	LL r,t;
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	r=Exgcd(b,a%b,x,y);
	t=x;
	x=y;
	y=t-a/b*y;
	return r;
}

LL getinv(LL a,LL M)
{
    LL x,y;
    Exgcd(a,M,x,y);
    return (x % MOD + MOD) % MOD;
}
void dfs1(int i)
{
    for(int j = 0; j < c[i].SZ; j++)
    {
        dfs1(c[i][j]);
        fu[i] = fu[i] * fu[c[i][j]] % MOD;
    }
    fu[i] = (fu[i] + 1LL) % MOD;
}
void dfs2(int i)
{
    if(i != 1)
    {
        if(fu[i] == 0) exit(i);
        if(f[i] == 1) fd[i] = ((fu[1] -1LL + MOD) % MOD * getinv(fu[i],MOD) % MOD + 1LL) % MOD;
        else fd[i] = ((fu[f[i]] - 1LL + MOD) % MOD * getinv(fu[i],MOD) % MOD * fd[f[i]] % MOD + 1LL ) % MOD;
    }
    for(int j = 0; j < c[i].SZ; j++)
    {
        dfs2(c[i][j]);
    }
}
int main()
{
    scanf("%d",&n);
    int x;
    for(int i = 1; i <= n; i++) c[i].clear();
    for(int i = 2; i <= n; i++)
    {
        scanf("%d",&x);
        f[i] = x;
        c[x].PB(i);
    }
    for(int i = 1; i <= n; i++) fd[i] = 1;
    for(int i = 1; i <= n; i++) fu[i] = 1;
    for(int i = 1; i <= n; i++) ans[i] = 1;
    dfs1(1);
    dfs2(1);
    for(int i = 2; i <= n; i++) ans[i] = ans[i] * fd[i] % MOD;
    for(int i = 1; i <= n; i++) ans[i] = ans[i] * ((fu[i] - 1LL + MOD) % MOD) % MOD;
    for(int i = 1; i <= n; i++)
    {
        printf("%I64d",ans[i]);
        if(i != n) printf(" ");
        else puts("");
    }
}
