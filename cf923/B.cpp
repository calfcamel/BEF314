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
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;


const int MAXN = 10000 + 5;
vector<pair<LL, LL> > v;
LL sum[100005];
LL a[100005];
int main()
{
    LL x,y;
    LL n,d;
    v.clear();
    scanf("%I64d%I64d",&n,&d);
    for(int i = 0; i < n; i++)
    {
        scanf("%I64d%I64d",&x,&y);
        v.push_back(MP(x,y));
    }
    sort(v.begin(), v.end());
    sum[0] = v[0].second;
    a[0] = v[0].first;
    for(int i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + v[i].second;
        a[i] = v[i].first;
    }
    int j = 0;
    LL ans = 0;
    for(int i = 0; i < n; i++)
    {
        while(j + 1< n && a[j + 1] - a[i] < d) j++;
        if(i) ans = max(ans, sum[j] - sum[i - 1]);
        else ans = max(ans, sum[j]);
    }
    cout << ans << endl;
    return 0;
}
