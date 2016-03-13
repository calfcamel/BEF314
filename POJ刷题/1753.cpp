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
typedef pair<LL, LL> PII;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define REP(i,x,y) for(int i = x; i <= (int) (y) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
#define LL long long
const int MAX16 = 1 << 16;
int dp[MAX16];
queue<int> q;
char s[10];
int rules[16];
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
int vis[MAX16];
#define hefa(x,y) (x >= 0 && y >= 0 && x < n && y < n)
int main()
{
    int n = 4;
    int t = 0;
    int init = 0;
    FOR(i,n)
    {
        scanf("%s",s);
        FOR(j,n)
        {
            int tmp = 0;
            if(s[j] == 'b') tmp = 1;
            init += tmp * (1 << t);
            t++;
        }
    }
//    dbg(init);
    clr(vis,0);
    while(!q.empty()) q.pop();
    q.push(init);
    vis[init] = 1;
    int qipan[4][4];
    FOR(r,16)
    {
        int rule = 0;
        int x = r / 4;
        int y = r % 4;
        clr(qipan,0);
        qipan[x][y] = 1;
        FOR(d,4) if(hefa(x + dx[d], y + dy[d])) qipan[x + dx[d]][y + dy[d]] = 1;
        int t = 0;
        FOR(i,n) FOR(j,n)
        {
            rule += qipan[i][j] * (1 << t);
            t++;
        }
        rules[r] = rule;
    }
//    FOR(i, 16) cout << rules[i] << endl;
    while(!q.empty())
    {
        int now = q.front();
        int foot = vis[now];
        if(now == 0 || now + 1 == (1 << 16))
        {
            cout << foot - 1<< endl;
            return 0;
        }
        q.pop();
        FOR(i, 16) if(!vis[now ^ rules[i]])
        {
            vis[now ^ rules[i]] = foot + 1;
            q.push(now ^ rules[i]);
        }
    }
    puts("Impossible");
    return 0;
}
