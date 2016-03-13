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
typedef pair<int, int> PII;

const int MAXN = 10000 + 5;

    double a,b;
double solve(double len)
{
    int l=1,r=1000000000;

    while(r-l>1)
    {
        int mid=(l+r)/2;

        if(len>b*2.0*mid)
            l=mid;
        else
            r=mid-1;
    }
    while(len<b*2.0*r)
        r--;
    return len/r/2.0;

}

int main()
{
    cin >> a >> b;
    if(b>a||b==0)
        printf("-1\n");
    else if(a==b)
    {
        printf("%f\n",a);
    }
    else
    {
        double ans1=solve(a-b);
        double ans2=solve(a+b);
        printf("%.11f\n",min(ans1,ans2));
    }
    return 0;
}
