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
const int MAXINT = 0x3FFFFFFF; // INF / 2
const int MAXN = 1000000 + 5;
char s[MAXN];
int a[MAXN];
int b[MAXN];
int main()
{
    scanf("%s",s);
    int l = strlen(s);
    a[0] = 0;
    for(int i = 0; i < l; i++)
    {
        if(s[i] == '0') a[i + 1] = a[i] + 1;
        else a[i + 1] = a[i];
    }
    b[l] = 0;
    for(int i = l - 1; i >= 0; i--)
    {
        if(s[i] == '1') b[i] = b[i + 1] + 1;
        else b[i] = b[i + 1];
    }
//    for(int i = 0; i <= l; i++)
//    {
//        cout << a[i] << " " << b[i] << " " << i << endl;
//    }
    for(int k = 0; k <= l; k++)
    {
        if(a[k] == b[k])
        {
            cout << k << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}
