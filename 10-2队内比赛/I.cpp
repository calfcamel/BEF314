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
#define PB(x) push_back(x)
#define SZ size()
#define LL long long
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
#define N 2001

int c[N][N];
int f[N][N];
int ans[N];
vector<string>H;
char buf1[20], buf2[20];
pair<string, string>s[N];
int n, q;

void matrixMul(int a[N][N], int b[N][N], int c[N][N])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n;j++)
        {
            if(0 == a[i][j])//这是优化的地方.
            continue;
            for(int k = 0;k < n;k++)
            c[i][k] += a[i][j] * b[j][k];
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int _T; scanf("%d", &_T);
    FOR1(ii, _T)
    {
        scanf("%d%d", &n, &q);
        H.clear();
        FOR(i, n) { scanf("%s%s", buf1, buf2); s[i] = MP(string(buf1), string(buf2)); H.PB(s[i].AA); H.PB(s[i].BB); }
        sort(H.OP, H.ED);
        H.resize(unique(H.OP, H.ED) - H.OP);
        memset(c, 0, sizeof c);
        FOR(i, n)
        {
            int x = lower_bound(H.OP, H.ED, s[i].AA) - H.OP;
            int y = lower_bound(H.OP, H.ED, s[i].BB) - H.OP;
            c[x][y]++;
            c[y][x]++;
        }
        n = H.SZ;
//        cout << "Matrix C : " << endl;
//        for(int i = 0; i < n; i ++)
//        {
//            for(int j = 0; j < n; j++)
//                cout << c[i][j] << " ";
//            cout << endl;
//        }
        memset(f, 0, sizeof f);
        matrixMul(c, c, f);
//        cout << "Matrix F : " << endl;
//        for(int i = 0; i < n; i ++)
//        {
//            for(int j = 0; j < n; j++)
//                cout << f[i][j] << " ";
//            cout << endl;
//        }
        memset(ans, -1, sizeof ans);
        FOR(i, n)
        {
            FOR(j, n)
            if(i != j && f[i][j])
            {
                if(ans[i] < f[i][j]) ans[i] = f[i][j];
            }
        }
        printf("Case %d:\n", ii);
        FOR(i, q)
        {
            scanf("%s", buf1);
            int p = lower_bound(H.OP, H.ED, string(buf1)) - H.OP;
            if(ans[p] == -1) printf("-");
            else
            {
                bool flg = true;
                FOR(j, n) if(!c[i][j] && f[p][j] == ans[p] && j != p) { if(!flg) printf(" "); printf("%s", H[j].c_str()); flg = false;  }
            }
            printf("\n");
        }
    }
    return 0;
}
