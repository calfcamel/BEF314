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


const int MAXN = 100000 + 5;

int f[MAXN];
int vis[MAXN];
int Find(int x)
{
    if(f[x] == x) return x;
    f[x] = Find(f[x]);
}
int Union(int a, int b)
{
    int x,y;
    x = Find(a);
    y = Find(b);
    if(x != y)
    {
        f[x] = y;
        return 1;
    }
    return 0;
}
void init()
{
    for(int i = 0; i < MAXN; i++)
    {
        vis[i] = 0;
        f[i] = i;
    }
}
int main()
{
    int b = 1;
    init();
    int x,y;
    while(scanf("%d%d",&x,&y))
    {
        if(x == -1) return 0;
        if(x == 0)
        {
            int bb = 0;
            int fa = -1;
            if(b)for(int i = 1; i < MAXN; i++)
            {
                if(vis[i])
                {
                    if(!bb)
                    {
                        bb = 1;
                        fa = Find(i);
                    }
                    else
                    {
                        if(fa != Find(i))
                            b = 0;
                    }
                }
            }
            if(b) puts("Yes");else puts("No");
            init();
            b = 1;
        }
        else
        {
            b &= Union(x,y);
            vis[x] = 1;
            vis[y] = 1;
        }
    }
    return 0;
}
