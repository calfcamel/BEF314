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
const double EPS = 1e-8;
int sign(double x)
{
    if(x > EPS) return 1;
    if(x < -EPS) return -1;
    return 0;
}

int main()
{
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        bool flag = false;
        int t,v1,v2;
        scanf("%d%d%d",&t,&v1,&v2);
        if(v1 > v2) swap(v1,v2);
        if(v1 == 0) flag = false;
        else if(v1 == v2) flag = true;
        else
        {
            if(sign(600.0 / v2 - 300.0 * sqrt(2.0) / v1))
        }
        printf("Case #%d: ",CAS);
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
