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
int f[100];
int sg[1005];
int _hash[1005];
void GETSG(int n)
{
    clr(sg,0);
    for(int i = 1; i <= n; i++)
    {
        clr(_hash,0);
        for(int j = 0; i - f[j] >= 0; j++)
            _hash[sg[i - f[j]]] = 1;
        for(int j = 0; j <= n; j++)
        {
            if(!_hash[j])
            {
                sg[i] = j;
                break;
            }
        }
    }
}
int main()
{
    f[0] = 1;
    f[1] = 2;
    for(int i = 2; i <= 15; i++)
        f[i] = f[i - 1] + f[i - 2];
    GETSG(1000);
    int n,m,p;
    while(scanf("%d%d%d",&n,&m,&p) != EOF)
    {
        if(n == 0 && m == 0 && p == 0) return 0;
        if(sg[n] ^ sg[m] ^ sg[p])
        {
            puts("Fibo");
        }
        else
        {
            puts("Nacci");
        }

    }
    return 0;
}
