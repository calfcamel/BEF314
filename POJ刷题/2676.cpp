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
//int tot;
//int x[90];
//int y[90];
char str[20];
int a[11][11];
vector<PII> v;
int h[10][10];
int l[10][10];
int g[4][4][10];
int tot;
//inline int getg(int x, int y)
//{
//    return x / 3 * 3 + y / 3;
//}
bool flag;
void dfs(int k)
{
    if(k == tot) flag = true;
    if(flag) return;
    int x = v[k].AA;
    int y = v[k].BB;
    FORR(i,9) if(h[x][i] == 0 && l[y][i] == 0 && g[x/3][y/3][i] == 0)
    {
        h[x][i] = 1;
        l[y][i] = 1;
        g[x/3][y/3][i] = 1;
        a[x][y] = i;
        dfs(k + 1);
        if(flag) return;
        h[x][i] = 0;
        l[y][i] = 0;
        g[x/3][y/3][i] = 0;
    }
}
void add(int x,int y)
{
    int val = a[x][y];
    h[x][val] = 1;
    l[y][val] = 1;
    g[x/3][y/3][val] = 1;
}
int main()
{
    int _T;
    scanf("%d",&_T);
    while(_T--)
    {
        v.clear();
        clr(h,0);
        clr(l,0);
        clr(g,0);
        clr(a,0);
        FOR(i,9)
        {
            scanf("%s",&str);
            FOR(j,9)
            {
                if(str[j] - '0')
                {
                    a[i][j] = str[j] - '0';
                    add(i,j);
                }
                else v.PB(MP(i,j));
            }
        }
        random_shuffle(all(v));
//        reverse(all(v));
        tot = v.SZ;
        flag = false;
        dfs(0);
        FOR(i,9)
        {
            FOR(j,9) printf("%d",a[i][j]);
            puts("");
        }
    }
}
