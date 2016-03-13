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

const int MAXN = 65;

int n,m;
/// UP RIGHT DOWN LEFT
const int dx[4] = {-1,0,+1,0};
const int dy[4] = {0,+1,0,-1};
/// # -1
/// . 0
/// P 1
/// x -2
int a[MAXN][MAXN];
int b[130][MAXN][MAXN];
int now[130][MAXN][MAXN];
int stx,sty,edx,edy;
char s[MAXN];
void update(int k,int x,int y)
{
//    if(k < 20) cout << "UPD " << k << " "<< x << " " << y << endl;
    FOR(d,4)
    {
        int i = x;
        int j = y;
        while(b[k][i][j] != -1)
        {
            b[k][i][j] = -2;
            i += dx[d];
            j += dy[d];
        }
    }
}
bool check(int k)
{
    FOR(d,4)
    {
        if(now[k][edx + dx[d]][edy + dy[d]]) return true;
    }
    return false;
}
bool hefa(int x,int y)
{
    if(0 < x && x <= n && 0 < y && y <= m) return true;
    return false;
}
bool checkcan(int k,int i,int j)
{
    if(a[i][j] == -1) return false;
    if(now[k][i][j]) return true;
    FOR(d,4)
    {
        if(now[k][i + dx[d]][j + dy[d]]) return true;
    }
    return false;
}
int main()
{
    scanf("%d%d\n",&n,&m);
//    dbg(n);
//    dbg(m);
    scanf("(%d %d) (%d %d)",&stx,&sty,&edx,&edy);
    if(stx == edx && sty == edy)
    {
        cout << 0 << endl;
        return 0;
    }
//    dbg(stx);
//    dbg(sty);
//    dbg(edx);
//    dbg(edy);
    clr(a,-1);
    FORR(i,n)
    {
        scanf("%s",s);
//        puts(s);
        FORR(j,m)
        {
            if(s[j - 1] == '.') a[i][j] = 0;
        }
    }
//    FORR(i,n)
//    {
//        FORR(j,m) cout << (a[i][j] == -1 ? 1:0);
//        cout << endl;
//    }
    FOR(k,120) FOR(i,MAXN) FOR(j,MAXN) b[k][i][j] = a[i][j];
    int numx;
    scanf("%d",&numx);
    FOR(i,numx)
    {
        int tmp;
        int x,y;
        scanf("%d",&tmp);
        int tmp2 = 2 * tmp - 2;
        FOR(j,tmp)
        {
            scanf(" (%d %d)",&x,&y);
            FOR(k,120) if(tmp == 1 || k % tmp2 == j || k % tmp2 == tmp2 - j) update(k,x,y);
        }
    }
    FOR(i,MAXN) FOR(j,MAXN) b[120][i][j] = b[0][i][j];
    if(b[0][stx][sty] != 0)
    {
        puts("IMPOSSIBLE");
        return 0;
    }
    if(((stx - edx) * (stx - edx) + (sty - edy) * (sty - edy)) <= 1)
    {
        cout << 1 << endl;
        return 0;
    }
    clr(now,0);
    now[0][stx][sty] = 1;
    int ans = 0;
    bool flag = true;
//    FOR(k,20)
//    {
//        cout << endl << k << endl;
//        FORR(i,n)
//        {
//            FORR(j,n) cout << -b[k][i][j];
//            cout << endl;
//        }
//    }
    while(flag)
    {
        FORR(k,120)
        {
            ans ++;
            FORR(i,n) FORR(j,m)
                if(checkcan(k - 1,i,j) && b[k][i][j] == 0)
                {
                    now[k][i][j] = 1;
//                    cout << "WALK " << k << " " << i << " " << j << endl;
                }
            if(check(k))
            {
                cout << ans + 1<< endl;
                return 0;
            }
        }
        flag = false;
        FORR(i,n) FORR(j,m) if(now[0][i][j] == 0 && now[120][i][j] == 1) flag = true;
        FOR(i,MAXN) FOR(j,MAXN) now[0][i][j] = now[120][i][j];
    }
    puts("IMPOSSIBLE");
    return 0;
}
