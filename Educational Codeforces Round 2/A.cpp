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
const int MAXINT = 0x3FFFFFFF; // INF / 2
const int MAXN = 300000 + 5;


char s[MAXN];
char a[MAXN];
char b[MAXN];

bool chksp(char ch)
{
    if(ch == 44) return false;
    if(ch == 59) return false;
    return true;
}
bool booa,boob;
int tota,totb;
void gao(int l, int r)
{
    int length = r - l + 1;
    if(length == 1 && chksp(s[l]) == false)
    {
        boob = true;
        b[totb++] = ',';
    }
}
int main()
{
    scanf("%d",s);
    int n = strlen(s);
    int l,r;
    l = 0;
    tota = 0;
    totb = 0;
    booa = false;
    boob = false;
    while(l < n)
    {
        r = l;
        while(chksp(s[r]) && r + 1 < n) r++;
        gao(l,r);
        l = r + 1;
    }
}
