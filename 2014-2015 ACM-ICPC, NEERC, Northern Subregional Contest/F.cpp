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
typedef unsigned long long ULL;
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
const int MAXN = 100005;
int n;
int a[MAXN];
int aa[MAXN];
int biao[MAXN];
int b[MAXN];
int u[MAXN];
int cb[MAXN];
int cf[MAXN];
vector<int> v[MAXN];
int main()
{
//    freopen("fragmentation.in","r",stdin);
//    freopen("fragmentation.out","w",stdout);
    scanf("%d",&n);
    FOR(i,n) scanf("%d",&a[i]);
    FOR(i,n) aa[i] = a[i];
    sort(aa, aa + n);
    int laa = unique(aa,aa + n) - aa;
    int tot = 1;
    FOR(i,laa) biao[aa[i]] = tot++;
    FOR(i,n) a[i] = biao[a[i]];
//    FOR(i,n) cout << a[i] << endl;
    int totbiao = tot - 1;
    tot = 0;
    FOR(i,n) u[i] = 1;
    b[tot++] = a[0];
    FOR(i,n) if(i)
        if(a[i] != a[i - 1]) b[tot++] = a[i];
        else u[tot - 1]++;
    n = tot;
//    FOR(i,n) cout << b[i] << " " << u[i] << endl;
    clr(cb, 0);
    clr(cf, 0);
    FOR(i,n) if(i)
        if(b[i - 1] + 1 == b[i])
        {
            cf[i - 1] = 1;
            cb[i] = 1;
        }
    FOR(i,n)
    {
        v[b[i]].PB(i);
    }
//    FOR(i,n) cout << b[i] << " " << cf[i] << endl;
//    dbg(totbiao);
    for(int i = 1; i <= totbiao; i++)
    {
        int maxj = v[i].SZ;
        int ccc = -1;
        bool boo = false;
        FOR(j,maxj)
        {
            if(maxj == 1 && cf[v[i][j]] && cb[v[i][j]])
            {
                u[v[i][j] + 1] += u[v[i][j]];
                u[v[i][j] + 1] += u[v[i][j] - 1];
                u[v[i][j]] = 0;
                u[v[i][j] - 1] = 0;
                boo = true;
                break;
            }
            if(cf[v[i][j]])
            {
                if(ccc == -1)
                    ccc = v[i][j];
//                else if(rand() % 5 == 2) ccc = v[i][j];
                if(v[i + 1].SZ <= 1 || cf[v[i][j] + 1] == 0)
                {
                    u[v[i][j] + 1] += u[v[i][j]];
                    u[v[i][j]] = 0;
                    boo = true;
                    break;
                }
            }
        }
        if(boo || ccc == -1) continue;
        u[ccc + 1] += u[ccc];
        u[ccc] = 0;
        cf[ccc + 1] = 0;
    }
    int m = 0;
    FOR(i,n) if(u[i]) m++;
    bool boo = false;
    printf("%d\n",m);
    FOR(i,n) if(u[i])
    {
        if(boo) printf(" ");
        else boo = true;
        printf("%d", u[i]);
    }
    puts("");
    return 0;
}
