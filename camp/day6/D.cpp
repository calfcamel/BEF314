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
const int MAXN = 100005;

int a[MAXN];
int b[MAXN];
vector<pair<int, int> > v,v2;
const int Maxn = MAXN;
int n;
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
	void hei(int x)
	{
	    int zero = x - query(x);
	    if(zero == 0)
        {
            int L = 1; int R = n;
            while(L < R)
            {
                int mid = (L + R) / 2;
                if(query(mid) == mid)
                    L = mid + 1;
                else R = mid;
            }
            insert(L, 1);
//            cout << "HEI   " << L << endl;
            return;
        }
        int L = 1; int R = x;
        while(L < R)
        {
            int mid = (L + R) / 2;
            if(mid - query(mid) < zero)
                L = mid + 1;
            else R = mid;
        }
        insert(L, 1);
//        cout << "HEI" << L << endl;
	}
}bit;
int main()
{
    scanf("%d",&n);
    FOR(i,n) scanf("%d",&a[i]);
    FOR(i,n) scanf("%d",&b[i]);
    v.clear();
    FOR(i,n) v.PB(MP(-a[i],-b[i]));
    sort(all(v));
//    FOR(i,n) v[i].AA = -v[i].AA;
//    FOR(i,n) v[i].BB = -v[i].BB;

    v2.clear();
    bit.init();
    for(int i = 1; i < n; i++) v2.PB(MP(v[i].BB, i));
    sort(all(v2));
//    FOR(i,n - 1) cout << v2[i].AA << " "; cout << endl;
//    FOR(i,n - 1) cout << v2[i].BB << " "; cout << endl;
    LL ans = 0;
    int del = 0;
    for(int i = 0; i < n - 1; i++)
    {
//        if(del == n / 2) break;
        int t = v2[i].BB;
//        dbg(t);
//        cout << "QY = " << bit.query(t) + del << " " << t << endl;
        if(bit.query(t) < t)
        {
//            dbg(v2[i].AA);
            del ++;
            ans = ans - v2[i].AA;
            bit.hei(t);
            bit.hei(t);
        }
    }
    cout << ans << endl;
}

/*
7
7 6 5 4 3 2 1
1 2 3 4 5 6 7
8
8 7 6 5 4 3 2 1
1 1 1 3 3 3 1 3
6
6 5 4 3 2 1
1 2 3 4 5 6
6
6 5 4 3 2 1
1 2 1 4 1 6
5
1 2 3 4 5
2 3 4 5 6
10
10 9 8 7 6 5 4 3 2 1
10 100 150 9 149 1 80 70 60 50
*/
