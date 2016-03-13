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
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;


const int MAXN = 10000 + 5;


int main()
{
    int n;
    LL x,y;
    scanf("%d%I64d",&n,&x);
    LL l,r;
    l = x;
    r = x;
    LL p,q;
    LL ans = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%I64d%I64d",&x,&y);
        p = max(l,x);
        q = min(r,y);
        if(p <= q)
        {
            ans += 0;// cost = 0;
            l = p; r = q;
        }
        else
        {
            if(min(abs(l - x), abs(l - y)) < min(abs(r - x), abs(r - y)) )
            {
                ans += min(abs(l - x), abs(l - y));
                p = l;
                if(abs(l - x) < abs(l - y)) q = x; else q = y;
                l = min(p,q);
                r = max(p,q);
            }
            else
            {
                ans += min(abs(r - x), abs(r - y));
                p = r;
                if(abs(r - x) < abs(r - y)) q = x; else q = y;
                l = min(p,q);
                r = max(p,q);
            }
        }
        //printf("put down %I64d %I64d\n",l,r);
    }
    cout << ans << endl;
    return 0;
}
