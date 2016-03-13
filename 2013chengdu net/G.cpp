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


const int MAXN = 10000 + 5;
int mm[10];
LL b[35];
LL c[10];
LL max_weight[10];
int m;
LL dp[10][5000];
LL dfs(int dig,LL weight,int MAX)
{
    if(dp[dig][weight] != -1 && MAX == -1) return dp[dig][weight];
    if(dig == 0) return 1;
    if(weight >= max_weight[dig] && MAX == -1) return c[dig];
    if(weight >= max_weight[dig]) return m % c[dig] + 1;
//    {
//        LL ret = 0;
//        int i = dig;
//        while(i > 0)
//        {
//            ret = ret * 10 + mm[i];
//            i--;
//        }
//    }
    LL ret = 0;
    if(MAX == -1)
    {
        for(LL i = 0; i < 10; i++)
            if(b[dig] * i <= weight)
                ret += dfs(dig - 1, weight - b[dig] * i, -1);
        dp[dig][weight] = ret;
        return ret;
    }
    else
    {
        for(int i = 0; i < MAX; i++)
            if(b[dig] * i <= weight)
                ret += dfs(dig - 1, weight - b[dig] * i, -1);
        if(b[dig] * MAX <= weight)
            ret += dfs(dig - 1, weight - b[dig] * MAX, mm[dig - 1]);
        return ret;
    }
}
LL getweight(int x)
{
    LL ret = 0;
    int i = 0;
    while(x)
    {
        ret += x % 10 * b[i + 1];
        i++;
        x = x / 10;
    }
    return ret;
}
int getdig(int x)
{
    int ret = 0;
    while(x)
    {
        ret ++;
        x /= 10;
    }
    return ret;
}

void fen(int x)
{
    clr(mm, 0);
    int tot = 1;
    while(x)
    {
        mm[tot++] = x % 10;
        x = x / 10;
    }
}
int main()
{
    clr(dp, -1);
    c[0] = 1;
    for(int i = 1; i < 10; i++)
        c[i] = c[i - 1] * 10LL;
    b[0] = 0; b[1] = 1;
    for(int i = 2; i < 35; i++)
        b[i] = b[i - 1] * 2LL;
    max_weight[0] = 9;
    for(int i = 1; i < 10; i++)
        max_weight[i] = max_weight[i - 1] + b[i] * 9LL;
    int _T;
    scanf("%d", &_T);
    LL ans = 0;
    int n;
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        scanf("%d%d",&n,&m);
        LL weight = getweight(n);
        int digm = getdig(m);
        int dign = getdig(n);
        fen(m);
//        cout << "fen m :"; for(int i = 1; i < 10; i++) cout << mm[i] << " " ; cout << endl;
//        cout << "weight = " << weight << " dign m = " << dign << " " << digm << endl;
        if(n == 0) ans = 1;
        else
        {
            ans = 999999999999LL % c[dign - 1];
            ans ++;// zero
            ans = 1;
//            cout << "INIT ans = " << ans << endl;
            for(int i = 1; i < digm; i++)
            {
                for(LL j = 1; j < 10; j++)
                    if(b[i] * j <= weight)
                    {
                        ans += dfs(i - 1, weight - b[i] * j, -1);
//                        cout << "ADD " << i << " " << j << " " << dfs(i - 1, weight - b[i] * j, -1) << endl;
                    }
            }
            for(LL j = 1; j < mm[digm]; j++)
            {
                if(b[digm] * j <= weight)
                {
                    ans += dfs(digm - 1, weight - b[digm] * j, -1);
//                    cout << "MAX DIG ADD " << j << " " <<  dfs(digm - 1, weight - b[digm] * j, -1) <<endl;
                }
            }
//            cout << "mm[digm] = " << mm[digm] << endl;
            if(b[digm] * mm[digm] <= weight)
            {
                ans += dfs(digm - 1, weight - b[digm] * mm[digm], mm[digm - 1]);
//                cout << "MAX MAX ADD " << dfs(digm - 1, weight - b[digm] * mm[digm], mm[digm - 1]) << endl;
            }
        }
        printf("Case #%d: %I64d\n",CAS,ans);
    }
    return 0;

}
