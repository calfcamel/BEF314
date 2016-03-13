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
char str1[MAXN];
char str2[MAXN];
char str3[MAXN];
int main()
{
    int n;
    int m;
    int now;
    scanf("%d%d%s%d%s",&n,&now,str1,&m,str2);
    int i = 0;
    now --;
    str3[i++] = str1[now];
    FOR(j,m)
    {
        if(str2[j] == 'R') now ++;
        else now --;
        str3[i++] = str1[now];
    }
    str3[i] = 0;
    puts(str3);
    return 0;
}
