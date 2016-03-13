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
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

LL absx(LL x)
{
    if(x < 0) x = -x;
    return x & 1LL;
}
int main()
{
    LL x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 > x2) swap(x1,x2);
    if(y1 > y2) swap(y1,y2);
    LL dx = x2 - x1 + 1;
    LL ca = (dx + 1) / 2;
    LL cb = dx / 2;
    LL la,lb;
    if(absx(x1 + y1) % 2 == 0 && absx(x1 + y2) % 2 == 0)
    {
        la = (y2 - y1 + 2) / 2;
        lb = la - 1;
    }
    else if(absx(x1 + y1) % 2 == 1 && absx(x1 + y2) % 2 == 1)
    {
        la = (y2 - y1) / 2;
        lb = la + 1;
    }
    else
    {
        la = lb = (y2 - y1 + 1) / 2;
    }
    cout << la * ca + lb * cb << endl;
}
