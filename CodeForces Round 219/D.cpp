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

int n,m,q;
char str[50][50];
int a[40][40];
int s1[40][40];
void init_gets1()
{
    clr(s1,0);
    FOR(i,n) FOR(j,m)
    {
        s1[i][j] += a[i][j];
        if(i && j) s1[i][j] -= s1[i - 1][j - 1];
        if(i) s1[i][j] += s1[i - 1][j];
        if(j) s1[i][j] += s1[i][j - 1];
    }
}
int is_rectangular(int a, int b, int c, int d)
{
    if(a < 0) return 0;
    if(b < 0) return 0;
    int ret = s1[c][d];
    if(a && b) ret += s1[a - 1][b - 1];
    if(a) ret -= s1[a - 1][d];
    if(b) ret -= s1[c][b - 1];
    if(ret == 0) return 1;
    return 0;
}
int sum[40][40][41][41];
int getsum(int a, int b, int c, int d, int l, int w)
{
    int ret = sum[c][d][l][w];
    if(a && b) ret += sum[a - 1][b - 1][l][w];
    if(a) ret -= sum[a - 1][d][l][w];
    if(b) ret -= sum[c][b - 1][l][w];
    return ret;
}
int sumend[40][40][41][41];
void init_getsumend()
{
    clr(sumend,0);
    FOR(i,n) FOR(j,m) FOR(a,i + 1) FOR(b, j + 1) sumend[i][j][i - a + 1][j - b + 1] += is_rectangular(a,b,i,j);
}
void init_getsum()
{
    clr(sum,0);
    FOR(i,n) FOR(j,m) FORR(l, i + 1) FORR(w, j + 1)
    {
        if(i) sum[i][j][l][w] += sum[i - 1][j][l][w];
        FOR(k,j + 1) sum[i][j][l][w] += sumend[i][k][l][w];
    }
}
int query(int a, int b, int c, int d)
{
    int maxL = c - a + 1;
    int maxW = d - b + 1;
    int ret = 0;
    for(int l = 1; l <= maxL; l++) for(int w = 1; w <= maxW; w++) ret += getsum(a + l - 1, b + w - 1, c, d, l, w);
    return ret;
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    FOR(i,n) scanf("%s",&str[i]);
    clr(a,0);
    FOR(i,n) FOR(j,m) if(str[i][j] == '1') a[i][j] = 1;
    init_gets1();
    init_getsumend();
    init_getsum();
//    dbg(sum[1][0][1][1] - sum[1][3][1][1]);
//    dbg(sum[1][0][1][2] - sum[1][3][1][2]);
//    dbg(sum[1][0][2][1] - sum[1][3][2][1]);
//    dbg(sum[1][0][1][3] - sum[1][3][1][3]);
//    dbg(sum[1][0][2][2] - sum[1][3][2][2]);
    int a,b,c,d;
    FOR(i,q)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%d\n",query(a - 1,b - 1,c - 1,d - 1));
    }
}
