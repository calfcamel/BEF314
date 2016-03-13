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
#include <iomanip>
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
typedef pair<int, int> PII;
#define FOR(i,x) for(int i = 0, _END_ = (int)(x); i < _END_ ; i++)
#define REP(i,x,y) for(int i = x,  _END_ = (int)(y); i <= _END_ ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
int a[500005];
int n;
bool chk(int x)
{
    int i = x;
    int j = n;
    while(1)
    {
        if(i == 0) return true;
        if(a[i] * 2 > a[j]) return false;
        i--;
        j--;
    }
}
int main()
{
    scanf("%d",&n);
    FORR(i,n) scanf("%d",&a[i]);
    sort(a + 1, a + n + 1);
    int L = 0; int R = n / 2;
    while(L < R)
    {
        int mid = (L + R + 1) / 2;
        if(chk(mid)) L = mid;
        else R = mid - 1;
    }
    cout << n - L << endl;
}
