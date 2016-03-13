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
#define cmaxmod(x,y) x = max((x) % MOD,(y) % MOD)
#define caddmod(x,y) x = ((x) % MOD + (y) % MOD) % MOD;
#define MP make_pair
#define AA first
#define BB second
#define PB push_back
#define SZ size()
#define dbg(x) cerr <<#x<<" = " << x << endl
#define FOR(x,y) for(int x = 0; x < (int)(y); x ++)
#define FORR(x,y) for(int x = 1; x <= (int)(y); x ++)
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;


const int MAXN = 501;

int a[MAXN][MAXN];
int b[MAXN][MAXN];
int c[MAXN];
int n;
bool checkans() {
    FOR(i,n) FOR(j,n)
    {
        if(i == j) continue;
        else if(i & j & 1)
        {
            if(b[i][j] != (c[i] | c[j])) return false;
        }
        else if((i & 1) == (j & 1))
        {
            if(b[i][j] != (c[i] & c[j])) return false;
        }
        else if(b[i][j] != (c[i] ^ c[j])) return false;
    }
    return true;
}
bool check(int p)
{
    c[0] = p;
    for(int i = 1; i < n; i++) c[i] = b[i][i - 1] ^ c[i - 1];
    return checkans();
}
int main()
{
    while(scanf("%d",&n) != EOF)
    {
        FOR(i,n) FOR(j,n) scanf("%d",&a[i][j]);
        bool boo = true;
        FOR(i,n) FOR(j,n)
        {
            if(i == j && a[i][j] != 0) boo = false;
            else if(a[i][j] != a[j][i]) boo = false;
        }
        if(boo) FOR(k,30)
        {
            int t = 1 << k;
            FOR(i,n) FOR(j,n) b[i][j] = (a[i][j] & t)? 1:0;
            if(check(0) || check(1))
            {
                ;
            }
            else
            {
                boo = false;
            }
            if(!boo) break;
        }
        if(boo) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

