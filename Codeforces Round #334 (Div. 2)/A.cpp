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
const int MAXN = 300000 + 5;
int a[100];
int b[100];
int main()
{
    int ans = 0;
    FOR(i,5) scanf("%d",&a[i]);
    FOR(i,5) scanf("%d",&b[i]);
    FOR(i,5)
    {
        ans += max(500 * (i + 1) / 250 * (250 - a[i]) - b[i] * 50, 500 / 10 * 3 * (i + 1));
    }
    int x,y;
    scanf("%d%d",&x,&y);
    ans += (2 * x - y) * 50;
    cout << ans << endl;
}
