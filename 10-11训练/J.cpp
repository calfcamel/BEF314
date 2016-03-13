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


const int MAXN = 100000 + 5;

struct node
{
    int x1,y1,x2,y2;
    int l,r;
}T[MAXN];

int tot;
int newnode(int x1,int y1,int x2,int y2)
{
    if(x1 > x2) swap(x1,x2);
    if(y1 > y2) swap(y1,y2);
    T[tot].x1 = x1;
    T[tot].x2 = x2;
    T[tot].y1 = y1;
    T[tot].y2 = y2;
    T[tot].L = -1;
    T[tot].R = -1;
    tot++;
    return tot - 1;
}
void addnode(int p, int x1,int y1,int x2,int y2)
{
    bool heng = y1 == y2;
    if(heng && x1 > x2) swap(x1,x2);
    if(!heng && y1 < y2) swap(y1,y2);
    if(!(~T[p].L) && !(~T[p].R))
    {
        T[p].L = newnode(x1,y1,T[p].x2,T[p].y2);
        T[p].R = newnode(T[p].x1,T[p].y1,x2,y2);
    }
    if()
}
int main()
{
    int x1,y1,x2,y2;
    while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2) != EOF)
    {
        tot = 0;
        newnode(x1,y1,x2,y2);
        int N,Q;
        scanf("%d%d",&N,&Q);
        FOR(i,N)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            addnode(p, x1,y1,x2,y2);
        }
    }
}
