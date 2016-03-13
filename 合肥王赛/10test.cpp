#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second

PII f[100010];
int pos[100010];
int n;

struct
{
    int lowbit(int x) { return x & (-x); }
    int a[100010];
    void init()
    {
        memset(a, 0, sizeof a);
    }

    int qry(int p)
    {
        int ans = 0;
        while(p > 0)
        {
            ans += a[p];
            p -= lowbit(p);
        }
        return ans;
    }

    void insert(int p, int c)
    {
        while(p <= n)
        {
            a[p] += c;
            p += lowbit(p);
        }
    }

    void INS(int a, int b, int c)
    {
        insert(a, c);
        insert(b + 1, -c);
    }

    int qry(int a, int b)
    {
        return qry(b) - qry(a - 1);
    }
}a, b;

bool valid(int x)
{
    if(x < 1 || x > n) return false;
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int _T; scanf("%d", &_T);
    for(int ii = 1; ii <= _T; ii++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d%d", &f[i].AA, &f[i].BB);
        sort(f, f + n);

        bool flg = false;
        a.init();
        b.init();
        for(int i = 0; i < n; i++)
        {
            int p1 = f[i].BB + a.qry(f[i].BB + 1) + 1;
            int p2 = a.qry(n - f[i].BB - i) + n - f[i].BB - i;
            cout << "qry " << f[i].BB + 1 << " " << n - f[i].BB - i << endl;
            int p;
            cout << f[i].AA << " " << f[i].BB << " ASS "  << " "<< p1 << ' ' << p2 << endl;

            if(!valid(p1) && !valid(p2)) { flg = true; break; }
            if(!valid(p1)) p = p2;
            else if(!valid(p2)) p = p1;
            else p = min(p1, p2);
            pos[p] = f[i].AA;

            //a.INS(1, p, 1);
            a.INS(p, n, 1);
        }
        if(flg) printf("Case #%d: impossible\n", ii);
        else { printf("Case #%d:", ii); for(int i = 1; i <= n; i++) printf(" %d", pos[i]); printf("\n"); }
    }
    return 0;
}
