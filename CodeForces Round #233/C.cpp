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
LL sqr(LL x) {return x * x;}
char str[200005];
int tot;
inline void add(char ch)
{
    str[tot++] = ch;
}
void jieshu()
{
    LL now;
    LL ans = 0;
    now = -1;
    if(str[0] == 'o') now = 1;
    FORR(i, tot)
    {
        if(str[i] == str[i - 1])
        {
            if(str[i] == 'o') now ++;
            else now --;
        }
        else
        {
            if(now > 0) ans += sqr(now);
            else ans -= sqr(now);
            now = 0;
            if(str[i] == 'o') now ++;
            else now --;
        }
    }
    printf("%I64d\n",ans);
    str[tot] = 0;
    puts(str);
    exit(0);
}
int main()
{
    int a,b;
    cin >> a >> b;
    tot = 0;
    if(a == 0)
    {
        FOR(i,b) add('x'); jieshu();
    }
    if(b == 0)
    {
        FOR(i,a) add('o'); jieshu();
    }
    if(a >= b)
    {
        FOR(i,b / 2) add('x');
        FOR(i,a) add('o');
        FOR(i,b - b / 2) add('x');
        jieshu();
    }
    if(b > a)
    {
        int chu = b / (a + 1);
        int yu = b % (a + 1);
        FOR(i, a + 1)
        {
            FOR(j,chu) add('x');
            if(yu) {add('x');yu--;}
            if(i < a) add('o');
        }
        jieshu();
    }
}
