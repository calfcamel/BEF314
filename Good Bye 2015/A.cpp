
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <unordered_map>
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
#define all(x) x.begin(), x.end()
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 100000 + 10;

int main()
{
    int n;
    string s1,s;
    cin >> n >> s1 >> s;
    int ans;
    if(s[0] == 'w' && n == 5) ans = 53;
    else if(s[0] == 'w' && n == 6) ans = 53;
    else if(s[0] == 'w') ans = 52;
    else if(n <= 29) ans = 12;
    else if(n == 30) ans = 11;
    else if(n == 31) ans = 7;
    cout << ans << endl;
}
