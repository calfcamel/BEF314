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
typedef pair<LL, LL> PII;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
int a[4][4];
char s[10];
const int n = 4;
void gao(int x,int y)
{
    FOR(i,n) a[x][i] ^= 1;
    FOR(i,n) a[i][y] ^= 1;
//    a[x][y] ^= 1;
}
vector<PII> v;
int main()
{
    v.clear();
    clr(a,0);
    FOR(i,n)
    {
        scanf("%s",&s);
        FOR(j,n) if(s[j] == '+') a[i][j] = 1;
    }
    FOR(i,n) FOR(j,n) if(a[i][j]) v.PB(MP(i,j));
    FOR(i,v.SZ) gao(v[i].AA, v[i].BB);
    int ans = 0;
    FOR(i,n) FOR(j,n) if(a[i][j]) ans++;
    printf("%d\n",ans);
    FOR(i,n) FOR(j,n) if(a[i][j]) printf("%d %d\n",i + 1,j + 1);
}
