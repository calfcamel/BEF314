
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

const int MAXN = 200000 + 5;
char a[MAXN];
char b[MAXN];
int sum1[MAXN];
int sum0[MAXN];
int main()
{
    scanf("%s%s",a,b);
    int la = strlen(a);
    int lb = strlen(b);
    sum1[0] = 0;
    sum0[0] = 0;
    FORR(i,lb)
    {
        sum1[i] = sum1[i - 1];
        sum0[i] = sum0[i - 1];
        if(b[i - 1] == '0') sum0[i]++;
        else sum1[i]++;
    }
    LL ans = 0;
    FOR(i,la) if(a[i] == '0') ans += sum1[lb - (la - i) + 1] - sum1[i];
    else  ans += sum0[lb - (la - i) + 1] - sum0[i];
    cout << ans << endl;
}
