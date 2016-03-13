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
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;


const int MAXN = 10000 + 5;
int n;
int a[100005];
int f[100005];
int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    a[0] = 1000000001;
    clr(f,0);
    f[0] = 0;
    for(int i = 1; i <= n; i++)
        if(a[i] >= a[i - 1]) f[i] = f[i - 1] + 1;
        else f[i] = 1;
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}
