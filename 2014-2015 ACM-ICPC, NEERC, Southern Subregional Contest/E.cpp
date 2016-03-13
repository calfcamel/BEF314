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
int a[MAXN];
int b[MAXN];
int boo[MAXN];
int gethe()
{
    int ret = 0;
    clr(boo, 0);
    int i = 2;
    while(i <= n)
    {
        if(a[i] > b[i] && a[i - 1] > b[i - 1])
        {
            i++;
            continue;
        }
        else if(a[i] > b[i] || a[i - 1] > b[i - 1])
        {
            if(a[i] + a[i - 1] > b[i] + b[i - 1])
            {
                boo[i] = 1;
                ret++;
                i+=2;
                continue;
            }
            i++;
            continue;
        }
        else
        {
            boo[i] = 1;
            i += 2;
            ret++;
        }
    }
    return ret;
}
int main()
{
    scanf("%d",&n);
    int win = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
        if(a[i] > b[i]) win++;
    }
//    dbg(win);
    if(win > n / 2)
    {
        puts("0");
        return 0;
    }
    int he = gethe();
    int j = 0;
    if(n - win * 2 + 1 <= he)
    {
        int ans = n - win * 2 + 1;
        printf("%d\n",ans);
        FOR(i,ans)
        {
            while(boo[j] == 0) j++;
            printf("%d %d\n",j - 1, j);
            j++;
            // output
        }
    }
    else
    {
        puts("-1");
        return 0;
    }
    return 0;
}


