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
const int MAXN = 3000000;
#define OP begin()
#define ED end()
const int N = MAXN;
LL inv[N];
LL b[MAXN];
void init()
{
    inv[0] = inv[1] = 1;
    for(int i = 2; i < N; i++)
        inv[i] = ((MOD - MOD / i) * inv[MOD % i]) % MOD;
}
#define point(x,y) ((x) * n + (y))
LL cl[MAXN];
int a[MAXN];
vector<pii> v;
int main()
{
    int n,k;
    LL l;
    scanf("%d%I64d%d",&n,&l,&k);
    LL cn = l / n;
    cl[0] = 1;
    LL tmp;

    FOR(i,n) scanf("%d",&a[i]);
    v.clear();
    FOR(i,n) v.PB(MP(a[i],i + 1));
    sort(v.OP,v.ED);
    FOR(i,n) a[i] = v[i].AA;
    FOR(i,n) b[i] = 1;
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
//    dbg(cn);
    tmp = l % n;
//    dbg(tmp);
    for(int i = 0; i < k; i++)
    {
        //if(i > cn + 1) break;
        for(int j = 0; j < n; j++)
        {
            p = point(i,j);
            if(v[j].BB <= tmp)
            {
                ans = (ans + max(cn - i + 1, 0LL) % MOD * b[p] % MOD) % MOD;
//                cout << b[p] * (LL)max(cn - i + 1, 0LL) % MOD << " ";
            }
            else
            {
                ans = (ans + max(cn - i, 0LL) % MOD * b[p] % MOD) % MOD;
//                cout << b[p] * (LL)max(cn - i, 0LL) % MOD << " ";
            }

        }
//        cout << endl;
    }
    cout << ans << endl;
}
