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

const int MAXN = 1000000 + 5;

vector<pii> v;
int a[MAXN];
void bitinit()
{
    clr(a,0);
}
inline int lowbit(int x)
{
    return x & (-x);
}
void bitinsert(int p,int add)
{
    while(p < MAXN)
    {
        a[p] += add;
        p += lowbit(p);
    }
}

LL getcnt(int p)
{
    int sum = 0;
    p--;
    while(p > 0)
    {
        sum += a[p];
        p -= lowbit(p);
    }
    return sum;
}
int main()
{
    int n;
    int x,y;
    bitinit();
    v.clear();
    scanf("%d",&n);
    FOR(i,n)
    {
        scanf("%d%d",&x,&y);
        if(y > x) swap(x,y);
        v.PB(MP(x,y));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    LL ans = 0;
    int maxi = 1;
    int maxj = 1;
    FOR(i,n)
    {
        bitinsert(v[i].BB, 1);
//        cout << v[i].AA << " " << v[i].BB << endl;
        for(int j = 0; j <= i; j++)
        if((LL)v[i].AA * ((LL)i + 1 - getcnt(v[j].BB)) * v[j].BB > ans)
        {
            ans = (LL)v[i].AA * ((LL)i +1 - getcnt(v[j].BB)) * v[j].BB;
//            cout << "\t" << ans << endl;
            maxi = v[i].AA;
            maxj = v[j].BB;
        }
    }
    cout << ans << endl;
    cout << maxi << " " << maxj << endl;
    return 0;
}
