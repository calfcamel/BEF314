
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
LL b[100];
vector<LL> v;
int main()
{
    b[0] = 1;
    for(int i = 1; i <= 62; i++) b[i] = b[i - 1] * 2LL;
    v.clear();
    LL tmp;
    for(int i = 2; i <= 62; i++)
    {
        tmp = 0;
        FOR(j,i) tmp |= b[j];
        FOR(j,i - 1) v.PB(tmp - b[j]);
    }
    LL x,y;
    cin >> x >> y;
    int n = v.SZ;
    int ans = 0;
    FOR(i,n) if(v[i] <= y && v[i] >= x) ans++;
    cout << ans << endl;
}
