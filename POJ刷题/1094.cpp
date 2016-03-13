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
const int MAXN = 26;
int a[MAXN][MAXN];
int n,m;
//int save[MAXN];
void adde(int x, int y)
{
    a[x][y] = 1;
//    save[x] = 1;
//    save[y] = 1;
}
char str[4];
char tp[MAXN + 1];
int vis[MAXN];
int tpsort()
{
    int flag = 1;
    char ch;
    tp[n] = 0;
    clr(vis,0);
//    int _num = 0;
//    FOR(i,n) if(!save[i]) _num++;
    FOR(l,n)
    {
        int tot = 0;
        FOR(i,n) if(!vis[i])
        {
            int cnt = 0;
            FOR(j,n) if(!vis[j] && a[j][i]) cnt++;
            if(!cnt)
            {
                tot++;
                ch = 'A' + i;
//                printf("FIND %c \n", ch);
            }
        }
//        dbg(tot);
        if(tot == 0) return 0;
        if(tot > 1) flag = -1;
        tp[l] = ch;
//        printf("%c\n",ch);
        vis[ch - 'A'] = 1;
    }
    return flag;
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
        if(n == 0 && m == 0) return 0;
        clr(a,0);
//        clr(save,0);
        int flag = 0;
        FOR(i,m)
        {
            scanf("%s",str);
            if(flag) continue;
            adde(str[0] - 'A', str[2] - 'A');
            int st = tpsort();
//            dbg(st);
            if(st != -1) flag = 1;
            if(st == 0) printf("Inconsistency found after %d relations.\n",i + 1);
            if(st == 1) printf("Sorted sequence determined after %d relations: ",i + 1);
            if(st == 1) printf("%s",tp);
            if(st == 1) puts(".");
        }
        if(!flag) printf("Sorted sequence cannot be determined.\n");
    }
}
