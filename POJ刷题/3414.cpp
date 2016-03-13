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
#define FOR(i,x) for(int i = 0, _END_ = (int)(x); i < _END_ ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int MAXN = 30;
int A,B,C;
int vis[101102];
struct quenode
{
    int a,b;
    int op;
    int bef;
}Q[101102];
int buf[10000];
void putans(int ans)
{
    int x = ans;
    int tot = 0;
    while(~x)
    {
        if(Q[x].op == -1) break;
        buf[tot++] = Q[x].op;
        x = Q[x].bef;
    }
    printf("%d\n",tot);
    reverse(buf, buf + tot);
    FOR(i,tot)
    {
        if(buf[i] == 0) puts("FILL(1)");
        if(buf[i] == 1) puts("FILL(2)");
        if(buf[i] == 2) puts("DROP(1)");
        if(buf[i] == 3) puts("DROP(2)");
        if(buf[i] == 4) puts("POUR(1,2)");
        if(buf[i] == 5) puts("POUR(2,1)");
    }
}
void bfs()
{
    clr(vis,0);
    int l = 0;
    int r = 1;
    Q[0].a = 0;
    Q[0].b = 0;
    Q[0].op = -1;
    Q[0].bef = -1;
    vis[0] = 1;
    int x,y;
    int tx,ty;
    int tmp;
    while(l < r)
    {
        x = Q[l].a;
        y = Q[l].b;
//        cout << x << " " << y << " " << Q[l].op << " " << Q[l].bef << endl;
        if(x == C)
        {
            putans(l);
            return;
        }
        if(y == C)
        {
            putans(l);
            return;
        }
        FOR(i,6)
        {
            if(i == 0) /// FILL(1)
            {
                tx = A;
                ty = y;
                if(!vis[tx * 1000 + ty]) {vis[tx * 1000 + ty] = 1; Q[r].a = tx; Q[r].b = ty; Q[r].op = i; Q[r].bef = l;r++;}
            }
            if(i == 1) /// FILL(2)
            {
                tx = x;
                ty = B;
                if(!vis[tx * 1000 + ty]) {vis[tx * 1000 + ty] = 1; Q[r].a = tx; Q[r].b = ty; Q[r].op = i; Q[r].bef = l;r++;}
            }
            if(i == 2) /// DROP(1)
            {
                tx = 0;
                ty = y;
                if(!vis[tx * 1000 + ty]) {vis[tx * 1000 + ty] = 1; Q[r].a = tx; Q[r].b = ty; Q[r].op = i; Q[r].bef = l;r++;}
            }
            if(i == 3) /// DROP(2)
            {
                tx = x;
                ty = 0;
                if(!vis[tx * 1000 + ty]) {vis[tx * 1000 + ty] = 1; Q[r].a = tx; Q[r].b = ty; Q[r].op = i; Q[r].bef = l;r++;}
            }
            if(i == 4) /// POUR(1,2)
            {
                tx = 0;
                ty = x + y;
                if(ty > B) {tx = ty - B; ty = B;}
                if(!vis[tx * 1000 + ty]) {vis[tx * 1000 + ty] = 1; Q[r].a = tx; Q[r].b = ty; Q[r].op = i; Q[r].bef = l;r++;}
            }
            if(i == 5) /// POUR(2,1)
            {
                tx = x + y;
                ty = 0;
                if(tx > A){ty = tx - A; tx = A;}
                if(!vis[tx * 1000 + ty]) {vis[tx * 1000 + ty] = 1; Q[r].a = tx; Q[r].b = ty; Q[r].op = i; Q[r].bef = l;r++;}
            }
        }
        l++;
    }
    puts("impossible");
}
int main()
{
    scanf("%d%d%d",&A,&B,&C);
    bfs();
}
