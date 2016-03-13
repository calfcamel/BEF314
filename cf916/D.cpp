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
typedef pair<int, int> PII;

const int MAXN = 1000000 + 5;

LL a[MAXN];
LL b[MAXN];
LL c[MAXN];
int main()
{
    LL n,k,x,ans = 0;
    scanf("%I64d%I64d%I64d",&n,&k,&x);
    LL t;
    for(int i = 0; i < n; i++)
    {
        scanf("%I64d",&a[i]);
    }
    b[0] = a[0];
    for(int i = 1; i < n; i++)
        b[i] = b[i - 1] | a[i];
    c[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--)
        c[i] = c[i + 1] | a[i];
    ans = 0;
    LL tmp = 1;
    for(int i = 0; i < k; i++)
        tmp *= x;
    ans = max((a[0] * tmp) | c[1], (a[n - 1] * tmp) | b[n - 2]);
    for(int i = 1; i < n - 1; i++)
        ans = max(ans, (a[i] * tmp) | b[i - 1] | c[i + 1]);
    cout << ans << endl;
    return 0;
}

