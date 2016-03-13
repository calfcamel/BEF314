
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
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
int n;
int x,y;
vector<PII> v;
vector<PII>::iterator it;
bool found(int x, int y)
{
    it = lower_bound(v.begin(), v.end(),MP(x, y));
    if(it != v.end()) if((*it).AA == x && (*it).BB == y) return true;
    return false;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        v.clear();
        FOR(i,n)
        {
            scanf("%d%d",&x,&y);
            v.PB(MP(x,y));
        }
        int vx,vy;
        int ans = 0;
        sort(all(v));
        FOR(i,n) for(int j = i + 1; j < n; j++)
        {
            vy = -(v[i].AA - v[j].AA);
            vx = v[i].BB - v[j].BB;
            if(found(v[i].AA+vx,v[i].BB+vy)&&found(v[j].AA+vx,v[j].BB+vy))ans++;
            vx = -vx;
            vy = -vy;
            if(found(v[i].AA+vx,v[i].BB+vy)&&found(v[j].AA+vx,v[j].BB+vy))ans++;

        }
//        dbg(ans);
        printf("%d\n",ans / 4);
    }
}
