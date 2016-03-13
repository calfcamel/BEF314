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
#include <assert.h>
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


LL powmod(LL a, LL b)
{
    LL ret = 1;
    while(b)
    {
        assert(b >= 0);
        if(b & 1LL) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1LL;
    }
    return ret;
}
LL f[10];
LL l[10];
string a;
string str[MAXN];
int n;
char stmp[MAXN];
int main()
{
    //ios::sync_with_stdio(false);
    //cin >> a >> n;
    scanf("%s",stmp);
    scanf("%d",&n);
    a = stmp;
    FOR(i,10) f[i] = i;
    FOR(i,10) l[i] = 1;
    int now;
    LL tmp;
    LL leng;
    for(int i = 0; i < n; i++)
    {
        scanf("%s",stmp);
        str[i] = stmp;
    }
        //cin >> str[i];
    for(int i = 0; i < n; i++)
    {
        const char *s = str[n - 1 - i].c_str();
        tmp = 0;
        now = s[0] - '0';
        leng = 0;
        if(strlen(s) == 3)
        {
            f[now] = 0;
            l[now] = 0;
            continue;
        }
        for(int j = strlen(s) - 1; j > 2; j--)
        {
            tmp = (tmp + f[s[j] - '0'] * powmod(10LL,leng) % MOD) % MOD;
            leng = leng + l[s[j] - '0'];
            leng %= MOD - 1;
        }
        f[now] = tmp;
        l[now] = leng;
    }
//    cout << 'F' << endl;
//    FOR(i,10) cout << f[i] << ' '; cout << endl;
//    FOR(i,10) cout << l[i] << ' '; cout << endl;
    tmp = 0;
    leng = 0;
    for(int j = a.SZ - 1; j >= 0; j--)
    {
        tmp = (tmp + f[a[j] - '0'] * powmod(10LL,leng) % MOD) % MOD;
        leng = leng + l[a[j] - '0'];
        leng %= MOD - 1;
    }
    cout << tmp << endl;
    return 0;
}
