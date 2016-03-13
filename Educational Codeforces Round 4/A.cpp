
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

const int MAXN = 200000 + 10;
string s;
int main()
{
    int n,p,q;
    cin >> n >> p >> q >> s;
    int x = 0;
    int y = 0;
    bool boo = false;
    FOR(i,200) if(n - p * i >= 0)
    {
        int tmp = n - p * i;
        if(tmp % q== 0)
        {
            x = i;
            y = tmp / q;
            boo = true;
        }
    }
    if(boo)
    {
        cout << x + y << endl;
        int i = 0;
        FOR(k,x)
        {
            FOR(j,p)
            {
                cout << s[i++];
            }
            cout << endl;
        }
        FOR(k,y)
        {
            FOR(j,q)
            {
                cout << s[i++];
            }
            cout << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }
}
