
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
typedef pair<int, int> PII;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int MAXN = 1000000 + 10;


int main()
{
    int n;
    scanf("%d",&n);
    if(n == 1)
    {
        puts("1 1");
        return 0;
    }
    if(n == 2)
    {
        puts("1 1 2 2");
        return 0;
    }
    if(n & 1)
    {
        printf("%d",n);
        for(int i = 2; i < n; i += 2) printf(" %d", i);
        for(int i = n - 1; i > 0; i -= 2) printf(" %d", i);
        for(int i = 1; i < n; i += 2) printf(" %d", i);
        printf(" %d",n);
        for(int i = n - 2; i > 0; i -= 2) printf(" %d", i);
        puts("");
        return 0;
    }
    else
    {
        printf("%d",n);
        for(int i = 1; i < n; i += 2) printf(" %d", i);
        for(int i = n - 1; i > 0; i -= 2) printf(" %d", i);
        for(int i = 2; i < n; i += 2) printf(" %d", i);
        printf(" %d",n);
        for(int i = n - 2; i > 0; i -= 2) printf(" %d", i);
        puts("");
        return 0;
    }
}
