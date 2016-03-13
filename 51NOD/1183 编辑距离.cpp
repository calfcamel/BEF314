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
const int MAXN = 1010;
char a[MAXN];
char b[MAXN];
int la,lb;
int dp[MAXN][MAXN];
int main()
{
    scanf("%s",a + 1); a[0] = '%';
    scanf("%s",b + 1); b[0] = '%';
    la = strlen(a) - 1;
    lb = strlen(b) - 1;
    clr(dp,0);
//    dbg(la);
//    dbg(lb);
    FOR(i,1001) dp[0][i] = i;
    FOR(i,1001) dp[i][0] = i;
    FORR(i,la) FORR(j,lb)
    {
        int tmp = 9999999;
        cmin(tmp, dp[i - 1][j] + 1); /// add
        cmin(tmp, dp[i][j - 1] + 1); /// delete
        if(a[i] == b[j])cmin(tmp, dp[i - 1][j - 1]); /// equal
        cmin(tmp, dp[i - 1][j - 1] + 1); /// modify
        dp[i][j] = tmp;
//        cout << i << " " << j << " " << dp[i][j] << endl;
    }
    cout << dp[la][lb] << endl;
}


