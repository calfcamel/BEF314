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
int n,k;
LL a[MAXN];
LL minv;
void jian(int x, LL s)
{
    while(x)
    {
        if(a[x] - minv >= s)
        {
            a[x] -= s;
            return;
        }
        else
        {
            s -= a[x] - minv;
            a[x] = minv;
        }
        x--;
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    int x;
    minv = 0;
    for(int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d",&x);
        a[i] = x;
        minv = min(minv, a[i]);
    }
    a[0] = 0;
    LL sum = 0;
    for(int i = 1; i < k; i++)
        sum += a[i];
    LL ans = 0;
    for(int i = k; i <= n; i++)
    {
        sum -= a[i - k];
        sum += a[i];
        if(sum < 0) continue;
        else
        {
            jian(i, sum + 1);
            ans += sum + 1;
            sum = -1;
        }
    }
    printf("%I64d\n",ans);
    for(int i = 1; i <= n; i++)
    {
        if(i - 1) printf(" ");
        printf("%I64d",a[i]);
    }
    puts("");
}

