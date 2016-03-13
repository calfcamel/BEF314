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
PII a[5005];
PII b[5005];
int get(int i, int j)
{
    if(a[i].AA > b[j].AA) return a[i].BB;
    else return b[j].BB;
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int x,y,z;
    FOR(i,n) a[i] = MP(-1,0);
    FOR(i,m) b[i] = MP(-1,0);
    FOR(i,k)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(x == 1) a[y - 1] = MP(i,z);
        if(x == 2) b[y - 1] = MP(i,z);
    }
    FOR(i,n)
    {
        bool boo = true;
        FOR(j,m)
        {
            if(boo) boo = false; else printf(" ");
            printf("%d",get(i,j));
        }
        puts("");
    }
}
