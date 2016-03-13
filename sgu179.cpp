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

char s[10005];
int main()
{
    scanf("%s",&s);
    int l = strlen(s);
    int n = l / 2;
    int suml = 0;
    int sumr = 0;
    int tmp = 0;
    for(int i = 0; i < n; i++)
        if(s[i] == '(') tmp ++;
//    if(tmp == n)
//    {
//        puts("No solution");
//        return 0;
//    }
    for(int i = 0; i < l; i++)
        if(s[i] == '(') suml ++; else sumr ++;
    for(int i = l - 1; i >=0; i--)
    {
        if(s[i] == '(') suml --; else sumr --;
        if(s[i] == '(' && suml > sumr)
        {
            s[i] = ')';
            int lef = n - suml;
            for(int j = i + 1; j < l; j++)
            {
                if(lef)
                {
                    lef--;
                    s[j] = '(';
                }
                else s[j] = ')';
            }
            puts(s);
            return 0;
        }
    }
    puts("No solution");
    return 0;
}
