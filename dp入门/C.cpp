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
#define REP(i,x,y) for(int i = (int)(x); i <= (int)(y); i++)
#define REPP(i,x,y) for(int i = (int)(x); i <= (int)(y); i--)
#define all(x) x.begin(),x.end()
const int MAXN = 30 + 5;

char a[MAXN];
char b[MAXN];
LL f[MAXN][MAXN];
LL g[MAXN][MAXN][MAXN * 2];
int main()
{
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        scanf("%s%s",a + 1,b + 1);
        a[0] = '@';
        b[0] = '@';
        int n = strlen(a) - 1;
        int m = strlen(b) - 1;
//        puts(a);
//        puts(b);
        clr(f,0);
        clr(g,0);
        REP(i,1,n) REP(j,1,m) f[i][j] = max(max(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1] + (a[i] == b[j] ? 1: 0));
        g[0][0][0] = 1;
//        REP(i,1,n) g[i][0][i] = i;
//        REP(i,1,m) g[0][i][i] = i;
        REP(i,0,n) REP(j,0,m) REP(k,0, i + j) if(g[i][j][k])
        {
            if(a[i + 1] == b[j + 1])
            {
                g[i + 1][j + 1][k + 1] += g[i][j][k];
//                g[i + 1][j + 1][k + 2] += g[i][j][k];
//                cout << "UP 1 " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
            }
            else
            {
                g[i + 1][j][k + 1] += g[i][j][k];
                g[i][j + 1][k + 1] += g[i][j][k];
//                g[i + 1][j + 1][k + 2] += g[i][j][k] * 2;
//                cout << "UP 2 " << i << " " << j + 1 << " " << k + 1 << endl;
//                cout << "UP 2 " << i + 1 << " " << j << " " << k + 1 << endl;
            }
        }
//        REP(i,0,n) REP(j,0,m) REP(k,0,i + j) if(g[i][j][k])
//            cout << i << " " << j << ' ' << k << " = " << g[i][j][k] << endl;
        LL ans = n + m - f[n][m];
        dbg(n);
        dbg(m);
        dbg(f[n][m]);
        printf("Case %d: %lld %lld\n",CAS,ans,g[n][m][ans]);
    }
    return 0;
}

