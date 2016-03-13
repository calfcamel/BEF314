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
LL a[MAXN];
int main()
{
    int n,k;
    int p;
    cin >> n >> k >> p;
    FOR(i,n) a[i] = 1;
    for(int i = n - k; i < n; i++)
    {
//        cout << i << " " << (p * i - 1) / 100 << endl;
        long long tmp = a[(p * i - 1) / 100];
//        dbg(tmp);
        a[i] = tmp + 1;
    }
    LL ans = 0;
    FOR(i,n) ans += a[i];
    printf("%I64d\n",ans);
    FOR(i,n)
    {
        if(i) printf(" ");
        printf("%I64d",a[i]);
    }
    puts("");
}
