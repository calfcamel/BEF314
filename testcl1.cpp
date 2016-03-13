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
const LL MOD = 100000007;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 10000 + 5;
int n;
int f[MAXN];
int ans[MAXN];
int main()
{
    clr(f,0);
    FORR(i,5000)
    {
        int now = 2 * i;
        int add = 2 * i;
        while(now < MAXN)
        {
            f[now]++;
            now += add;
        }
    }
    FORR(i,10000)
    {
        ans[i] = i;
    }
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",CAS,ans[n] - f[n]);
    }
    return 0;
}

