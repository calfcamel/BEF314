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
double dis(int x,int y)
{
    double ret = x * x + y * y;
    return sqrt(ret);
}
int xj(int x,int y,int x2,int y2)
{
    return x * y2 - y * x2;
}
int sign(int x)
{
    if(x > 0) return 1;
    if(x == 0) return 0;
    return -1;
}
int main()
{
    int xa,xb,xc,ya,yb,yc;
    int d,v;
    int td,tm,fd,fm;
    int w;
    scanf("%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xc,&yc);
    scanf("%d%d",&d,&v);
    d *= 60;
    scanf("%d:%d %d:%d",&td,&tm,&fd,&fm);
    scanf("%d",&w);
    double t1,t2,t3;
    t1 = d;
    t1 += 3600.0 * (dis(xb - xc, yb - yc) + dis(xc - xa, yc- ya)) / ((double)v);
    t2 = (td + fd) * 3600 + (tm + fm) * 60;
    t3 = 3600.0 * dis(xb - xa, yb- ya) / ((double)w);
    if(xj(xb - xa, yb - ya,xc - xa, yc- ya) == 0 && dis(xb - xc, yb - yc) <= dis(xb - xa, yb - ya) && dis(xa - xc, ya - yc) <= dis(xb - xa, yb - ya))
    {
        t3 += d;
    }
//    cout << t1 << endl;
//    cout << t2 << endl;
//    cout << t3 << endl;
    if(t1 < t2 && t1 < t3)
    {
        puts("Alex");
    }
    else if(t2 < t3)
    {
        puts("Dmitry");
    }
    else puts("Petr");
    return 0;
}

