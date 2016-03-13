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
#include <iomanip>
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
#define REP(i,x,y) for(int i = x,  _END_ = (int)(y); i <= _END_ ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
int ans[100];
int ansst[100];
int n = 12;
int a[100];
void gao(int st)
{
//    dbg(st);
    a[n] = 2;
    FOR(i,n) a[i] = (st & (1 << i)) ? 1:0;
//    FOR(i,n) cout << a[i]; cout << endl;
    int now = 1;
    int ret = 0;
    REP(i,1,n)
    {
        if(a[i] != a[i - 1])
        {
            if(a[i - 1] == 0) ret += now * now;
            else ret -= now * now;
            now = 1;
        }
        else now++;
    }
    int x = 0;
    FOR(i,n) x += a[i];
//    if(st == 3413) dbg(ret);
    if(ret > ans[x])
    {
        ans[x] = ret;
        ansst[x] = st;
    }
}
int main()
{
    REP(i,0,n) ans[i] = - n * n * 2;
    FOR(st,1 << n)
    {
        gao(st);
    }
    REP(i,0,n)
        cout << ans[i] << " " << ansst[i] << endl;
}

