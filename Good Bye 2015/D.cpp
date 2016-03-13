
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

const int MAXN = 5000 + 10;
int n;
char s[MAXN];
LL bef[MAXN];
LL f[MAXN];
int q[MAXN];
void init(int l)
{
    clr(q,0);
    FORR(i,n)
    {
        if(i + l > n) break;
        if(s[i] == s[i + l]) q[i] = 0;
        else if(s[i] > s[i + l]) q[i] = 2; /// FALSE
        else q[i] = 1; /// TRUE
    }
//        cout << "Q  :  "; for(int i = 0; i <= n; i++) cout << q[i] << " "; cout << endl;
    FOR(i,n) q[i] = q[i - 1] + q[i];
}
bool check(int i, int l)
{
    if(s[i - l] == '0') return false;
    int tmp = upper_bound(q + i - l, q + i, q[i - l - 1]) - q;
    if(tmp == i) return false;
//    if(q[tmp] == 1) cout << "\t\tADD " << i << endl;
    return q[tmp] - q[i - l - 1] == 1;
}
int main()
{
    scanf("%d",&n);
    s[0] = '0' - 2;
    scanf("%s",s + 1);
//    puts(s);
    clr(bef,0);
    bef[0] = 0;
    bef[1] = 1;
    LL sum = 0;
    for(int i = 2; i <= n; i++) if(bef[i - 1]) if(s[i] > s[i - 1]) bef[i] = bef[i - 1];
//    cout << "BEF: "; for(int i = 0; i <= n; i++) cout << bef[i] << " "; cout << endl;
    for(int l = 2; l <= n; l++)
    {
        clr(f,0);
        init(l);
        for(int i = 1; i <= n - l + 1; i++) if(s[i] != '0')
        {
            if(i == 1) f[i] = 1;
            else f[i] = bef[i - 1];
            if(i > l) if(check(i,l)) f[i] = (f[i - l] + f[i]) % MOD;
        }
//        dbg(l);
//        cout << "f[" << l << "]: "; for(int i = 0; i <= n; i++) cout << i << " "; cout << endl;
//        cout << "f[" << l << "]: "; for(int i = 0; i <= n; i++) cout << f[i] << " "; cout << endl;
        for(int i = 1; i <= n - l + 1; i++) bef[i + l - 1] += f[i];
        for(int i = 1; i <= n - l + 1; i++) bef[i + l - 1] %= MOD;
//        cout << "BEF:  "; for(int i = 0; i <= n; i++) cout << bef[i] << " "; cout << endl;
    }
//    cout << "BEF: "; for(int i = 0; i <= n; i++) cout << bef[i] << " "; cout << endl;
    sum = bef[n] % MOD;
    cout << sum << endl;
}
