
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
//const int mov[13] = {0,2,4,6,8,10,12,14,16,18,20,22,24};
inline int getbit(int st, int k) {return (st >> k) & 1;}
inline int clrbit(int st, int k){return st&~(1 << k);}
inline int clrbit(int st, int i, int j){return clrbit(st,i) & clrbit(st,j);}
inline int clrbit(int st, int i, int j, int k){return clrbit(st,i,k) & clrbit(st,j);}
int n,m;
int del;
const int MAXN = 20;
int a[MAXN][MAXN];
char str[MAXN + 1];
const int HASH = 30001;
const int STATE = 1000010;
int cur,nxt;
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
int totst;
void putst(int st)
{
    int tmp;
    FOR(j,totst)
    {
        tmp = getbit(st,j);
        if(tmp == 0) putchar('0');
        if(tmp == 1) putchar('1');
    }
}
void init()
{
    n = 8;
    FOR(i,n) FOR(j,m) a[i][j] = 1;
    FOR(i,del)
    {
        scanf("%s",str);
        a[str[1] - 'A'][str[0] - 'A'] = 0;
    }
    totst = 1 + 2 * m;
//    FOR(i,n)
//    {
//        FOR(j,m) cout << a[i][j]; cout << endl;
//    }
}
int t1,t2,t3;
int k1,k2,k3;
void dplock(int j)
{
    FOR(k, hm[cur].size)
    {
        k1 = getbit(hm[cur].state[k], 2 * j);
        k2 = getbit(hm[cur].state[k], 2 * j + 1);
        k3 = getbit(hm[cur].state[k], 2 * j + 2);
        if(k1 + k2 + k3 == 0) hm[nxt].push(hm[cur].state[k], hm[cur].dp[k]);
    }
}
void dpblank(int i, int j)
{
    t1 = 2 * j;
    t2 = 2 * j + 1;
    t3 = 2 * j + 2;
    FOR(k, hm[cur].size)
    {
        k1 = getbit(hm[cur].state[k], t1);
        k2 = getbit(hm[cur].state[k], t2);
        k3 = getbit(hm[cur].state[k], t3);
        if(k1 + k2 + k3 == 0)
        {
            hm[nxt].push(clrbit(hm[cur].state[k],t1,t2,t3) | (1 << t1) | (1 << t2), hm[cur].dp[k]);
            hm[nxt].push(clrbit(hm[cur].state[k],t1,t2,t3) | (1 << t3) | (1 << t2), hm[cur].dp[k]);
            hm[nxt].push(clrbit(hm[cur].state[k],t1,t2,t3) | (1 << t1) | (1 << t3), hm[cur].dp[k]);
        }
        else if(k1 + k2 + k3 == 1)
        {
            hm[nxt].push(clrbit(hm[cur].state[k],t1,t2,t3) | (1 << t1), hm[cur].dp[k]);
            hm[nxt].push(clrbit(hm[cur].state[k],t1,t2,t3) | (1 << t2), hm[cur].dp[k]);
            hm[nxt].push(clrbit(hm[cur].state[k],t1,t2,t3) | (1 << t3), hm[cur].dp[k]);
        }
        else if(k1 + k2 + k3 == 2)
        {
            hm[nxt].push(clrbit(hm[cur].state[k],t1,t2,t3), hm[cur].dp[k]);
        }
    }
}
void shift1()
{
    FOR(k, hm[cur].size) if(getbit(hm[cur].state[k], 0) + getbit(hm[cur].state[k], totst - 1) == 0)
    {
        hm[nxt].push(hm[cur].state[k], hm[cur].dp[k]);
    }
}
void shift2()
{
    FOR(k, hm[cur].size) if(getbit(hm[cur].state[k], totst - 2) + getbit(hm[cur].state[k], totst - 1) == 0)
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
//        cout << i << " " << j << ": \n";
//        if(j == 0) FOR(k, hm[cur].size)
//        {
//            printf("\t");
//            putst(hm[cur].state[k]);
//            printf(" %d\n", hm[cur].dp[k]);
//        }
        hm[nxt].init();
        if(j < m)
        {
            if(a[i][j]) dpblank(i,j);
            else dplock(j);
        }
        else if(i & 1) shift1(); else shift2();
        swap(cur, nxt);
    }
    FOR(i,hm[cur].size) if(hm[cur].state[i] == 0) ans += hm[cur].dp[i];
    printf("%lld\n",ans);
}
int main()
{
    while(~scanf("%d%d",&m,&del))
    {
        init();
        solve();
    }
    return 0;
}
