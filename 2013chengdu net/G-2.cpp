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

struct
{
    int lowbit(int x) { return x & (-x); }
    int a[100010];
    void init()
    {
        memset(a, 0, sizeof a);
    }

    int qry(int p)
    {
        int ans = 0;
        while(p > 0)
        {
            ans += a[p];
            p -= lowbit(p);
        }
        return ans;
    }

    void insert(int p, int c)
    {
        while(p <= n)
        {
            a[p] += c;
            p += lowbit(p);
        }
    }

    void INS(int a, int b, int c)
    {
        insert(a, c);
        insert(b + 1, -c);
    }

    int qry(int a, int b)
    {
        return qry(b) - qry(a - 1);
    }
}a, b;

int main()
{

}
