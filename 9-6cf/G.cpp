#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100010
#define LL long long
#define INF
#define M 200010

LL f[N];
int q[N];
bool vis[N];
int n, m;
int ind[N], pre[N];
int c[M], t[M], nt[M];
int cnt;

void add(int x, int y, int C)
{
    t[cnt] = y;
    nt[cnt] = ind[x];
    c[cnt] = C;
    ind[x] = cnt;
    cnt++;
}

void add2(int x, int y, int C)
{
    add(x, y, C);
    add(y, x, C);
}

void spfa()
{
    int l = 0, r = 0;
    memset(vis, 0, sizeof vis);
    vis[n - 1] = true;
    q[l] = n - 1;
    memset(f, -1, sizeof f);
    f[n - 1] = 0;
    pre[n - 1] = -1;
    while(l <= r)
    {
        int x = q[l % N];
        l++;
        vis[x] = false;
        for(int k = ind[x]; k != -1; k = nt[k])
        if(f[x] * 10LL + c[k] < f[t[k]] || f[t[k]] == -1)
        {
            f[t[k]] = f[x] * 10LL + c[k];
            pre[t[k]] = x;
            if(!vis[t[k]])
            {
                r++;
                q[r % N] = t[k];
                vis[t[k]] = true;
            }
        }
    }
}

int main()
{
    memset(ind, -1, sizeof ind);
    cnt = 0;
    scanf("%d%d", &n, &m);
    while(m--)
    {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        add2(x, y, z);
    }
    spfa();
    printf("%I64d\n", f[0]);
    int cc = 0;
    int k = 0;
    while(k >= 0)
    {
        cc++;
        k = pre[k];
    }
    printf("%d\n", cc);
    k = 0;
    while(k >= 0)
    {
        printf("%d ", k);
        k = pre[k];
    }
    return 0;
}
