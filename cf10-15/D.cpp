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
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
const int MAXN = 1000000 + 5;
#define OP begin()
#define ED end()
int n,k;
LL l;
int a[MAXN];
LL b[MAXN];
vector<pii> v;

#define point(x,y) ((x) * n + (y))
//LL cl[MAXN];
LL clj1[MAXN];
const int N = MAXN;
LL inv[N];
void init()
{
    inv[0] = inv[1] = 1;
    for(int i = 2; i < N; i++)
        inv[i] = ((MOD - MOD / i) * inv[MOD % i]) % MOD;
}
LL fclj1;
int fcl;
LL getclj1(LL m)
{
    if(m > fclj1) return 0;
    if(m < 0) return 0;
    return clj1[m];
}
//LL getcl(int m)
//{
//    if(m > fcl) return 0;
//    if(m == 0) return 0;
//    return cl[m];
//}
int main()
{
    scanf("%d%I64d%d",&n,&l,&k);
    init();
    LL tmp;
//    tmp = (l + n - 1) / (LL)n;
//    fcl = tmp;
//    clr(cl,0);
//    cl[0] = 1;
//    for(int i = 1; i <= k; i++)
//    {
//        if(tmp < 0) break;
//        cl[i] = cl[i - 1] * tmp % MOD;
//        cl[i] = cl[i] * inv[i] % MOD;
//        tmp --;
//    }

    tmp = l / n;
    fclj1 = tmp;
    clr(clj1,0);
    clj1[0] = 1;
    for(int i = 1; i <= k; i++)
    {
        if(tmp < 0) break;
        clj1[i] = clj1[i - 1] * tmp % MOD;
        clj1[i] = clj1[i] * inv[i] % MOD;
        tmp --;
    }
//    cout << "clj1:" <<endl;
//    FOR(i,k + 1) cout << clj1[i] << " "; cout << endl;

    FOR(i,n) scanf("%d",&a[i]);
    v.clear();
    FOR(i,n) v.PB(MP(a[i],i));
    sort(v.OP,v.ED);
    FOR(i,n) a[i] = v[i].AA;
    FOR(i,n) b[i] = 1;
//    dbg(k);
//    FOR(i,k)
//    {
//        FOR(j,n) cout << b[point(i,j)] << " ";
//        cout << endl;
//    }
//    cout << "a" << endl;
//    FOR(i,n) cout << a[i] << ' '; cout << endl;
    int j;
    LL sum;
    int p;
    for(int i = 1; i < k; i++)
    {
        j = 0;
        sum = 0;
        FOR(t,n)
        {
            p = point(i,t);
            b[p] = 0;
            //if(t) b[p] += b[p - 1];
            while(j < n && a[j] <= a[t])
            {
                sum += b[point(i - 1,j)];
                sum %= MOD;
                j++;
            }
            b[p] = (b[p] + sum) % MOD;
        }
    }
//    cout << endl;
//    FOR(i,k)
//    {
//        FOR(j,n) cout << b[point(i,j)] << " ";
//        cout << endl;
//    }
    LL ans = 0;
    tmp = l % n;
//    dbg(l);
    FOR(i,k) FOR(j,n)
    {
        if(!i) continue;
//        dbg(i * k + j);
//        dbg(i * k + v[j].BB);
        if(i * k + v[j].BB >= l / n * n)
        {
//            cout << "CCCCCCCCCC" << endl;
            continue;
        }
        if(v[j].BB <= tmp)// && i * k + v[j].BB + l % n >= l)
        {
            ans = (ans + getclj1(i) * b[point(i,j)] % MOD) % MOD;
//            cout << "ex:" << getclj1(i) << " " << b[point(i,j)] << endl;
//            cout << "ex add " << getclj1(i) * b[point(i,j)] << endl;
        }
        ans = (ans + getclj1(i + 1) * b[point(i,j)] % MOD) % MOD;
//        cout << "add " << getclj1(i + 1) * b[point(i,j)] << endl;
    }
    ans = (ans + l) % MOD;
    cout << ans << endl;
    return 0;
}
