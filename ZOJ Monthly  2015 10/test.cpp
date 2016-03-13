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
#define REP(i,x,y) for(int i = (x); i <= (int) (y) ; i++)

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

LL inv6 = getinv(6LL, MOD);
LL inv2 = getinv(2LL, MOD);

LL getsi2(LL x)
{
    x = x % MOD;
    LL ret = inv6;
    ret = ret * x % MOD;
    ret = ret * (x + 1LL) % MOD;
    ret = ret * (x * 2LL % MOD + 1) % MOD;
    return ret;
}
LL getsi(LL x)
{
    x = x % MOD;
    LL ret = inv2;
    ret = ret * x % MOD;
    ret = ret * (x + 1LL) % MOD;
    return ret;
}
#define LB long double
int main()
{
    int _T;
    cout << (1.0 / (0.15 * sqrt(2 * acos(-1.0)))* exp(-1.0 * (20-21.4) * (-1.4) / 2 / 0.15 / 0.15)) << endl;
}
