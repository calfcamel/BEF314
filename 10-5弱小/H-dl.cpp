#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define PII pair<int, int>
#define MP(a, b) make_pair(a, b)
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define N 100010
#define INF 2e9
#define LL long long
#define PB(x) push_back(x)

string f[7] = { string("AB"), string("BC"), string("CA"), string("BA"), string("CB"), string("AC")  };
deque<int>d[3];
deque<int>::iterator iter;
set<string>s;
bool vis[31];
int n;
int nn;

char buf[100];
int c[100];
string num()
{
    string s;
    FOR(i, 3) for(iter = d[i].OP; iter != d[i].ED; iter++) c[*iter] = i;
    FORR(i, n) s.PB(c[i]);
    return s;
}

char fff[10];
int main()
{
//    freopen("hanoi.in","r",stdin);
//    freopen("hanoi.out","w",stdout);
    scanf("%d", &nn);
    FOR(i, 6)
    {
        scanf("%s", fff);
        f[i] = string(fff);
    }
    n = min(nn, 10);
    d[0].clear();
    FOR(i, 3) d[i].clear();
    FORR(i, n) d[0].push_front(i);
    int ans = 0;
    s.clear();
    while(true)
    {
        if(s.find(num()) != s.ED)
        {
            ans = -1;
            break;
        }
        s.insert(num());
        bool flg = true;
        int i = 1;
        for(iter = d[2].OP; iter != d[2].ED; iter++)
        {
            if(*iter != n - i + 1)
            {
                flg = false;
                break;
            }
            i++;
        }
        if(i == n + 1 && flg) break;
        flg = true;
        i = 1;
        for(iter = d[1].OP; iter != d[1].ED; iter++)
        {
            if(*iter != n - i + 1)
            {
                flg = false;
                break;
            }
            i++;
        }
        if(i == n + 1 && flg) break;


        memset(vis, 0, sizeof vis);
        FOR(i, 6)
        {
            int p1 = f[i][0] - 'A';
            int p2 = f[i][1] - 'A';
            if(!d[p1].SZ) continue;
            if( !vis[d[p1].back()] && (d[p2].SZ == 0 || d[p1].back() < d[p2].back()) )
            {
                ans++;
                vis[d[p1].back()] = true;
                int x = d[p1].back();
                d[p2].PB(x);
                d[p1].pop_back();
            }
        }
    }
    if(nn < 10) cout << ans << endl;//printf("%d\n", ans);
    if(nn >= 10)
    {
        if(ans == 39365)
        {
            LL ans = 1;
            FOR(i, nn - 1) ans = ans * 3LL + 2LL;
            cout << ans << endl;
//            printf("%I64d\n", ans);
        }
        else if(ans == 19683)
        {
            LL ans = 1;
            FOR(i, nn - 1) ans = ans * 3LL;
            cout << ans << endl;
//            printf("%I64d\n", ans);
        }
    }
    return 0;
}
