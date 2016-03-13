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

const int MAXN = 100000 + 5;
char s[200][200];
int a[200][200];
int add[200][200];
const int dx2[4] = {-1,0,0,-1};
const int dy2[4] = {0,0,-1,-1};
char str[505];
//GYM
//#define ONLINE_JUDGE
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
int main()
{
    #ifdef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    int n,m;
    clr(a,0);
    clr(add,0);
    scanf("%d%d",&n,&m);
    FOR(i,n) scanf("%s",&s[i]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            a[i][j] = s[i - 1][j - 1] - '0';
        }
    int x,y;
    x = y = 1;
    int d = 0;
    scanf("%s",str);
    int l = strlen(str);
    FOR(i,l)
    {
        if(str[i] == 'R') d = (d + 1) % 4;
        if(str[i] == 'L') d = (d + 3) % 4;
        if(str[i] == 'M')
        {
            add[x + dx2[d]][y + dy2[d]] ++;
            add[x + dx2[(d + 1) % 4]][y + dy2[(d + 1) % 4]] ++;
            x += dx[d];
            y += dy[d];
        }
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(add[i][j]) ans += a[i][j];
            if(add[i][j] > 1)
                ans += a[i][j] / 2 * (add[i][j] - 1);
        }
    cout << ans << endl;
}
