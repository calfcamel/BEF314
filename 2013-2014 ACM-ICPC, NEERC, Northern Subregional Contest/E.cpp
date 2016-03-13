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
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 100000 + 5;
//GYM
#define ONLINE_JUDGE
char s[MAXN];
int main()
{
    #ifdef ONLINE_JUDGE
        freopen("energy.in","r",stdin);
        freopen("energy.out","w",stdout);
    #endif // ONLINE_JUDGE
    int n;
    int add = 0;
    int left1 = 0;
    int left2 = 0;
    long long ans = 0;
    scanf("%d",&n);
    scanf("%s",s);
    int l = strlen(s);
    FOR(i,l)
    {
        if(s[i] == '2')
        {
            if(n >= 2)
            {
                n -= 2;
                left1 += 2;
                add++;
            }
        }
        if(s[i] == '1')
        {
            if(n >= 1)
            {
                n--;
                add++;
            }
            else
            {
                if(left2)
                {
                    left2--;
                    add++;
                }
                else if(left1)
                {
                    left1 -= 2;
                    left2 += 1;
                }
            }
        }
        ans += add;
    }
    cout << ans << endl;
}
