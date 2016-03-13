// calfcamel
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
const int MAXN = 100000 + 5;
LL gcd(LL a,LL b){
	if(b==0)return a;
	return gcd(b,a % b);
}
LL g;
LL a[MAXN];
inline int check(LL x)
{
    while(x % 2 == 0) x /= 2;
    while(x % 3 == 0) x /= 3;
    if(x == 1) return 1;
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    LL x;
    for(int i = 0; i < n; i++)
        scanf("%I64d",&a[i]);
    g = gcd(a[0],a[1]);
    for(int i = 2; i < n; i++)
        g = gcd(g,a[i]);
    for(int i = 0; i < n; i++)
        a[i] /= g;
    int bb = 1;
    for(int i = 0; i < n; i++)
        {
            bb &= check(a[i]);
            if(bb == 0) break;
        }
    if(bb) puts("Yes");
    else puts("No");
}
