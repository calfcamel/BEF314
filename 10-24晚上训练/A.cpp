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

const int MAXN = 100000 + 5;

int main()
{
    int n;
    scanf("%d",&n);
    int a = 0;
    int b = 0;
    int x;
    FOR(i,n)
    {
        scanf("%d",&x);
        if(x == 25)
        {
            a++;
        }
        if(x == 50)
        {
            a--;
            b++;
        }
        if(x == 100)
        {
            if(b >= 1) {b--; a--;}
            else a -= 3;
        }
        if(b < 0 || a < 0)
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
