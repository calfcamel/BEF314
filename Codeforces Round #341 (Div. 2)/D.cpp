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
const int MAXN = 500001;
long double x,y,z;
long double get(int i)
{
//    dbg(i);9
    if(i == 1) return z * log(y) + log(log(x));
    if(i == 2) return y * log(z) + log(log(x));
    if(i == 5) return z * log(x) + log(log(y));
    if(i == 6) return x * log(z) + log(log(y));
    if(i == 9) return y * log(x) + log(log(z));
    if(i == 10) return x * log(y) + log(log(z));
    if(i == 3) return log(y * z * log(x));
    if(i == 7) return log(x * z * log(y));
    if(i == 11) return log(x * y * log(z));
    if(i == 4) return get(3);
    if(i == 8) return get(7);
    if(i == 12) return get(11);
}
long double putans(int i)
{
    if(i == 1) puts("x^y^z");
    if(i == 2) puts("x^z^y");
    if(i == 3) puts("(x^y)^z");
//    if(i == 4) puts("x^y^z");
    if(i == 5) puts("y^x^z");
    if(i == 6) puts("y^z^x");
    if(i == 7) puts("(y^x)^z");
//    if(i == 8) puts("x^y^z");
    if(i == 9) puts("z^x^y");
    if(i == 10) puts("z^y^x");
    if(i == 11) puts("(z^x)^y");
//    if(i == 12) puts("x^y^z");
}
int main()
{
    cin >> x >> y >> z;
    dbg(get(5));
    dbg(get(6));
    FORR(i,12)
    {
        bool boo = true;
        FORR(j,12) if(get(i) < get(j)) boo = false;
        if(boo)
        {
            putans(i);
            return 0;
        }
    }
}
