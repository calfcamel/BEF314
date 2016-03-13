
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <unordered_map>
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
#define all(x) x.begin(), x.end()
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 1000000 + 10;
char s[MAXN];
char z[MAXN];
int ans;
int p;
void gun()
{
    puts("Impossible");
    exit(0);
}
int cost(char a, char b)
{
//    cout << a << b << endl;
    if(a == '<' && b == '>') return 0;
    if(a == '(' && b == ')') return 0;
    if(a == '{' && b == '}') return 0;
    if(a == '[' && b == ']') return 0;
    return 1;
}
bool isleft(char a)
{
    if(a == '<') return true;
    if(a == '(') return true;
    if(a == '{') return true;
    if(a == '[') return true;
    return false;
}
void push(char a)
{
    z[p++] = a;
}
bool pop(char a)
{
    if(p <= 0) return false;
    p--;
    ans += cost(z[p], a);
    return true;
}
int main()
{
    scanf("%s",s);
    int l = strlen(s);
    if(l & 1)
    {
        puts("Impossible");
        return 0;
    }
    ans = 0;
    p = 0;
    FOR(i,l)
    {
        if(isleft(s[i]))
        {
            push(s[i]);
        }
        else
        {
            if(pop(s[i]) == false) gun();
        }
    }
    if(p != 0) gun();
    cout << ans << endl;
    return 0;
}
