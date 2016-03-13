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
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;


const int MAXN = 200000 + 5;
struct{
    int a[10005];
    int n = 10004;
    void CLR()
    {
        clr(a,0);
    }
    void ADD(int x, int c)
    {
         for (int i=x; i<=n; i+=i&(-i)) a[i] = max(a[i], c);
    }
    int MAX(int x)
    {
        int s = 0;
        for (int i=x; i>0; i-=i&(-i)) s = max(s, a[i]);
        return s;
    }
}s;
int ans = 0;
int a[MAXN];
int f[MAXN];
int g[MAXN];
int tot;
int st[20];
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {

        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i = 0; i < n; i++)
            a[i + n] = a[i];
        tot = 0;
        for(int i = 0; i < n; i++)
            if(a[i] == 10000) st[tot++] = i;
        int add;
        ans = 0;
        for(int l = 0; l < tot; l++)
        {
            add = st[l];
            clr(f,0);
            s.CLR();
            for(int i = add; i < add + n; i++) if(a[i] != 10000)
            {
                f[i] = a[i] + s.MAX(10000 - a[i]);
                s.ADD(10000 - a[i],f[i]);
            }
            s.CLR();
            clr(g,0);
            for(int i = add + n - 1; i >= add; i--) if(a[i] != 10000)
            {
                g[i] = a[i] + s.MAX(10000 - a[i]);
                s.ADD(10000 - a[i],g[i]);
            }
            for(int i = add + 1; i < add + n; i++) f[i] = max(f[i],f[i - 1]);
            for(int i = add + n - 1 - 1; i >= add; i--) g[i] = max(g[i],g[i + 1]);
            for(int i = add; i < add + n - 1; i++)
            {
                ans = max(ans,f[i] + g[i + 1]);
            }
            ans = max(ans, g[add]);
            ans = max(ans, f[add + n - 1]);
        }
        printf("%d\n",ans + 10000);
    }
    return 0;
}
