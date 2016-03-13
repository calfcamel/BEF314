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
#define dbg(x) cerr <<#x<<" = " << x << endl
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)

const int MAXN = 500000 + 5;
int a[MAXN];
int b[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    FOR(i,n) scanf("%d",&a[i]);
    a[n] = a[n - 1];
    int cnt = 0;
    int st = 0;
    int ed;
    int ans = 0;
    for(int i = 1; i < n + 1; i++)
    {
        if(a[i] == a[i - 1])
        {
            ed = i - 1;
            if(ed != st)
            {
                if((ed - st + 1) & 1)
                {
                    FOR(j,(ed - st)) a[st + j] = a[st];
                }
                else
                {
                    FOR(j,(ed - st)) a[st + j] = (j > (ed - st) / 2) ? a[ed] : a[st];
                }
                ans = max(ans, (ed - st) / 2);
//                cout << st << " " << ed << endl;
            }
            st = i;
        }
    }
    printf("%d\n",ans);
    printf("%d",a[0]);
    for(int i = 1; i < n; i++) printf(" %d",a[i]);
    puts("");
    return 0;
}
