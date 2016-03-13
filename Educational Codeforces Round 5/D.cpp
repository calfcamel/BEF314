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
const int MAXN = 500000 + 1;
struct node
{
    int i;
    int next;
}p[MAXN];
int v[1000001];
int a[MAXN];
int n;
int bef[MAXN];
int nxt[MAXN];
int ansl;
int ansr;
int tot;
int main()
{
    tot = 0;
    ansl = 1;
    ansr = 1;
    scanf("%d",&n);
    FORR(i,n) scanf("%d",&a[i]);
    clr(v,-1);
    FORR(i,n)
    {
        if(v[a[i]] == -1)
        {
            bef[i] = -1;
        }
    }
}
