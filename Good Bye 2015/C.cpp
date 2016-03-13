
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <unordered_map>
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
#define all(x) x.begin(), x.end()
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 500 + 10;

int sa[MAXN][MAXN];
int sb[MAXN][MAXN];
char s[MAXN][MAXN];
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int sum[MAXN][MAXN];
int query(int x1,int y1,int x2,int y2)
{
//    cout <<"QRY"<< x1 << y1 << x2<< y2<< endl;
    if(x1 == x2 && y1 == y2) return 0;
    int ret = 0;
//    if(x1 < x2) ret += sb[x2 - 1][y2] - sb[x1 - 1][y2] - sb[x2 - 1][y1 - 1] + sb[x1 - 1][y1 - 1];
//    if(y1 < y2) ret += sa[x2][y2 - 1] - sb[x1 - 1][y2 - 1] - sb[x2][y1 - 1] + sb[x1 - 1][y1 - 1];
//    if(x1 < x2) ret += sa[x2 - 1][y2] - sa[x1 - 1][y2] - sa[x2 - 1][y1 - 1] + sa[x1 - 1][y1 - 1];
//    dbg(ret);
//    if(y1 < y2) ret += sb[x2][y2 - 1] - sb[x1 - 1][y2 - 1] - sb[x2][y1 - 1] + sb[x1 - 1][y1 - 1];
//    dbg(ret);
    if(x1 < x2) ret += sb[x2 - 1][y2] - sb[x1 - 1][y2] - sb[x2 - 1][y1 - 1] + sb[x1 - 1][y1 - 1];
//    dbg(ret);
    if(y1 < y2) ret += sa[x2][y2 - 1] - sa[x1 - 1][y2 - 1] - sa[x2][y1 - 1] + sa[x1 - 1][y1 - 1];
//    dbg(ret);
//    dbg(sa[x2][y2 - 1]);
//    dbg(-sa[x1 - 1][y2 - 1]);
//    dbg(-sa[x2][y1 - 1]);
//    dbg(sa[x1 - 1][y1 - 1]);
//    if(y1 < y2) ret += sb[x2 - 1][y2] - sb[x1 - 1][y2] - sb[x2 - 1][y1 - 1] + sb[x1 - 1][y1 - 1];
//    if(x1 < x2) ret += sa[x2][y2 - 1] - sa[x1 - 1][y2 - 1] - sa[x2][y1 - 1] + sa[x1 - 1][y1 - 1];
    return ret;
}
int main()
{
    clr(sa,0);
    clr(sb,0);
    clr(b,0);
    clr(sum,0);
    clr(a,0);
    int n,m;
    scanf("%d%d",&n,&m);
    FOR(i,n) scanf("%s",s[i]);
    FOR(i,n) FOR(j,m) if(s[i][j] == '.')
    {
        if(i + 1 <= n) if(s[i][j + 1] == '.') a[i + 1][j + 1]++; /// heng
        if(j + 1 <= m) if(s[i + 1][j] == '.') b[i + 1][j + 1]++;
    }
    FORR(i,n) FORR(j,m)
    {
        sa[i][j] = sa[i - 1][j] + sa[i][j - 1] - sa[i - 1][j - 1] + a[i][j];
        sb[i][j] = sb[i - 1][j] + sb[i][j - 1] - sb[i - 1][j - 1] + b[i][j];
    }
//    cout << "SA" << endl;
//    FORR(i,n) {FORR(j,m) cout << sa[i][j] << " "; cout << endl;}
//    cout << "SB" << endl;
//    FORR(i,n) {FORR(j,m) cout << sb[i][j] << " "; cout << endl;}
    int q;
    int x1,x2,y1,y2;
    scanf("%d",&q);
    FOR(qq,q)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1 > x2) swap(x1,x2);
        if(y1 > y2) swap(y1,y2);
        printf("%d\n",query(x1,y1,x2,y2));
    }
}
