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
int f[MAXN];
int c[MAXN];
int a[MAXN];
int a0[MAXN];
int la[MAXN];
int k0;
int lk;
int n;
int m;
int k;
int ans[MAXN];
void putans()
{
    int tot = n - 1;
    int next;
    for(int i = k0 - 1; i >= 0; i--)
    {
        ans[tot--] = a0[i];
        next = a0[i];
        while(c[next] != -1)
        {
            ans[tot--] = c[next];
            next = c[next];
        }
    }
    printf("%d",ans[0]);
    for(int i = 1; i < n; i++)
        printf(" %d",ans[i]);
    puts("");
}
int main()
{
    int _T;
    scanf("%d", &_T);
    bool b;
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        scanf("%d%d",&n,&m);
        b = false;
        clr(f,-1);
        clr(c,-1);
        for(int l = 0; l < m; l++)
        {
            scanf("%d",&k);
            for(int i = 0; i < k; i++)
                scanf("%d",&a[i]);
            for(int i = 1; i < k; i++)
                if(a[i - 1] > a[i]) b = true;
            if(b) continue;
            if(l == 0) k0 = k;
            if(l == 0) for(int i = 0; i < k; i++)
                a0[i] = a[i];
            if(l)
            {
                int j = lk - 1;
                for(int i = k - 1; i >= 0; i--)
                {
                    while((j >= 0 && la[j] > a[i]) || (j >= 0 && c[la[j]] != -1)) j--;
                    if(j < 0)
                        b = true;
                    if(b) break;
                    if(c[la[j]] == -1)
                    {
                        c[la[j]] = a[i];
                        f[a[i]] = la[j];
                    }
                    else b = true;
                    if(b) break;
                }
                if(b) continue;
            }
            for(int i = 0; i < k; i++)
                la[i] = a[i];
            lk = k;
        }
        printf("Case #%d: ",CAS);
        if(b) puts("No solution");
        else
        {
            putans();
        }
    }
    return 0;
}
