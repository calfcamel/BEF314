
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
const int MAXN = 200000 + 10;
int n,q;
int l,r,x;
int a[MAXN];
int b[MAXN];
int main()
{
    scanf("%d%d",&n,&q);
    FORR(i,n) scanf("%d",&a[i]);
    a[n + 1] = 0;
    for(int i = n; i > 0; i--)
    {
        if(a[i] == a[i + 1]) b[i] = b[i + 1];
        else b[i] = i + 1;
    }
//    FORR(i,n)
//    {
//        printf("%d ",b[i]);
//    }
//    puts("");
    int ans;
    FOR(i,q)
    {
        scanf("%d%d%d",&l,&r,&x);
        ans = n + 1;
        if(a[b[l]] != x) ans = b[l];
        if(a[l] != x) ans = l;
        if(ans > r) ans = -1;
        printf("%d\n",ans);
    }
}
