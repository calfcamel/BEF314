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
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int INF = 0x3FFFFFFF; // INF / 2
const int MAXTEST = 1000000000;
bool check(int i)
{
    if(i / 1 % 1000 == 233) return true;
    if(i / 10 % 1000 == 233) return true;
    if(i / 100 % 1000 == 233) return true;
    if(i / 1000 % 1000 == 233) return true;
    if(i / 10000 % 1000 == 233) return true;
    if(i / 100000 % 1000 == 233) return true;
    if(i / 1000000 % 1000 == 233) return true;
    return false;
}
int main()
{
    int tot = 0;
    for(int i = 1; i <= MAXTEST; i++)
    {
        if(check(i))
        {
            tot++;
//            cout << tot << "\t" << i << endl;
        }
    }
    cout << tot << endl;
}




