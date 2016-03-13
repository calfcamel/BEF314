
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
const int MAXN = 50 + 5;
int num[MAXN];
LL a[MAXN];
LL b[MAXN];
LL c[MAXN];

void mul()
{
    clr(c,0);
    for(int i = 0; i <= 50; i++)
        for(int j = 0; j <= 50; j++)
            if(i + j <= 50) c[i + j] += a[i] * b[j];
}
int main()
{
    int _T;
    scanf("%d",&_T);
    while(_T--)
    {
        for(int i = 1; i <= 26; i++)
            scanf("%d",&num[i]);
        clr(c,0);
        for(int i = 1; i <= 26; i++)
        {
            for(int j = 0; j <= 50; j++)
                a[j] = c[j];
            clr(b,0);
            for(int j = 0; j <= num[i]; j++)
            {
                if(j * i > 50) break;
                b[j * i] = 1;
            }
            if(i == 1)
            {
                for(int j = 0; j <= 50; j++)
                    c[j] = b[j];
            }
            else
                mul();
        }
        LL ans = 0;
        for(int i = 1; i <= 50; i++)
            ans += c[i];
        cout << ans << endl;
    }
    return 0;
}
