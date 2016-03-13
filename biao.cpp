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
int a[1005];
int n;
int sum[15][1 << 12];
void putans()
{
    FOR(i,n) cout << a[i] << " ";
    FOR(i,n - 1) if(a[i] > a[i + 1]) cout << "D"; else cout << "I";
    cout << endl;
}
void putst(int st)
{
    FOR(i,n - 1)
    {
        if(st & (1 << i)) putchar('D'); else putchar('I');
    }
}
void calc()
{
    int st = 0;
    FOR(i,n - 1) if(a[i] > a[i + 1]) st |= 1 << i;
    sum[n][st]++;
}
int qiu(int nn)
{
    FOR(i,10) a[i] = i;
    n = nn;
    clr(sum[n],0);
    sum[n][0] = 1;
    while(next_permutation(a, a + n)) calc();
//    FOR(st,1 << n - 1)
//    {
//        putst(st); printf(" = %d\n", sum[st]);
//    }
}
int main()
{
    REP(i,2,10) qiu(i);
    int x;
    while(cin >> x)
    {
        REP(i,1,10) cout << sum[i][x] << " " ;cout << endl;
    }
}
