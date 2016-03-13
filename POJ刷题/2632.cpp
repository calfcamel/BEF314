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
const int MAXN = 105;
int rd[MAXN];
int rx[MAXN];
int ry[MAXN];
int a[MAXN][MAXN];

char str[10];
int getdis(char ch)
{
    if(ch == 'N') return 0;
    if(ch == 'E') return 1;
    if(ch == 'S') return 2;
    if(ch == 'W') return 3;
}
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int main()
{
    int _T;
    scanf("%d",&_T);
    while(_T--)
    {
        int n,m;
        scanf("%d%d",&m,&n);
        int totr,q;
        clr(a,-1);
        FORR(i,n) FORR(j,m) a[i][j] = 0;
        scanf("%d%d",&totr,&q);
        int x,y,rp;
        FORR(i,totr)
        {
            scanf("%d%d%s",&y,&x,str);
            a[x][y] = i;
            rd[i] = getdis(str[0]);
            rx[i] = x;
            ry[i] = y;
        }
        int st;
        int flag = 0;
        int ansx,ansy;
//        for(int i = 0; i <= n + 1; i++)
//        {
//            for(int j = 0; j <= m + 1; j++)
//                printf("%d ",a[i][j]);
//            puts("");
//        }
        FOR(l,q)
        {
            scanf("%d%s%d",&x,str,&rp);
            if(flag != 0) continue;
            if(str[0] == 'L') rd[x] = (rd[x] + 100 - rp) % 4;
            if(str[0] == 'R') rd[x] = (rd[x] + 100 + rp) % 4;
            if(str[0] == 'F') FOR(i,rp)
            {
                st = a[rx[x] + dx[rd[x]]][ry[x] + dy[rd[x]]];
//                dbg(st);
                if(st == -1)
                {
                    flag = -1;
                    ansx = x;
                    break;
                }
                if(st > 0)
                {
                    flag = 1;
                    ansx = x;
                    ansy = st;
                    break;
                }
                if(st == 0)
                {
                    a[rx[x]][ry[x]] = 0;
                    rx[x] += dx[rd[x]];
                    ry[x] += dy[rd[x]];
                    a[rx[x]][ry[x]] = x;
//                    dbg(rx[x]);
//                    dbg(ry[x]);
                }
            }
        }
        if(flag == -1) printf("Robot %d crashes into the wall\n",ansx);
        if(flag == 1) printf("Robot %d crashes into robot %d\n",ansx,ansy);
        if(flag == 0) printf("OK\n");
    }
}
