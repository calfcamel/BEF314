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
const LL MOD = 105225319;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int N = 32000000;
LL prime[N];
int totp;
bool check[N];
void Eular()
{
	clr(check,false);
	int tot = 0;
	for (int i = 2; i < N; i++)
	{
		if (!check[i]) prime[tot++] = i;
		for (int j = 0; j < tot; j++)
		{
			if (i * prime[j] >= N) break;
			check[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
	totp = tot;
}
LL yinzi[200];
int numyz[200];
int totyz;
void fenjie(LL n)
{
    totyz = 0;
    FOR(i, totp) if(n % prime[i] == 0)
    {
        yinzi[totyz] = prime[i];
        numyz[totyz] = 0;
        while(n % prime[i] == 0)
        {
            n /= prime[i];
            numyz[totyz] ++;
        }
        totyz ++;
    }
    if(n != 1)
    {
        yinzi[totyz]++;
        numyz[totyz] = 1;
        totyz++;
    }
}
void dfs(int k, LL now)
{
    if(k == totyz)
    {

    }
    FOR(i,numyz[k])
    {
        if(i) now *= yinzi[k];
        dfs(k + 1, now);
    }
}
int main()
{
    return 0;
}

