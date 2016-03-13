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
typedef pair<int, int> PII;
#define FOR(i,x) for(int i = 0, _END_ = (int)(x); i < _END_ ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int N = 10000;
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
int tot;
int S,T;
int vis[10000];
queue<int> Q;
int bit[10];
int bfs()
{
    clr(vis,-1);
    while(!Q.empty()) Q.pop();
    vis[S] = 0;
    Q.push(S);
    int x;
    int tmp;
    while(!Q.empty())
    {
        x = Q.front();
        Q.pop();
        if(x == T) return vis[x];
        bit[0] = x / 1000;
        bit[1] = x % 1000 / 100;
        bit[2] = x % 100 / 10;
        bit[3] = x % 10;
        FOR(i,10)
        {
            if(i)
            {
                tmp = i * 1000 + bit[1] * 100 + bit[2] * 10 + bit[3];
                if(!check[tmp] && vis[tmp] == -1)
                {
                    vis[tmp] = vis[x] + 1;
                    Q.push(tmp);
                }
            }
            tmp = bit[0] * 1000 + i * 100 + bit[2] * 10 + bit[3];
            if(!check[tmp] && vis[tmp] == -1)
            {
                vis[tmp] = vis[x] + 1;
                Q.push(tmp);
            }
            tmp = bit[0] * 1000 + bit[1] * 100 + i * 10 + bit[3];
            if(!check[tmp] && vis[tmp] == -1)
            {
                vis[tmp] = vis[x] + 1;
                Q.push(tmp);
            }
            tmp = bit[0] * 1000 + bit[1] * 100 + bit[2] * 10 + i;
            if(!check[tmp] && vis[tmp] == -1)
            {
                vis[tmp] = vis[x] + 1;
                Q.push(tmp);
            }
        }
    }
}
int main()
{
    Eular();
//    dbg(check[2]);
//    dbg(check[4]);
//    tot = 0;
//    FOR(i,totp) if(prime[i] >= 1000) prime[tot++] = prime[i];
    int _T;
    scanf("%d",&_T);
    while(_T--)
    {
        scanf("%d%d",&S,&T);
        printf("%d\n",bfs());
    }
}
