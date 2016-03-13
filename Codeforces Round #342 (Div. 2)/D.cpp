
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
typedef pair<LL, LL> PII;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int MAXN = 100005;
char str[MAXN];
int lstr;
int a[MAXN];
int ans[MAXN];
void tryall()
{
    clr(ans);
    FOR(i,lstr) a[i] = str[i] - '0';
    int l = 0;
    int r = lstr - 1;
    int tl, tr;
    while(l <= r)
    {
        if(l == r)
        {
            ans[l] = a[l] / 2;
            if(a[l] & 1) return ;
        }
        else
        {
            tr = 0;
            tl = a[r];
        }
        r--;
        l++;
    }
}
int main()
{
    scanf("%s",str);
    lstr = strlen(str);
    tryall();
    tryto(lstr - 1);
    puts("0");
    return 0;
}
