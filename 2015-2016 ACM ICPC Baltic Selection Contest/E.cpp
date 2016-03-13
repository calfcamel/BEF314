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
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 100000 + 5;
int e1[MAXN];
int e2[MAXN];
void add(int x, int y)
{
    if(x > y) swap(x, y);
    if(e1[x] == -1) e1[x] = y;
    else e2[x] = y;
}
struct node
{
    LL a[MAXN];
    void bitinit()
    {
        clr(a,0);
    }
    inline LL lowbit(LL x)
    {
        return x & (-x);
    }
    void bitinsert(LL p,LL add)
    {
        while(p < MAXN)
        {
            a[p] += add;
            p += lowbit(p);
        }
    }
    LL getcnt(LL p)
    {
        LL sum = 0;
        while(p > 0)
        {
            sum += a[p];
            p -= lowbit(p);
        }
        return sum;
    }
}bit1;
int main()
{
    int n;
    clr(e1, -1);
    clr(e2, -1);
    bit1.bitinit();
    scanf("%d",&n);
    int x;
    FORR(i,n)
    {
        scanf("%d",&x);
        add(i,x);
    }
    LL ans = 0;
    FORR(i,n)
    {
        if(e1[i] != -1) ans += bit1.getcnt(e1[i] - 1) - bit1.getcnt(i);
        if(e2[i] != -1) ans += bit1.getcnt(e2[i] - 1) - bit1.getcnt(i);
        if(e1[i] != -1) bit1.bitinsert(e1[i], 1);
        if(e2[i] != -1) bit1.bitinsert(e2[i], 1);
    }
    cout << ans << endl;
    return 0;
}

