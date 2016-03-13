#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
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
#define MP3(x,y,z) make_pair(x, makepair(y,z))
#define AA first
#define BB second
#define AAA first.first
#define BBA second.first
#define BBB second.second
#define PB push_back
#define SZ size()
#define dbg(x) cerr <<#x<<" = " << x << endl
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)

vector<piii> v;
const int MAXN = 10000 + 5;
char s[MAXN];
int del[MAXN];
int boo[MAXN];
int n;
int n2;
int x[MAXN];
int ans[MAXN];
const int cha = 'a' - 'A';
int totdel;
void solve()
{
    char last = 0;
    int lasti = -1;
    FOR(i,n2) if(!del[i])
    {
        if(last - s[i] == cha || s[i] - last == cha)
        {
            del[lasti] = 1;
            del[i] = 1;
            if(boo[i]) ans[i] = x[lasti];
            else ans[lasti] = x[i];
            last = 0;
            lasti = -1;
            totdel ++;
        }
        else
        {
            lasti = i;
            last = s[i];
        }
    }
}
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define LL long long
const int maxn = 111111;
LL add[maxn<<2];
LL sum[maxn<<2];
void PushUp(int rt) {
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void PushDown(int rt,int m) {
	if (add[rt]) {
		add[rt<<1] += add[rt];
		add[rt<<1|1] += add[rt];
		sum[rt<<1] += add[rt] * (m - (m >> 1));
		sum[rt<<1|1] += add[rt] * (m >> 1);
		add[rt] = 0;
	}
}
void build(int l,int r,int rt) {
	add[rt] = 0;
	if (l == r) {
		scanf("%lld",&sum[rt]);
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUp(rt);
}
void update(int L,int R,int c,int l,int r,int rt) {
	if (L <= l && r <= R) {
		add[rt] += c;
		sum[rt] += (LL)c * (r - l + 1);
		return ;
	}
	PushDown(rt , r - l + 1);
	int m = (l + r) >> 1;
	if (L <= m) update(L , R , c , lson);
	if (m < R) update(L , R , c , rson);
	PushUp(rt);
}
LL query(int L,int R,int l,int r,int rt) {
	if (L <= l && r <= R) {
		return sum[rt];
	}
	PushDown(rt , r - l + 1);
	int m = (l + r) >> 1;
	LL ret = 0;
	if (L <= m) ret += query(L , R , lson);
	if (m < R) ret += query(L , R , rson);
	return ret;
}
int main()
{
    totdel = 0;
    clr(del,0);
    scanf("%d%s",&n,s);
    n2 = 2 * n;
    clr(boo,0);
    int tot = 0;
    FOR(i,n2) if(s[i] >= 'a') x[i] = ++tot;
    FOR(i,n2) if(s[i] < 'a') boo[i] = 1;
    FOR(i,n) solve();
    if(totdel == n)
    {
        bool b = false;
        FOR(i,n2) if(boo[i])
        {
            if(b) printf(" "); else b = true;
            printf("%d",ans[i]);
        }
        puts("");
    }
    else puts("Impossible");
    return 0;
}
