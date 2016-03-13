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
#define ccmin(x,y) if(x == -1) x = y; else x = min(x,y)
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

const int MAXN = 1000 + 2;
int a[505][505];
char s[100005];
int x,y;
    int n,m;
void zou(char ch)
{
    if(ch == 'U') if(x - 1 > 0) x--;
    if(ch == 'D') if(x + 1 <= n) x++;
    if(ch == 'L') if(y - 1 > 0) y--;
    if(ch == 'R') if(y + 1 <= m) y++;
}
int main()
{
    scanf("%d%d",&n,&m);
    FORR(i,n) FORR(j,m) a[i][j] = 1;
    scanf("%d%d",&x,&y);
    a[x][y] = 0;
    printf("1");
    scanf("%s",s);
    int l = strlen(s);
    FOR(i,l)
    {
        zou(s[i]);
        if(l - 1 != i) printf(" %d", a[x][y]);
        else
        {
            int sum = 0;
            FORR(k,n) FORR(j,m) sum += a[k][j];
            printf(" %d",sum);
        }
        a[x][y] = 0;
    }
    puts("");
}
