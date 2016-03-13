
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
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%I64d",&a[i]);
    LL now = 0;
    for(int i = 1; i <= n; i++)
        now += a[i] * i;
    LL sum = 0;
    LL del = 0;
    for(int i = n; i >= 1; i--)
    {
        del = a[i] * i + sum;
        if(del < 0)
        {
            now -= del;
        }
        else
        {
            sum += a[i];
        }
    }
    cout << now << endl;
}

