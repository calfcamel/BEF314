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

const int MAXN = 1000000000;
int main()
{
    // find x;
    int xL,xR,x,y,yL,yR;
    xL = 0;
    xR = MAXN;
    yL = 0;
    yR = MAXN;

    y = 0;
    int b1,b2;
    while(xL < xR)
    {
        printf("%d %d\n",xL,y);
        fflush(stdout);
        scanf("%d",&b1);
        printf("%d %d\n",xR,y);
        fflush(stdout);
        scanf("%d",&b2);
        if(b2) xL = (xL + xR) / 2 + (xL + xR) % 2;
        else xR = (xL + xR) / 2;
    }
    x = 0;
    while(yL < yR)
    {
        printf("%d %d\n",x,yL);
        fflush(stdout);
        scanf("%d",&b1);
        printf("%d %d\n",x,yR);
        fflush(stdout);
        scanf("%d",&b2);
        if(b2) yL = (yL + yR) / 2 + (yL + yR) % 2;
        else yR = (yL + yR) / 2;
    }
    printf("A %d %d\n",xL,yL);
    fflush(stdout);
    return 0;
}
