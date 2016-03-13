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

LL A,B,C;
LL ans1;
LL ans2;
bool check(LL x)
{
//    cout << "CHECK " << x << endl;
    LL add = min(A, B);
    LL yu = B % add;
    LL tian = B / add;
    if(x * tian >= ans1) return true;
    LL sx = ans1 - x * tian;
    sx = min(sx, x);
    if(x * tian * add + sx * yu >= C) return true;
    return false;
}
int main()
{
    cin >> A >> B >> C;
    LL tmp = min(A,B);
    ans1 = (C + tmp - 1) / tmp;
    LL L = 1;
    LL R = ans1;
    while(L < R)
    {
        LL mid = (L + R) / 2;
        if(check(mid))
        {
            R = mid;
        }
        else L = mid + 1;
    }
    ans2 = L;
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}

