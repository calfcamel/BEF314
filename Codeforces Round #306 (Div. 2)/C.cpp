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
const int MAXN = 100000 + 5;

char s[1000];
int f[10];
int t[10];
int n;
bool check(int x)
{
    if(x / 10 == 0)
    {
        if(f[x] != -1) return true;
    }
    else if(x / 100 == 0)
    {
        if(f[x / 10] != -1 && f[x % 10] != -1 && f[x / 10] < t[x % 10]) return true;
    }
    else
    {
        int l = f[x / 100];
        int r = t[x % 10];
        int m = x / 10 % 10;
        if(l == -1 || l >= r) return false;
        for(int i = l + 1; i < r; i++) if(s[i] - '0' == m) return true;
    }
    return false;
}
int main()
{
    scanf("%s",s);
    n = strlen(s);
    FOR(i,10) f[i] = -1;
    FOR(i,n)
    {
        t[s[i] - '0'] = i;
        if(f[s[i] - '0'] == -1) f[s[i] - '0'] = i;
    }
    FOR(i,125)
    {
        int tmp = i * 8 ;
        if(check(tmp))
        {
            puts("YES");
            printf("%d\n",tmp);
            return 0;
        }
    }
    puts("NO");
}
