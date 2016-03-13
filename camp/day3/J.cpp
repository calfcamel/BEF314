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
#define LL long long
const int MAXN = 1001;
int a[MAXN][MAXN];
int cnt;
void add(int x,int y)
{
    a[x][y] = cnt;
    a[x + 1][y] = cnt;
    a[x][y + 1] = cnt;
    a[x + 1][y + 1] = cnt;
    cnt++;
}
int main()
{
    int n;
    int l;
    scanf("%d",&n);
    if(n == 1)
    {
        l = 1;
        a[0][0] = 1;
    }
    else if(n != 4 && n <= 5)
    {
        l = -1;
    }
    else
    {
        bool boo = false;
        if(n & 1)
        {
            boo = true;
            n = n - 3;
        }
        int x = (n - 2) / 2;
        l = 2 * (1 + x);
        cnt = 1;
        FOR(i,l / 2) add(0,i * 2);
        FOR(i,l / 2) if(i) add(i * 2,0);
        REP(i,2,l) REP(j,2,l) a[i][j] = cnt;
        cnt++;
        if(boo)
        {
            int tmp = (l - 2) / 2 + 2;
            REP(i,tmp,l) REP(j,2,l) a[i][j] = cnt;
            cnt++;
            REP(i,2,l) REP(j,tmp,l) a[i][j] = cnt;
            cnt++;
            REP(i,tmp,l) REP(j,tmp,l) a[i][j] = cnt;
            cnt++;
        }
    }
    if(l == -1)
    {
        printf("Impossible\n");
    }
    else
    {
        printf("Possible\n%d\n",l);
        FOR(i,l)
        {
            FOR(j,l) if(j) printf(" %d",a[i][j]); else printf("%d",a[i][j]);
            printf("\n");
        }
    }
}
