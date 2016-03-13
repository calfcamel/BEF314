#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
//#include <unordered_map>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <assert.h>
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
#define all(x) x.begin(), x.end()
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
#define FOR3(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define REP(i,x,y) for(int i = x; i >= (int) (y) ; i--)
const int MAXN = 505;
int a[4];
void print()
{
    FOR(i,4) cout << a[i] << " "; cout << endl;
}
int main()
{
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    print();
    while(next_permutation(a,a + 4)) print();
}
