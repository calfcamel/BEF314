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
const int MAXN = 205;
int tot;
int a[10];
bool chk(int k)
{
    tot = 0;
    while(k)
    {
        a[tot++] = k % 10;
        k /= 10;
    }
    FOR(i,tot) if(a[i] != a[tot - 1 - i]) return false;
    return true;
}
vector<int> v;
int main()
{
    for(int i = 100; i <= 999; i++) for(int j = 100; j <= 999; j++) if(chk(i * j)) v.PB(i * j);
    sort(all(v));
    cout << v[v.SZ - 1] << endl;
}



