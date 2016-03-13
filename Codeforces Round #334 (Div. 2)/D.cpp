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
const int MAXINT = 0x3FFFFFFF; // INF / 2
const int MAXN = 1000000 + 5;
int vis[MAXN];
int tou[MAXN];
int length[MAXN];
int main()
{
    LL p,k;
    cin >> p >> k;
    if(k == 0)
    {
        LL ans = 1;
        FOR(i,p - 1) ans = ans * p % MOD;
        cout << ans << endl;
        return 0;
    }

    LL ans = 1;
    clr(vis, 0);
    clr(length,0);
    clr(tou,0);
    int cnt = 0;
    int now;
    FOR(i,p) if(!vis[i])
    {
        now = i;
        cnt = 1;
        vis[i] = 1;
        tou[i] = 1;
        while(!vis[now * k % p])
        {
            cnt++;
            vis[now * k % p] = 1;
            now = now * k % p;
        }
        length[cnt]++;
        tou[i] = cnt;
    }
//    dbg(ans);
    FOR(i,p) if(tou[i] != 0)
    {
        if(tou[i] != 1) ans = ans * (tou[i]  * length[tou[i]] % MOD + length[1]) % MOD;
        else ans = ans * (tou[i]  * length[tou[i]] % MOD) % MOD;
//        dbg(tou[i]  * (length[tou[i]] + 1));
    }
    cout << ans << endl;
}
