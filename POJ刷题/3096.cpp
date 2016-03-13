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
const int MAXN = 200005;
char s[MAXN];
int vis[26 * 26];
int getnum(char A, char B)
{
    return (A - 'A') * 26 + (B - 'A');
}
int main()
{
    while(scanf("%s",s))
    {
        if(s[0] == '*') return 0;
        int l = strlen(s);
        int boo = true;
        int tmp;
        for(int d = 1; d < l; d++)
        {
            clr(vis,0);
            FOR(i, l - d)
            {
                tmp = getnum(s[i], s[i + d]);
                if(vis[tmp]) boo = false;
                vis[tmp] = 1;
            }
            if(!boo) break;
        }
        if(boo) printf("%s is surprising.\n",s);
        else printf("%s is NOT surprising.\n",s);
    }
}

