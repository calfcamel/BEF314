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

int cnt[1000];
char s[MAXN];
int main(){
    scanf("%s",s);
    int l = strlen(s);
    clr(cnt,0);
    FOR(i,n) cnt[s[i]]++;
    char chj = 0;
    for(int i = 'a'; i <= 'z'; i++)
    {
        if(cnt[i] & 1)
        {
            chj = i;
        }
    }
    for(int i = 'a'; i <= 'z'; i++)
    {
        if((cnt[i] & 1) && chj != i)
        {
            cnt[i]--;
            cnt[a]++;
        }
    }
    if(j)
    return 0;
}
