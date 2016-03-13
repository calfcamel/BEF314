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
const int MAXN = 2005;
typedef int sint;
//vector<pair<sint,sint> > v[8];
int tot[8];
//int disx[8][MAXN * MAXN];
//int disy[8][MAXN * MAXN];
int n;
char str[MAXN][10];
int a[MAXN][MAXN];
int d[MAXN];
int vis[MAXN];
int dis(sint i, sint j)
{
    sint ret = 0;
    FOR(k,7) if(str[i][k] != str[j][k]) ret++;
//    cout << i << " " << j << " " << ret << endl;
    return ret;
}
//struct myset
//{
//    sint f[MAXN];
//    void init()
//    {
//        FOR(i,n) f[i] = i;
//    }
//    sint gf(sint x)
//    {
//        if(x == f[x]) return x;
//        f[x] = gf(f[x]);
//    }
//    bool uni(sint x, sint y)
//    {
//        sint fx = gf(x);
//        sint fy = gf(y);
//        if(fx == fy) return false;
//        f[fx] = fy;
//        return true;
//    }
//}st;
//void Kruskal()
//{
//    int ans = 0;
//    st.init();
//    FOR(i,8)
//    {
////        int maxj = v[i].SZ;
////        FOR(j,maxj) if(st.uni(v[i][j].AA, v[i][j].BB)) ans += i;
//        FOR(j,tot[i]) if(st.uni(disx[i][j], disy[i][j])) ans += i;
//    }
//    printf("The highest possible quality is 1/%d.\n",ans);
//}
int prim(int n)
{
    clr(vis,0);
    vis[0] = 1;
    FOR(i,n) d[i] = a[0][i];
    int ret = 0;
    FOR(i,n - 1)
    {
        int MIN = 1000000000;
        int j;
        FOR(i,n) if(!vis[i] && MIN > d[i])
        {
            MIN = d[i];
            j = i;
        }
        vis[j] = 1;
        FOR(i,n) cmin(d[i], a[j][i]);
        ret += MIN;
    }
    return ret;
}
int main()
{
    while(~scanf("%d",&n))
    {
        if(n == 0) return 0;
        FOR(i,n) scanf("%s",str[i]);
//        FOR(i,8) v[i].clear();
        FOR(i,8) tot[i] = 0;
        int td;
        for(sint i = 0; i < n; i++) for(sint j = i; j < n; j++)
        {
            td = dis(i,j);
            a[i][j] = td;
            a[j][i] = td;
//            disx[d][tot[d]] = i;
//            disy[d][tot[d]] = j;
//            tot[d]++;
        }
        printf("The highest possible quality is 1/%d.\n",prim(n));
//            v[dis(i,j)].PB(MP(i,j));
//        FOR(i,8)
//        {
//            cout << i << ":" << endl;
//            FOR(j,v[i].SZ) cout << "\t" << v[i][j].AA << " " << v[i][j].BB << endl;
//        }
//        Kruskal();
    }
}
