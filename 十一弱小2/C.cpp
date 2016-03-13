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


const int MAXN = 100000 + 5;

int _cnt_bit[1 << 16];
int dp[2][1 << 16];
char s[130][20];
int l[130];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < (1 << m); i++) _cnt_bit[i] = __builtin_popcount(i);
    for(int i = 0; i < n; i++)
        scanf("%s",&s[i]);
    for(int i = 0; i < n; i++)
        l[i] = strlen(s[i]);
    clr(dp, -1);
    dp[0][0] = 0;
    int cur = 0; int next = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            clr(dp[next], -1);
            for(int bit = 0; bit < (1 << m); bit++) if(dp[cur][bit] >= 0)
            {
                int idx = _cnt_bit[bit & (1 << j) - 1];
                if(idx < l[i])
                {
                    int nxt = dp[cur][bit];
                    if(j && (bit & 1 << (j - 1)) && s[i][idx - 1] == s[i][idx]) nxt++;
                    if(i && (bit & 1 << j) && s[i][idx] == s[i - 1][l[i - 1] - _cnt_bit[bit >> j]]) nxt++;
                    cmax(dp[next][bit | 1 << j], nxt);
                }
                if(idx + m - j > l[i])
                {
                    cmax(dp[next][bit & ~(1 << j)], dp[cur][bit]);
                }
            }
            swap(cur, next);
        }
    }
    printf("%d\n",2 * *max_element(dp[cur], dp[cur] + (1 << m)));
    return 0;
}
