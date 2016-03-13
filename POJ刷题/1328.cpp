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

double d;
int n,m;
vector<pair<double, double> > v;
inline double calc(double y, double z)
{
    return sqrt(z * z - y * y);
}
void add(double x,double y)
{
    double cha = calc(y,d);
    v.PB(MP(x - cha, -(x + cha)));
}
int main()
{
    int cas = 1;
    while(scanf("%d%d",&n,&m) && (n != 0))
    {
        d = m;
        int x,y;
        bool boo = true;
        v.clear();
        if(m < 0) boo = false;
        FOR(i,n)
        {
            scanf("%d%d",&x,&y);
            if(y < 0) y = -y;
            if(y > m) boo = false;
            if(boo) add(x,y);
        }
        printf("Case %d: ",cas++);
        if(boo)
        {
            int ans = 0;
            sort(all(v));
            int lv = v.SZ;
            FOR(i,lv) v[i].BB = -v[i].BB;
//            FOR(i,lv) cout << i << " " << v[i].AA << " " << v[i].BB << endl;
            FOR(i,lv)
            {
                if(i + 1 < lv && v[i].BB >= v[i + 1].AA) v[i + 1].BB = cmin(v[i + 1].BB, v[i].BB);
                else ans++;
            }
            printf("%d\n",ans);
        }
        else puts("-1");
    }
}
