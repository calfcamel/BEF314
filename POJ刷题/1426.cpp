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
const int MAXN = 200005;
int n;
int a[100];
int vis[205];
int tmpvis[205];
int p[205];
int ans[100];
void putans(int x)
{
    if(x < 0) return ;
    ans[p[x]] = 1;
    putans(vis[x]);
}
int main()
{
    while(scanf("%d",&n),n)
    {
        if(n == 1)
        {
            printf("%d\n",n);
            continue;
        }
        a[0] = 1;
        for(int i = 1; i < 100; i++)
        {
            a[i] = a[i - 1] * 10 % n;
        }
//        FOR(i,10) dbg(a[i]);
        clr(vis,-1);
//        dbg(vis[0]);
        FOR(i,100)
        {
            clr(tmpvis, -1);
            FOR(j,n) if(vis[j] != -1 && vis[(j + a[i]) % n] == -1)
            {
                tmpvis[(j + a[i]) % n] = j;
                p[(j + a[i]) % n] = i;
//                cout << "UP" << (j + a[i]) % n << endl;
//                if((j + a[i]) % n == 0) break;
            }
            FOR(j,n) if(tmpvis[j] != -1) vis[j] = tmpvis[j];
            if(vis[a[i]] == -1)
            {
                vis[a[i]] = -2;
                p[a[i]] = i;
//                cout << "ADD " << a[i] << endl;
//                if(a[i] == 0) break;
            }
        }
        clr(ans,0);
        putans(0);
        bool boo = false;
        for(int i = 99; i >= 0; i--)
        {
            if(ans[i]) boo = true;
            if(boo) printf("%d",ans[i]);
        }
        puts("");
    }
}

