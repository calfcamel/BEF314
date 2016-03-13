
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
const int MAXN = 5005;

char s[MAXN];
char t[MAXN];
int h[27];
int ls;
int lt;
int nxt[MAXN];
int dp[2][MAXN];
int f[MAXN];
const int Maxn = MAXN;
struct stbit {
	int buf[Maxn];
	int lowbit(int x) { return x & (-x); }
	void init() {
		memset(buf, 0, sizeof buf);
	}
	void insert(int x, int c) {
		while(x < Maxn) {
			buf[x] = (buf[x] + c);
			x += lowbit(x);
		}
	}

	int query(int x) {
		int ans = 0;
		while(x > 0) {
			ans = (ans + buf[x]);
			x -= lowbit(x);
		}
		return ans;
	}
	int get(int x)
	{
	    if(x == 0) return 0;
	    if(x == 1) return query(x);
	    else return query(x) - query(x - 1);
	}
	int query(int l,int r)
	{
	    return query(r) - query(l);
	}
}bit[2];
int main()
{
    scanf("%s%s",s,t);
    ls = strlen(s);
    lt = strlen(t);
    t[lt++] = 'z' + 1;
    t[lt] = 0;
    FOR(i,27) h[i] = -1;
    for(int i = lt - 1; i >= 0; i--)
    {
        nxt[i] = h[t[i] - 'a'];
        h[t[i] - 'a'] = i;
    }
//    FOR(i,lt) cout << i << " " << nxt[i] << endl;
//    FOR(i,27) cout << i << " " << h[i] << endl;
//    cout << ch << endl;
    clr(f,0);
    f[lt - 1] = 0;
    for(int i = lt - 2; i >= 0; i--)
        if(t[i] == t[i + 1]) f[i] = 0;
        else f[i] = lt - 1 - i;
//    FOR(i,lt) cout << i << " " << f[i] << endl;
    clr(dp,0);
    int cur = 0;
    int tmp = 1;
//    dp[cur][lt] = 1;
//    s[ls] = 'z' + 1;
    bit[cur].init();
    bit[cur].insert(lt - 1,1);
    for(int i = ls - 1; i > 0; i--)
    {
        bit[tmp].init();
//        int snext = h[s[i]];
//        dbg(s[i]);
        int tnext = h[s[i] - 'a'];
//        dbg(tnext);
//        dbg(i);
        while(~tnext)
        {
//            dbg(tnext);
//            while(~snext)
//            {
//                if(snext > tnext) break;
//                snext = nxt[snext];
//            }
//            if(snext == -1) break;
//            cout << "QRY" << tnext  << " " << f[tnext] << endl;
            if(tnext) if(bit[cur].query(tnext, tnext + max(f[tnext] + 1, 0)))
            {
                bit[tmp].insert(tnext,1);
//                cout << " INS " << tnext << endl;
            }
            tnext = nxt[tnext];
        }
        swap(cur,tmp);
    }
    if(s[0] == t[0] && bit[cur].query(0,max(f[0]+1, 0))) puts("Yes");
    else puts("No");
}
