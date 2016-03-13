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
LL Exgcd(LL a,LL b,LL &x,LL &y){
    LL r,t;
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    r=Exgcd(b,a%b,x,y);
    t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
LL getinv(LL a,LL M)
{
    LL x,y;
    Exgcd(a,M,x,y);
    return (x % MOD + MOD) % MOD;
}

const int MAXN = 2000000 + 5;

LL a,b,c,d,aa,bb,cc,dd,ans;
LL f[MAXN];
LL g[MAXN];
int main()
{
    f[0] = 1;
    for(LL i = 1; i < MAXN; i++)
        f[i] = i * f[i - 1] % MOD;
    for(int i = 0; i < MAXN; i++)
        g[i] = getinv(f[i],MOD);
    int n;
    cin >> n;
    n ++;
    LL ans = f[2 * n];
    ans = ans * g[n] % MOD;
    ans = ans * g[n] % MOD;
    ans = (ans + MOD - 1) % MOD;
    cout << ans << endl;
    return 0;
}
