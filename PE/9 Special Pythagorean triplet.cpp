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
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int MAXN = 1005;

bool chk(int a, int b, int c)
{
    if(a < b && b < c && a * a + b * b == c * c) return true;
    return false;
}
int main()
{
    int sum = 1000;
    for(int a = 1; a <= 1000; a++) for(int b = a + 1; b <= 1000; b++) if(chk(a,b,1000 - a - b))
    {
        dbg(a);
        dbg(b);
        dbg(1000 - a - b);
        cout << a * b * (1000 - a - b ) << endl;
    }
}

