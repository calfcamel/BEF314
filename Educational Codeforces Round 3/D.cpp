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
const int MAXN = 200000 + 5;
int n,k,m;
LL s;
LL a[MAXN];
LL b[MAXN];
int da[MAXN];
int db[MAXN];
vector<pair<LL,int> > va;
vector<pair<LL,int> > vb;
bool check(int x)
{
    LL pa = a[x];
    LL pb = b[x];
    int i = 0;
    int j = 0;
    int maxi = va.SZ;
    int maxj = vb.SZ;
    LL now = 0;
    while(i + j < k)
    {
        if(now > s) return false;
        if(i == maxi)
        {
            now += vb[j].AA * pb;
            j++;
        }
        else if(j == maxj)
        {
            now += va[i].AA * pa;
            i++;
        }
        else
        {
            if(va[i].AA * pa < vb[j].AA * pb)
            {
                now += va[i].AA * pa;
                i++;
            }
            else
            {
                now += vb[j].AA * pb;
                j++;
            }
        }
    }
    return now <= s;
}
void printans(int x)
{
    LL pa = a[x];
    LL pb = b[x];
    int i = 0;
    int j = 0;
    int maxi = va.SZ;
    int maxj = vb.SZ;
    LL now = 0;
    while(i + j < k)
    {
        if(i == maxi)
        {
            printf("%d %d\n",vb[j].BB, db[x]);
            j++;
        }
        else if(j == maxj)
        {
            printf("%d %d\n",va[i].BB, da[x]);
            i++;
        }
        else
        {
            if(va[i].AA * pa < vb[j].AA * pb)
            {
                printf("%d %d\n",va[i].BB, da[x]);
                i++;
            }
            else
            {
                printf("%d %d\n",vb[j].BB, db[x]);
                j++;
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%I64d",&n,&m,&k,&s);
    FORR(i,n) scanf("%I64d",&a[i]);
    FORR(i,n) da[i] = i;
    FORR(i,n) scanf("%I64d",&b[i]);
    FORR(i,n) db[i] = i;
    for(int i = 2; i <= n; i++) if(a[i] > a[i - 1])
    {
        a[i] = a[i - 1];
        da[i] = da[i - 1];
    }
    for(int i = 2; i <= n; i++) if(b[i] > b[i - 1])
    {
        b[i] = b[i - 1];
        db[i] = db[i - 1];
    }
    LL x,y;
    va.clear();
    vb.clear();
    FORR(i,m)
    {
        scanf("%I64d%I64d",&x,&y);
        if(x == 1) va.PB(MP(y,i));
        else vb.PB(MP(y,i));
    }
    sort(all(va));
    sort(all(vb));
    if(check(n) == false)
    {
        puts("-1");
        return 0;
    }
    int l = 1; int r = n;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%d\n",l);
    printans(l);
}
