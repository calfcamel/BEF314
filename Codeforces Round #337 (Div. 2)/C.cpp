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

typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int MAXN = 1026;
int b[11];
int s[MAXN][MAXN];

char fan(char x)
{
    if(x == '+') return '*';
    return '+';
}
int main()
{
    b[0] = 1;
    FORR(i,10) b[i] = b[i - 1] * 2;
    int k;
    cin >> k;
    int n = 1;
    FOR(i,k) n = n * 2;
//    dbg(n);
    s[0][0] = '+';
    for(int l = 1; l <= k; l++)
    {
        FOR(i, b[l - 1]) FOR(j, b[l - 1])
        {
            s[i][j + b[l - 1]] = s[i][j];
            s[i + b[l - 1]][j] = s[i][j];
            s[i + b[l - 1]][j + b[l - 1]] = fan(s[i][j]);
        }
    }
    FOR(i,n)
    {
        FOR(j,n) putchar(s[i][j]);
        puts("");
    }
    return 0;
}
