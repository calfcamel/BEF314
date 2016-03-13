
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
typedef pair<LL, LL> PII;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
#define LL long long
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
//扩展欧几里得
//ax+by=d;
//x'=x+b/d;
//y'=y-a/d;
//a,b要求非负!
long long d,x,y;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        long long ret=exgcd(b,a%b,x,y);
        long long temp=x;
        x=y;
        y=temp-a/b*y;
        return ret;
    }
}
void getyinzi(LL x)
{
    cout << x << "de yinzi"<< endl;
    REP(i,1,x) if(x % i == 0) cout << i << endl;
}
const int N = 1000;
LL prime[N];
bool check[N];
int totp;
void Eular()
{
	clr(check,false);
    totp = 0;
	for (int i = 2; i < N; i++)
	{
		if (!check[i]) prime[totp++] = i;
		for (int j = 0; j < totp; j++)
		{
			if (i * prime[j] >= N) break;
			check[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
//const int N = 5000000 + 5;
//int prime[N];
//bool check[N];
LL phi[N];
void Phi()
{
	clr(check,false);
	phi[1] = 1;
    totp = 0;
	for (int i = 2; i < N; i++)
	{
		if (!check[i])
		{
			prime[totp++] = i;
			phi[i]  = i - 1;
		}
		for (int j = 0; j < totp; j++)
		{
			if (i * prime[j] >= N) break;
			check[i * prime[j]] = true;
			if (i % prime[j] == 0)
			{
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
}
LL inv(LL a,LL M)
{
    LL x,y;
    exgcd(a,M,x,y);
    return (x % M + M) % M;
}
int main()
{
//    getyinzi(54);
//    Eular(); FOR(i,totp) cout << prime[i] << " ";
//    cout << gcd(2009,1394) << endl;
//    LL a = 2009 / gcd(2009,1394); LL b = 1394 / gcd(2009,1394); exgcd(a,b,x,y); cout << x << " " << y << endl;
//    dbg(inv(424,915));
//    LL p = 1; int ans = 0; while(1){p = p * 5 % 47; ans ++; if(p == 37) break;} dbg(ans);
    Phi(); dbg(phi[32]); dbg(phi[35]); dbg(phi[36]); dbg(phi[phi[37]]);
//    REP(x,500 + 1,1000 - 1) if(x % 7 == 1 && x % 8 == 3 && x % 9 == 5) cout << x << endl;
}
