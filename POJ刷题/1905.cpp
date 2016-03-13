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

int main()
{
    double l,a,b;
    while(cin >> l >> a >> b)
    {
        if(l < 0) return 0;
        double ll = l + l * a * b;
        double L = l / 2.0;
        double R = ll * 100000.0;
        FOR(i,100)
        {
            double M = (L + R) / 2.0;
            if(M * 2.0 * asin(l/2.0/M) < ll) R = M;
            else L = M;
        }
        double ans = L - sqrt(L * L - l * l / 4.0);
        if(l == 0 || a == 0 || b == 0) ans = 0;
        printf("%.3f\n",ans);
    }
}
