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

char s[1005];
int n;
int p;
inline bool check(int i)
{
    if(i - 1 >= 0 && s[i] == s[i - 1]) return false;
    if(i - 2 >= 0 && s[i] == s[i - 2]) return false;
    return true;
}
int main()
{
    scanf("%d%d%s",&n,&p,s);
    bool boo;
    char tmp = 'a' + p - 1;
    for(int i = n - 1 ; i >= 0; i--) if(s[i] < tmp)
    {
        s[i] = s[i] + 1;
        boo = check(i);
        while(check(i) == false && s[i] + 1 <= tmp) s[i] = s[i] + 1;
        boo = check(i);
        if(boo) for(int j = i + 1; j < n; j++)
        {
            s[j] = 'a';
            while(check(j) == false && s[j] + 1 <= tmp) s[j] = s[j] + 1;
            boo &= check(j);
        }
        if(boo)
        {
            puts(s);
            return 0;
        }
    }
    puts("NO");
    return 0;
}
