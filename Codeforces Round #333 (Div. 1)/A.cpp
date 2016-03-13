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
const int INF = 0x3FFFFFFF; // INF / 2
const int MAXN = 2000 + 5;
int e[405][405];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    bool b = false;
    FORR(i,n) FORR(j,n)
        if(i == j) e[i][j] = 0;
        else e[i][j] = INF;
    FOR(i,m)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x == n && y == 1) b = true;
        if(x == 1 && y == n) b = true;
        e[x][y] = 1;
        e[y][x] = 1;
    }
    if(b)
    {
        FORR(i,n) FORR(j,n)
        {
            if(i == j) e[i][j] = 0;
            else if(e[i][j] == INF) e[i][j] = 1;
            else e[i][j] = INF;
        }
    }
    FORR(k,n) FORR(i,n) FORR(j,n)
        if(e[i][j] > e[i][k] + e[k][j])
            e[i][j] = e[i][k] + e[k][j];
    if(e[1][n] == INF) puts("-1");
    else printf("%d\n",e[1][n]);
}



