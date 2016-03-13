#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;
#define LL long long
#define u32 usigned int
#define AA first
#define BB second
typedef pair<int, int> PII;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) y = max(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b), make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define INS(x) insert(x)
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define REP(i, L, R) for(int i = L; i <= (R); i++)
#define MEM(x,y) memset(a, (y), sizeof a);
#define ECH(x) for(__typeof x.OP it = x.OP; it != x.ED; it++)
#define ONES(x) __builtin_popcount(x)
/*====================================*/
#define N 100001

char str[N];
bool b[N][27];
bool q[N];
int main()
{
    int m,l;
    while(scanf("%d%d",&m,&l)!= EOF)
    {
        scanf("%s",str);
        if(m > 26)
        {
            puts("0");
            continue;
        }
        int n = strlen(str);
        for(int i = 0; i < n; i++)
        {
            b[i][0] = true;
            for(int j = 1; j < m && i + j * l < n; j++)
            {
                if(b[i][j - 1] && str[i] != str[i + j * l])
                {
                    b[i][j] = true;
                }
                else b[i][j] = false;
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m && i + j * l < n; j++)
                if(b[i][j]) cout << i << " " << j << endl;
        }
        for(int i = 0; i < n - l * m + 1; i++)
        {
            q[i] = true;
            for(int j = 0; j < m; j++)
            {
                q[i] &= b[i + j * l][m - j];
            }
        }
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < n - l * m + 1; i++)
        {
            if(q[i]) cnt++;
            else cnt = 0;
            if(cnt >= m) ans ++;
        }
        printf("%d\n",ans);
    }
}
