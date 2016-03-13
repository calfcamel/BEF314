
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <unordered_map>
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
#define all(x) x.begin(), x.end()
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 100000 + 10;
vector<pair<int, pii> > tmph;
vector<pair<int, pii> > tmps;
vector<pair<int, pii> > vh;
vector<pair<int, pii> > vs;
void addh(int x,int y1, int y2)
{
    if(y1 > y2) swap(y1,y2);
    tmph.PB(MP(x,MP(y1,y2)));
}
void adds(int y,int x1, int x2)
{
    if(x1 > x2) swap(x1,x2);
    tmph.PB(MP(y,MP(x1,x2)));
}
LL ans = 0;
void quchong()
{
    int n = tmph.SZ;
    int tot = 0;
    FOR(i,n)
    {
        if(i == 0) vh.PB(tmph[i]);
        else
        {
            if(vh[tot].AA == tmph[i].AA && vh[tot].BB.BB <= tmph[i].BB.AA)
            {
                cmax(vh[tot].BB.BB, tmph[i].BB.BB);
            }
            else
            {
                vh.PB(tmph[i]);
                tot++;
            }
        }
    }
    n = tmps.SZ;
    tot = 0;
    FOR(i,n)
    {
        if(i == 0) vs.PB(tmps[i]);
        else
        {
            if(vs[tot].AA == tmps[i].AA && vs[tot].BB.BB <= tmps[i].BB.AA)
            {
                cmax(vs[tot].BB.BB, tmps[i].BB.BB);
            }
            else
            {
                vs.PB(tmps[i]);
                tot++;
            }
        }
    }
}

set<pii> SET;
vector<pair<int, pii> >

///
///
/// ÏÈÆúÁÆ£¬ÏÈÆúÁÆ
///
///
int main()
{
    /// INIT
    tmph.clear();
    tmps.clear();
    vh.clear();
    vs.clear();
    SET.clear();
    ans = 0;

    int n; scanf("%d",&n);
    int x1,y1,x2,y2;
    FOR(i,n)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1 == x2) adds(x1,y1,y2);
        else addh(y1,x1,x2);
    }
    sort(all(tmph));
    sort(all(tmps));

    quchong();
}
