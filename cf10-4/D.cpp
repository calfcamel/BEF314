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
inline int lowbit(int x)
{
    return x & (-x);
}
struct
{
    int a[305];
    int N = 303;
    void CLR()
    {
        clr(a,0);
    }
    void ins(int p, int c)
    {
        while(p <= N)
        {
            a[p] = max(a[p], c);
            p += lowbit(p);
        }
    }
    int qry(int p)
    {
        int ans = 0;
        while(p > 0)
        {
            ans = max(ans, a[p]);
            p -= lowbit(p);
        }
        return ans;
    }
}s;
int a[102 * 204];
int f[10300];
void LISf()
{

}
int g[10300];
void LISg()
{

}
int num[10300];
void GETnum(int t)
{

}
int dp[10300 * 2];
void GETsmall(int n)
{
    clr(dp,0);
    s.CLR();
    for(int i = 0; i < n; i++)
    {

    }
}
int main()
{
    int n,t;
    scanf("%d",&n,&t);
    for(int i = 0; i < n; i++)
        scanf("%d",a[i]);
    for(int l = 1; l <= 204; l++)
    {
        for(int i = 0; i < n; i++)
            a[i + l * n] = a[i];
    }
    if(T <= 204)
    {
        GETsmall(n * t);
        cout << *max_element(dp,dp + n * t) << endl;
        return 0;
    }
}
