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
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
LL tot = 0;
LL a[20];
void fenjie(LL n)
{
    tot = 0;
    while(n)
    {
        a[tot++] = n % 10;
        n /= 10;
    }
}
LL fac[10];
void init()
{
    FOR(i,10)
    {
        fac[i] = 1;
        FORR(j, i) fac[i] *= j;
    }
}
LL f(LL n)
{
    fenjie(n);
    LL ret = 0;
    FOR(i,tot) ret += fac[a[i]];
    return ret;
}
LL sf(LL n)
{
    n = f(n);
    fenjie(n);
    LL ret = 0;
    FOR(i,tot) ret += a[i];
    return ret;
}
LL g[200];
void findg(int n)
{
    FORR(i, 150) g[i] = -1;
    FOR(i, n)
    {
        LL t = sf(i);
        if(i % 1000000 == 0) cout << i << endl;
        if(t <= 150 && t >= 0 && g[t] == -1) g[t] = i;
    }
}
LL sg(LL n)
{
    n = g[n];
    fenjie(n);
    LL ret = 0;
    FOR(i,tot) ret += a[i];
    return ret;
}
int main()
{
    init();
//    FOR(i,10) cout << fac[i] << endl;
//    dbg(f(342));
//    dbg(sf(342));
    findg(1000000000);
    for(int i = 0; i <= 150; i++) cout << i << " " << g[i] << endl;
    LL sum = 0;
    FORR(i,20) sum += sg(i);
    dbg(sum);
}


