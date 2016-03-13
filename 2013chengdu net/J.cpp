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


const int MAXN = 100000 + 5;
int a[MAXN];
int b[50];
int now = 0;
void add(int x)
{
//    cout << "ADD " << x << endl;
    int i = 0;
    while(x)
    {
        if(x & 1) b[i]++;
        x = x >> 1;
        i++;
    }
    int tmp = 1;
    now = 0;
    for(int i = 0; i <= 30; i++)
    {
        if(b[i])
        {
            now = now | tmp;
        }
        tmp = tmp << 1;
    }
}
void del(int x)
{
//    cout << "DEL " << x << endl;
    int i = 0;
    while(x)
    {
        if(x & 1) b[i]--;
        x = x >> 1;
        i++;
    }
    int tmp = 1;
    now = 0;
    for(int i = 0; i <= 30; i++)
    {
        if(b[i])
        {
            now = now | tmp;
        }
        tmp = tmp << 1;
    }
}
int main()
{
    int _T;
    scanf("%d", &_T);
    LL ans;
    int n,m;
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        ans = 0;
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        int j = -1;
        now = 0;
        clr(b, 0);
        for(int i = 0; i < n; i++)
        {
            j = max(j, i - 1);
            //cout << "test " << i << " " << j << endl;
            while(j < n - 1 && (a[j + 1] | now) < m){add(a[j + 1]);j++;}
            ans = ans + j - i + 1;
            if(j >= i) del(a[i]);
            //cout << i << " " << j << " " << now << endl << endl;
        }
        printf("Case #%d: %I64d\n",CAS,ans);
    }
    return 0;
}
