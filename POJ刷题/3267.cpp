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
typedef pair<int, int> PII;
#define FOR(i,x) for(int i = 0, _END_ = (int)(x); i < _END_ ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
int n,l;
char a[305];
char str[605][305];
int dp[305];
int ls[605];
int cal(int i, int k)
{
    int fal = dp[i];
    if(l - i < ls[k]) return dp[i];
    int ret = 0;
    int j = 0;
    while(i < l && j < ls[k])
    {
        if(str[k][j] == a[i]) j++;
        else ret++;
        i++;
    }
    if(j < ls[k]) return fal;
    else return ret + dp[i];
}
int main()
{
    scanf("%d%d",&n,&l);
    scanf("%s",a);
    FOR(i,n) scanf("%s",&str[i]);
    FOR(i,l) dp[i] = l - i;
    dp[l] = 0;
    FOR(i,n) ls[i] = strlen(str[i]);
    for(int i = l - 1; i >= 0; i--) FOR(j,n) cmin(dp[i],cal(i,j));
    printf("%d\n",dp[0]);
}
