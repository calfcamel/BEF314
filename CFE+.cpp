
// calfcamel
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
const int MAXN = 100000 + 5;
LL a[MAXN];
LL sum[MAXN];
int d[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%I64d",&a[i]);
    clr(d,0);
    clr(sum,0);
    sum[n + 1] = 0;
    for(int i = n; i >= 1; i--)
    {
        sum[i] = sum[i + 1];
        if(a[i] >= 0)
            sum[i] += a[i];
    }
    LL tot = 0;
    LL del = 0;
    for(int i = 1; i <= n; i++)
    {
        tot++;
        if(a[i] >= 0) continue;
        del = a[i] * tot;
        del = -del;
        if(del > sum[i])
        {
            d[i] = 1;
            tot--;
        }
    }
    LL now = 0;
    tot = 0;
    for(int i = 1; i <= n; i++)
    {
        if(d[i]) continue;
        tot++;
        now += tot * a[i];
    }
    cout << now << endl;
}

