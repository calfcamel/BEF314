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
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;

int dp[205][205][4];
int a[205];
int main()
{
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        int ans = 0;
        int n;
        int x;
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&x);
            ans += x;
        }
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        a[n + 1] = 0;
        a[0] = 0;
        clr(dp,0);
        for(int i = 1; i <= n; i++)
        {
            dp[i][i][0] = 0;
            dp[i][i][1] = a[i];
            dp[i][i][2] = a[i];
            dp[i][i][3] = 2 * a[i];
        }
        cout << "test" << dp[1][1][1] << endl;
        for(int l = 2; l <= n; l++)
            for(int i = 1; i + l - 1 <= n; i++)
            {
                int j = i + l - 1;
                //dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j]);
                dp[i][j][0] = min(dp[i + 1][j][2], dp[i][j - 1][1]);
                dp[i][j][1] = min(dp[i + 1][j][3], dp[i][j - 1][1] + a[j]);
                dp[i][j][2] = min(a[i] + dp[i + 1][j][2], dp[i][j - 1][3]);
                dp[i][j][3] = min(a[i] + dp[i + 1][j][3], dp[i][j - 1][3] + a[j]);
                for(int k = i + 1; k <= j - 1; k++)
                {
                    dp[i][j][3] = min(dp[i][j][3],dp[i][k - 1][3] + dp[k + 1][j][3]);
                    dp[i][j][2] = min(dp[i][j][2],dp[i][k - 1][3] + dp[k + 1][j][2]);
                    dp[i][j][1] = min(dp[i][j][1],dp[i][k - 1][1] + dp[k + 1][j][3]);
                    dp[i][j][0] = min(dp[i][j][0],dp[i][k - 1][1] + dp[k + 1][j][2]);
                }
                    //dp[i][j] = min(dp[i][j],dp[i][k - 1] + dp[k + 1][j] - 2 * a[k]);
                cout << endl;
                cout << "dp[" << i << "][" << j << "][0] = " << dp[i][j][0] << endl;
                cout << "dp[" << i << "][" << j << "][1] = " << dp[i][j][1] << endl;
                cout << "dp[" << i << "][" << j << "][2] = " << dp[i][j][2] << endl;
                cout << "dp[" << i << "][" << j << "][3] = " << dp[i][j][3] << endl;
            }
        printf("Case #%d: ",CAS);
        printf("%d\n",ans + dp[1][n][0]);
    }
    return 0;
}
