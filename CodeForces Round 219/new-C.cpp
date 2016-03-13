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
#include <iomanip>
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
#define FOR(i,x) for(int i = 0, _END_ = (int)(x); i < _END_ ; i++)
#define REP(i,x,y) for(int i = x,  _END_ = (int)(y); i <= _END_ ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
int a[1000050];
const int MAX = 1000000;
int n;
int x;
int main()
{
    for(int i = 0; i <= MAX; i++) a[i] = 0;
    scanf("%d",&n);
    FOR(i,n)
    {
        scanf("%d",&x);
        a[x]++;
    }
    int ans = 0;
    int now = 0;
    int del;
    for(int i = MAX; i > 1; i--)
    {
        now += a[i];
        del = min(now, a[i / 2]);
        assert(del >= 0);
        a[i / 2] -= del;
        now -= del;
        ans += del;
    }
    printf("%d\n",n - ans);
}

