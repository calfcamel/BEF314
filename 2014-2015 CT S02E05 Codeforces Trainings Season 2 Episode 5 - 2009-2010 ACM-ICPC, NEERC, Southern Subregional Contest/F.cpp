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
const int C = 3;
int a[MAXN];
//GYM
//#define ONLINE_JUDGE
vector<pii> v;
int pre[MAXN];
int dp[MAXN];
void add(int i,int w)
{
    FOR(j,v.SZ) if(a[v[j].BB] == a[i])
    {
        if(w > -v[j].AA)
        {
            v[j].AA = -w;
            v[j].BB = i;
        }
        sort(v.begin(),v.end());
        return;
    }
    if(v.SZ < 3)
    {
        v.PB(MP(-w,i));
    }
    else
    {
        for(int j = v.SZ - 1; j >= 0; j--)
        {
            if(-v[j].AA < w)
            {
                v[j].AA = -w;
                v[j].BB = i;
                break;
            }
        }
    }
    sort(v.begin(),v.end());
}
pii get(int i)
{
    FOR(j,v.SZ) if(a[v[j].BB] != a[i] + 1 && a[v[j].BB] != a[i] - 1) return v[j];
}
bool boo;
void init()
{
    v.clear();
    a[0] = -3;
    a[1] = -2;
    a[2] = -1;
    add(0,0);
    add(1,0);
    add(2,0);
    clr(dp,0);
    clr(pre,0);
}
void display()
{
    cout << "DISPLAY V" << endl;
    FOR(i,v.SZ)
    {
        cout << v[i].AA << " " << v[i].BB << " " << a[v[i].BB] << endl;
    }
}
void put(int x)
{
//    dbg(x);
    if(x < C) return;
    put(pre[x]);
    if(boo) printf(" ");
    else boo = true;
    printf("%d",a[x]);
}
int main()
{
    #ifdef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    int n; scanf("%d",&n);
    FOR(i,n) scanf("%d",&a[i + C]);
    pii ret;
    init();
    FOR(i,n)
    {
        ret = get(i + C);
        if(dp[i + C] < -ret.AA + 1)
        {
            dp[i + C] = -ret.AA + 1;
            pre[i + C] = ret.BB;
            add(i + C, dp[i + C]);
        }
    }
    int ans = 0;
    int ansi;
//    FOR(i,n) cout << dp[i + C] << " " << pre[i + C] << endl;
    FOR(i,n) if(dp[i + C] > ans)
    {
        ans = dp[i + C];
        ansi = i + C;
    }
    printf("%d\n",n - ans);
    boo = false;
    put(ansi);
    puts("");
    return 0;
}

