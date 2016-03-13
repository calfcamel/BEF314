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
#define ccmin(x,y) if(x == -1) x = y; else x = min(x,y)
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
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 100 + 5;
int a[MAXN][MAXN];
int ans[MAXN][MAXN];
char s[MAXN][MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    FORR(i,n) scanf("%s",s[i]);
    clr(a,0);
    clr(ans,0);
    FORR(i,n) FOR(j,m)
    {
        if(s[i][j] == 'T')
        {
            a[i][j + 1] = 1;
            ans[i][j + 1] = MAXN;
        }
    }
//    int now = 0;
//    FORR(i,n)
//    {
//        now = 0;
//        for(int j = 1; j <= m; j++)
//        {
//            if(a[i][j] == 0) now = 0;
//            else now++;
//            cmin(ans[i][j], now);
//        }
//    }
//    FORR(i,n)
//    {
//        now = 0;
//        for(int j = m; j > 0; j--)
//        {
//            if(a[i][j] == 0) now = 0;
//            else now++;
//            cmin(ans[i][j], now);
//        }
//    }
//    FORR(j,m)
//    {
//        now = 0;
//        for(int i = 1; i <= n; i++)
//        {
//            if(a[i][j] == 0) now = 0;
//            else now++;
//            cmin(ans[i][j], now);
//        }
//    }
//    FORR(j,m)
//    {
//        now = 0;
//        for(int i = n; i > 0; i--)
//        {
//            if(a[i][j] == 0) now = 0;
//            else now++;
//            cmin(ans[i][j], now);
//        }
//    }
    FOR(k,100)
    {
        FORR(i,n) FORR(j,m)
        {
            cmin(ans[i][j], 1 + min(min(ans[i + 1][j],ans[i - 1][j]),min(ans[i][j + 1], ans[i][j - 1])));
        }
    }
    int maxans = 0;
    FORR(i,n) FORR(j,m) cmax(maxans,ans[i][j]);
    if(maxans < 10)
    {
        FORR(i,n)
        {
            FORR(j,m)
            {
                if(ans[i][j]) printf(".%d",ans[i][j]);
                else printf("..");
            }
            puts("");
        }
    }
    else
    {
        FORR(i,n)
        {
            FORR(j,m)
            {
                if(ans[i][j])
                {
                    if(ans[i][j] < 10) printf("..%d",ans[i][j]);
                    else printf(".%d",ans[i][j]);
                }
                else printf("...");
            }
            puts("");
        }
    }
    return 0;
}
