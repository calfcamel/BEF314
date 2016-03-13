#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>
#include <map>
using namespace std;
#define PII pair<int, int>
#define MP(a, b) make_pair(a, b)
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define PB(x) push_back(x)
#define SZ size()
#define LL long long
#define PB(x) push_back(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define u32 unsigned int
#define ONES(x) __builtin_popcount(x)

unsigned int ELFhash(char *str)
{
    unsigned int h = 0;
    unsigned int x;
    while(*str)
    {
        h = (h << 4) + *str++;
        x = h & 0xF0000000L;
        if(x)
        {
            h ^= x>>24;
            h &= ~x;
        }
    }
    return h & 0x7FFFFFFF;
}

map<u32, int>f[(1 << 6)];
LL cnt[10];
char s[50001][10];
char buf[10];
LL ans[10];
int n;

int main()
{
    freopen("high.in", "r", stdin);
    freopen("high.out", "w", stdout);

    FOR(i, (1 << 6)) f[i].clear();
    scanf("%d", &n);

    memset(buf, 0, sizeof buf);
    FOR(i, n) scanf("%s", s[i]);

    memset(ans, 0, sizeof ans);
    FOR(i, n)
    {
        FOR(j, 32)
        {
            FOR(k, 5)
            if(j & (1 << k))
            {
                buf[k] = s[i][k];
            }
            else buf[k] = '#';
            ans[5 - ONES(j)] += f[j][ELFhash(buf)];
            f[j][ELFhash(buf)] += 1;
        }
    }
//    FOR(i, 6) printf("%d ", ans[i]);
//    puts("");
    cnt[0] = ans[0];
    cnt[1] = ans[1] - ans[0] * 5;
    cnt[2] = ans[2] - ans[1] * 4 + ans[0] * 10;
    cnt[3] = ans[3] - ans[2] * 3 + ans[1] * 6 - ans[0] * 10;
    cnt[4] = ans[4] - ans[3] * 2 + ans[2] * 3 - ans[1] * 4 + ans[0] * 5;
    cnt[5] = ans[5] - ans[4] + ans[3] - ans[2] + ans[1] - ans[0];
    cout << cnt[0];
    for(int i = 1; i <= 5; i++)
        cout << " " << cnt[i];
    cout << endl;
    return 0;
}
