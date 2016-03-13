#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;
#define LL long long
#define u32 usigned int
#define AA first
#define BB second
typedef pair<int, int> PII;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) y = max(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b), make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define INS(x) insert(x)
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define REP(i, L, R) for(int i = L; i <= (R); i++)
#define MEM(x,y) memset(a, (y), sizeof a);
#define ECH(x) for(__typeof x.OP it = x.OP; it != x.ED; it++)
#define ONES(x) __builtin_popcount(x)
/*====================================*/
#define N 100001
const int MAXN = 200;
const int z = 50;
int a[MAXN];
bool check()
{
    FOR(i,MAXN)
    {
        if(a[i] > 1) return true;
        if(i && a[i] && a[i - 1]) return true;
    }
    return false;
}
void calc2()
{
    for(int i = 1; i <= z; i++)
    if(a[i] > 1)
    {
        a[i - 1] += a[i] / 2;
        a[i + 2] += a[i] / 2;
        a[i] %= 2;
    }
    for(int i = MAXN - 2; i >= z; i--)
    {
        if(a[i] > 1)
        {
            a[i - 1] += a[i] / 2;
            a[i + 2] += a[i] / 2;
            a[i] %= 2;
        }
    }
}
void calc11()
{
    int tmp;
    FOR(i,MAXN)
    {
        if(i && (i - 1)&& a[i] && a[i - 1])
        {
            tmp = min(a[i],a[i - 1]);
            a[i] -= tmp;
            a[i - 1] -= tmp;
            a[i - 2] += tmp;
        }
    }
}
void calc()
{
    while(check())
    {
        calc2();
        calc11();
    }
}
void print()
{
    int i = 0;
    while(a[i] == 0) i++;
    int j = MAXN - 1;
    while(a[j] == 0) j--;
    for(int k = i; k <= j; k++)
    {
        printf("%d",a[k]);
        if(k == z && j > z) printf(".");
    }
    puts("");
}
int main()
{
    int n;
    while(scanf("%d",&n)!= EOF)
    {
        MEM(a,0);
        a[50] = n;
        calc();
        print();
    }
}
