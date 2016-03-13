
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
char ai[100];
    int lstr;
    int lai;
bool chk(int x)
{
    FOR(i,lai) if(str[x - i] != ai[lai - i - 1]) return false;
    return true;
}
int main()
{
    scanf("%s%s",str,ai);
    lstr = strlen(str);
    lai = strlen(ai);
    int ans = 0;
    for(int i = lai - 1; i < lstr; i++)
    {
        if(chk(i))
        {
            ans ++;
            str[i] = '#';
        }
    }
    cout << ans << endl;
//    puts(str);
}
