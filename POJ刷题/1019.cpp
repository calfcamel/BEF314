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
typedef pair<int, int> PII;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const LL MAX = 2147483647;
const int MAXN = 31268;
LL li[MAXN + 1];
LL sum[MAXN + 1];
LL sumsum[MAXN + 1];
inline LL getl(LL i)
{
    if(i >= 1000000000L) return 10;
    if(i >= 100000000L) return 9;
    if(i >= 10000000L) return 8;
    if(i >= 1000000L) return 7;
    if(i >= 100000L) return 6;
    if(i >= 10000L) return 5;
    if(i >= 1000L) return 4;
    if(i >= 100L) return 3;
    if(i >= 10L) return 2;
    return 1;
}
void init()
{
    sum[0] = 0;
    sumsum[0] = 0;
    FORR(i,MAXN)
    {
        li[i] = getl(i);
        sum[i] = sum[i - 1] + li[i];
        sumsum[i] = sumsum[i - 1] + sum[i];
    }
}
void gao3(LL n, LL t)
{
    LL l = li[n];
    FOR(i,l - t) n /= 10;
    cout << n % 10 << endl;
}
void gao2(LL n)
{
    FORR(i,n)
    {
        if(sum[i] == n)
        {
            cout << i % 10 << endl;
            return;
        }
        else if(sum[i] > n)
        {
            gao3(i, n - sum[i - 1]);
            return;
        }
    }
}
void gao(LL n)
{
    FORR(i,MAXN)
    {
        if(sumsum[i] == n)
        {
            cout << i % 10 << endl;
            return;
        }
        else if(sumsum[i] > n)
        {
            gao2(n - sumsum[i - 1]);
            return;
        }
    }
}
int main()
{
    init();
    int _T;
    cin >>_T;
    while(_T--)
    {
        LL n;
        cin >> n;
        gao(n);
    }
    return 0;
}
