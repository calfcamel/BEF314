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
#define MEM(x) memset(a, 0, sizeof a);
#define ECH(x) for(__typeof x.OP it = x.OP; it != x.ED; it++)
#define ONES(x) __builtin_popcount(x)
/*====================================*/
#define N 40001
double f[N];
int a[N];
int n;
int sum;
double P;
LL b[41];
int main()
{
    b[0] = 1;
    for(int i = 1; i <= 40; i++) b[i] = b[i - 1] * 2LL;
    int _T; scanf("%d", &_T);
    while(_T--)
    {
        scanf("%d%lf", &n, &P);
        sum = 0;
        FOR(i, n) scanf("%d", &a[i]);
        FOR(i, n) sum += a[i];

        memset(f, 0, sizeof f);
        f[0] = 1;
        FOR(i, n)
        {
            for(int j = sum; j >= a[i]; j--) if(f[j - a[i]]) f[j] += f[j - a[i]];
        }
//        FOR(i, sum) cout << f[i] << endl;
        LL Q = (int)(P * 1000);
        LL cnt = 0;
        LL ans = 0;
        REP(i, 0, sum) if(f[i])
        {
            cnt += f[i];
            if(1000LL * cnt < Q * b[n])
            {
                continue;
            }
            ans = i;
            break;
        }
        if(Q == 0) ans = 0;
        printf("%I64d\n",ans);
    }
}
