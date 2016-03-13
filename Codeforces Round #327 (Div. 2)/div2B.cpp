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

const int MAXN = 200000 + 5;

char s[MAXN];
char x[5];
char y[5];
char a[26];
int get(char ch)
{
    FOR(i,26) if(a[i] == ch) return i;
}
int main()
{
    int n,m;
    FOR(i,26) a[i] = 'a' + i;
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    FOR(i,m)
    {
        scanf("%s%s",x,y);
        swap(a[get(x[0])],a[get(y[0])]);
    }
    FOR(i,n)
    {
        printf("%c",a[s[i] - 'a']);
    }
    puts("");
}
