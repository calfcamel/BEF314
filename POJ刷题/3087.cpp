#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
//#include <unordered_map>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <assert.h>
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
typedef pair<int, int> PII;
#define FOR(i,x) for(int i = 0, _END_ = (int)(x); i < _END_ ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int MAXN = 105;
int l;
char s[MAXN << 1];
char s12[MAXN << 1];
char s1[MAXN];
char s2[MAXN];
int ans;
int ts;
int main()
{
    int _T;
    scanf("%d",&_T);
    FORR(CAS, _T)
    {
        scanf("%d",&l);
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s12);
        ans = 0;
        map<string, bool> vis;
        while(1)
        {
            ts = 0;
            FOR(i,l)
            {
                s[ts++] = s2[i];
                s[ts++] = s1[i];
            }
            s[l << 1] = 0;
            ans++;
            if(strcmp(s,s12) == 0) break;
            if(vis[s])
            {
                ans = -1;
                break;
            }
            vis[s] = 1;
            FOR(i,l) s1[i] = s[i];
            FOR(i,l) s2[i] = s[i + l];
        }
        printf("%d %d\n", CAS, ans);
    }
}
