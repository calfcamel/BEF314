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
typedef unsigned long long ULL;
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

LL ans[5001];
vector<LL> v[5001];
int getcnt(int x)
{
    int ret = 0;
    while(x)
    {
        ret += x % 10;
        x = x/ 10;
    }
    return ret;
}
int main()
{
    freopen("digits.in","r",stdin);
    freopen("digits.out","w",stdout);
    int n;
    clr(ans,0);
    for(int i = 1; i <= 10000000; i++)
    {
        v[getcnt(i)].PB((LL)i);
    }
    for(int i = 1; i <= 5000; i++)
    {
        LL sum = 0;
        int maxj = v[i].SZ;
        maxj = min(maxj, 5000);
        for(int j = 0; j < maxj; j++)
            {
                sum += v[i][j];
                if(ans[j + 1] == 0) ans[j + 1] = sum;
                else ans[j + 1] = min(ans[j + 1], sum);
            }
    }
    cin >> n;
    cout << ans[n] << endl;
    return 0;
}
