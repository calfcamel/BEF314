
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
int n,k;
vector<pii> v;
vector<pii> ans;
vector<pii> z_ans;
priority_queue<int> Q;
int ceng;
int bef;
void quit(int x)
{
    while(!Q.empty() && -Q.top() < x)
    {
        if(ceng == k)
        {
            ans.PB(MP(bef,-Q.top()));
        }
        Q.pop();
        ceng--;
    }
}
void addleft(int x)
{
    ceng++;
    if(ceng == k) bef = x;
}
void addright(int x)
{
    Q.push(-x);
}
int main()
{
    scanf("%d%d",&n,&k);
    int x,y;
    FOR(i,n)
    {
        scanf("%d%d",&x,&y);
        if(x != y) v.PB(MP(x,y));
    }
    sort(all(v));
    n = v.SZ;
    ans.clear();
    ceng = 0;
    FOR(i,n)
    {
        quit(v[i].AA);
        addleft(v[i].AA);
        addright(v[i].BB);
    }
    quit(1000000001);
    n = ans.SZ;
    if(n == 0)
    {
        puts("0");
        return 0;
    }
    z_ans.clear();
    int tot = 0;
    FOR(i,n)
    {
        if(tot == 0)
        {
            z_ans.PB(ans[i]);
            tot++;
        }
        else
        {
            if(z_ans[tot - 1].BB >= ans[i].AA)
            {
                cmax(z_ans[tot - 1].BB, ans[i].BB);
            }
            else
            {
                z_ans.PB(ans[i]);
                tot++;
            }
        }
    }
    printf("%d\n",tot);
    FOR(i,tot)
    {
        printf("%d %d\n",z_ans[i].AA, z_ans[i].BB);
    }
    return 0;
}
