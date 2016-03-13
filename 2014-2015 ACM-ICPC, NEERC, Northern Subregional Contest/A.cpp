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

const int cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main()
{
    freopen("alarm.in","r",stdin);
    freopen("alarm.out","w",stdout);
    int n;
    int num;
    cin >> n;
    for(int i = 0; i <= 2; i++)
        for(int j = 0; j <= (i == 2 ? 4:9); j++)
            FOR(k,7) FOR(p,10)
    {
        if(cnt[i] + cnt[j] + cnt[k] + cnt[p] == n)
        {
            cout << i << j << ":" << k << p << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}
