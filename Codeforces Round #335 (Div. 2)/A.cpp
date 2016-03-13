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
#define ccmin(x,y) if(x == -1) x = y; else x = min(x,y)
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

const int MAXN = 1000 + 2;

int main()
{
    int a,b,c;
    int x,y,z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    a -= x;
    b -= y;
    c -= z;
    int ansf = 0;
    int ansz = 0;
    if(a > 0) ansz += a / 2;
    if(b > 0) ansz += b / 2;
    if(c > 0) ansz += c / 2;
    if(a < 0) ansf += a;
    if(b < 0) ansf += b;
    if(c < 0) ansf += c;
    if(ansz + ansf >=0) puts("Yes"); else puts("No");
    return 0;
}
