
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
const int mov[13] = {0,2,4,6,8,10,12,14,16,18,20,22,24};
inline int getbit(int st, int k) {return (st >> mov[k]) & 3;}
inline int pybit(int st, int k){return st << mov[k];}
inline int clrbit(int st, int k){return st&~(3 << mov[k]);}
inline int clrbit(int st, int i, int j){return clrbit(st,i) & clrbit(st,j);}
int n,m;
const int MAXN = 15;
int a[MAXN][MAXN];
char str[MAXN + 1];
const int HASH = 10007;
const int STATE = 1000010;
const int L = 1;
const int R = 2;
int cur,nxt;
int fx, fy;
struct HASHMAP
{
    int head[HASH],next[STATE],state[STATE],size;
    LL dp[STATE];
    void init()
    {
        size = 0;
        clr(head, -1);
    }
    void push(int st, LL ans)
    {
        int h = st % HASH;
        for(int i = head[h]; i != -1; i = next[i]) if(st == state[i])
        {
            dp[i] += ans;
            return;
        }
        dp[size] = ans;
        state[size] = st;
        next[size] = head[h];
        head[h] = size;
        size++;
    }
}hm[2];
void init()
{
//    scanf("%d%d",&n,&m);
    clr(a, 0);
    FOR(i,n)
    {
        scanf("%s",&str);
        FOR(j,m) if(str[j] == '.') a[i][j] = 1;
    }
    a[n][0] = 1;
    a[n][m - 1] = 1;
    n ++;
    FOR(i,m) a[n][i] = 1;
    n ++;
    FOR(i,n) FOR(j,m) if(a[i][j]) {fx = i; fy = j;}
}
int t1,t2;
int k1,k2;
void dplock(int j, int cur)
{
    FOR(k, hm[cur].size)
    {
        k1 = getbit(hm[cur].state[k], j);
        k2 = getbit(hm[cur].state[k], j + 1);
        if(k1 + k2 == 0) hm[nxt].push(hm[cur].state[k], hm[cur].dp[k]);
    }
}
void putst(int st)
{
    int tmp;
//    printf("%d\t",st);
    FOR(j,m + 1)
    {
        tmp = getbit(st,j);
        if(tmp == 0) putchar('#');
        if(tmp == L) putchar('L');
        if(tmp == R) putchar('R');
        if(tmp == 3) printf("PPPPP");
    }
}
int cnt;
int fll(int st, int j)
{
//    printf("FLL %d ",j);
    int ret = clrbit(st, j, j + 1);
    j++;
    cnt = 0;
    while(cnt != -1)
    {
        j++;
        if(getbit(st, j) == L) cnt++;
        if(getbit(st, j) == R) cnt--;
    }
    ret = clrbit(ret, j);
    ret |= L << mov[j];
//    printf(" find %d ", j);
//    putst(st); printf(" ");
//    putst(ret); puts("");
    return ret;
}
int frr(int st, int j)
{
//    printf("FRR %d ", j);
    int ret = clrbit(st, j, j + 1);
    cnt = 0;
    while(cnt != 1)
    {
        j--;
        if(getbit(st, j) == L) cnt++;
        if(getbit(st, j) == R) cnt--;
    }
//    printf(" clr1 "); putst(ret);
    ret = clrbit(ret, j);
//    printf(" clr2 "); putst(ret);
    ret |= R << mov[j];
//    printf(" find %d ", j);
//    putst(st); printf(" ");
//    putst(ret); puts("");
    return ret;
}
void dpblank(int i, int j, int cur)
{
    FOR(k, hm[cur].size)
    {

        k1 = getbit(hm[cur].state[k], j);
        k2 = getbit(hm[cur].state[k], j + 1);
        if(k1 + k2 == 0) hm[nxt].push(clrbit(hm[cur].state[k], j, j + 1) | (L << mov[j]) | (R << mov[j + 1]), hm[cur].dp[k]);
        else if(k1 == R && k2 == L) hm[nxt].push(clrbit(hm[cur].state[k], j, j + 1), hm[cur].dp[k]);
        else if(k1 == L && k2 == R)
        {
            if(i == fx && j == fy) hm[nxt].push(clrbit(hm[cur].state[k], j, j + 1), hm[cur].dp[k]);
        }
        else if(k1 == L && k2 == L) hm[nxt].push(fll(hm[cur].state[k], j), hm[cur].dp[k]);
        else if(k1 == R && k2 == R) hm[nxt].push(frr(hm[cur].state[k], j), hm[cur].dp[k]);
        else
        {
            hm[nxt].push(hm[cur].state[k], hm[cur].dp[k]);
            hm[nxt].push(clrbit(hm[cur].state[k], j, j + 1) | (k2 << mov[j]) | (k1 << mov[j + 1]), hm[cur].dp[k]);
        }
    }
}
void shift(int cur)
{
//    FOR(k, hm[cur].size)
//    {
//        printf("zhuanyi:");
//        putst(hm[cur].state[k]);
//        printf(" %d m + 1 = %d",getbit(hm[cur].state[k],m + 1), m + 1);
//        puts("");
//    }
    FOR(k, hm[cur].size) if(getbit(hm[cur].state[k], m) == 0)
    {
        hm[nxt].push(hm[cur].state[k] << 2, hm[cur].dp[k]);
    }
}
void solve()
{
    LL ans = 0;
    cur = 0;
    nxt = 1;
    hm[cur].init();
    hm[cur].push(0,1);
    FOR(i,n) FOR(j,m + 1)
    {
//        printf("%d %d:\n",i , j);FOR(k, hm[cur].size)
//        {printf("\t");putst(hm[cur].state[k]);puts("");}
        hm[nxt].init();
        if(j < m)
        {
            if(a[i][j]) dpblank(i,j,cur);
            else dplock(j,cur);
        }
        else shift(cur);
        swap(cur, nxt);
    }
    FOR(i,hm[cur].size) if(hm[cur].state[i] == 0) ans += hm[cur].dp[i];
    printf("%I64d\n",ans);
}
int main()
{
    while(scanf("%d%d",&n,&m),n)
    {
        init();
        solve();
    }
//    int _T;
//    scanf("%d",&_T);
//    FORR(CAS, _T)
//    {
//        init();
//        printf("Case %d: ", CAS);
//        solve();
//    }
    return 0;
}

