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


const int MAXN = 1000 + 5;

int f[MAXN];
int Find(int x)
{
    if(f[x] == x) return x;
    f[x] = Find(f[x]);
}
void Union(int a, int b)
{
    int x,y;
    x = Find(a);
    y = Find(b);
    if(x != y) f[x] = y;
}
void init()
{
    for(int i = 0; i < MAXN; i++)
        f[i] = i;
}
int main()
{
    int _T;
    scanf("%d",&_T);
    while(_T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int x,y;
        init();
        for(int i = 0; i < m; i ++)
        {
            scanf("%d%d",&x,&y);
            Union(x,y);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(Find(i) == i)
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
