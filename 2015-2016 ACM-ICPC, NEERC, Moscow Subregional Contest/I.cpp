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

const int MAXN = 100000 + 5;

int a[2000];
int main()
{
    int n;
    scanf("%d",&n);
    int x,y;
    clr(a,0);
    FOR(i,n)
    {
        scanf("%d%d",&x,&y);
        for(int i = x; i <= y; i++)
            a[i] = 1;
    }
    int tmp;
    bool flag = true;
    for(int i = 1; i <= 1826; i++)
    {
        tmp = 0;
        FOR(j,180)
        {
            if(i + j > 1826) break;
            tmp += a[i + j];
        }
        //if(tmp)cout << i <<"\t"<< tmp << endl;
        if(tmp > 90) flag = false;
    }
    if(flag) puts("Yes");
    else puts("No");
}
