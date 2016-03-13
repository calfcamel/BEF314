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
const int MAXN = 2000 + 5;
int n,k;
int a[MAXN];
int c[MAXN];
vector<pii> v1;
vector<pii> vans;
pii ans[MAXN];
int vis[MAXN];
int main()
{
    clr(c,0);
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i] != -1) c[a[i]] ++;
        else c[0] ++;
    }
    v1.clear();
    for(int i = 1; i <= n; i++)
        if(c[i]) v1.PB(MP(c[i],i));
    if(v1.size() == 0)
    {
        puts("YES");
        for(int i = 1; i <= n; i++)
            puts("1 1");
        return 0;
    }
    sort(v1.begin(),v1.end());
    int nn = v1.SZ;
    v1[nn - 1].AA += c[0];
    vans.clear();
    int t = k;
    FOR(i,nn)
    {
        while(v1[i].AA >= k)
        {
            v1[i].AA -= k;
            FOR(i,k) vans.PB(MP(v1[i].BB, v1[i].BB));
        }
        if(v1[i].AA)
        {
            bool boo = true;
            for(int j = i + 1; j <= nn; j++)
            {
                if(v1[i].AA + v1[j].AA >= t)
                {
                    boo = false;
                    v1[j].AA -= t - v1[i].AA;
                    v1[i].AA = 0;
                    FOR(i,t) vans.PB(MP(v1[i].BB, v1[j].BB));
                    break;
                }
            }
            if(boo)
            {
                puts("NO");
                return 0;
            }
        }
    }
    clr(vis,0);
    for(int i = 1; i <= n; i++) if(a[i] != -1)
    {
        FOR(j,n) if(!vis[j]) if(a[i] == vans[j].AA || a[i] == vans[j].BB)
        {
            vis[j] = 1;
            ans[i] = vans[j];
            break;
        }
    }
    for(int i = 1; i <= n; i++) if(a[i] == -1)
    {
        FOR(j,n) if(!vis[j])
        {
            vis[j] = 1;
            ans[i] = vans[j];
            break;
        }
    }
    puts("YES");
    for(int i = 1; i <= n; i++) printf("%d %d\n",ans[i].AA, ans[i].BB);
    puts("-------");
    for(int i = 0; i < n; i++) printf("%d %d\n",vans[i].AA, vans[i].BB);
}



