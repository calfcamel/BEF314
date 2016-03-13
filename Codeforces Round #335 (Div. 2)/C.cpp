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
#define ccmin(x,y) if(x == -1) x = y; else x = min(x,y)
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
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 1000 + 2;

const int N = 410000;
int a[N];
int d[N];
int BinSearch(int key, int* d, int low, int high)
{
    while(low<=high)
    {
        int mid = (low+high)>>1;
        if(key>d[mid] && key<=d[mid+1])
            return mid;
        else if(key>d[mid])
            low = mid+1;
        else
            high = mid-1;
    }
    return 0;
}

int LIS(int* a, int n, int* d)
{
    int ret = 0;
    FORR(i,n)
    {
        d[a[i]] = max(1,d[a[i] - 1] + 1);
        ret = max(ret, d[a[i]]);
    }
    return ret;
}

int main()
{
    int t;
    int p;
    memset(d,0,sizeof(d));
//    scanf("%d",&t);
//    while(t--)
//    {
        scanf("%d",&p);
        for(int i = 1; i <= p; i++)
            scanf("%d",&a[i]);
        printf("%d\n",p - LIS(a,p,d));
//    }
    return 0;
}
