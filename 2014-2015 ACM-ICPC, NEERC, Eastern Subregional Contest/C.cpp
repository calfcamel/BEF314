#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
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
#define MP3(x,y,z) make_pair(x, makepair(y,z))
#define AA first
#define BB second
#define AAA first.first
#define BBA second.first
#define BBB second.second
#define PB push_back
#define SZ size()
#define dbg(x) cerr <<#x<<" = " << x << endl
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)

vector<piii> v;
const int MAXN = 100000 + 5;
int main()
{
    int n;
    scanf("%d",&n);
    int c,dd,MM,hh,mm,t;
    v.clear();
    FOR(i,n)
    {
        scanf("%d %d.%d %d:%d",&c,&dd,&MM,&hh,&mm);
        time = MM * 1000000 + dd * 10000 + hh * 100 + mm;
        v.PB(MP3(t,c));
    }
    return 0;
}
