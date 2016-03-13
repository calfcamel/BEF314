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
const int MAXN = 501;
int getdeep(int x)
{
    int d = 0;
    while(x)
    {
        x >>= 1;
        d++;
    }
    return d;
}
vector<int> v;
bool chkans(int a,int b)
{
    if(a == b) return false;
    if(b > a) swap(a,b); // a > b
    while(a)
    {
        if(a == b) return false;
        a >>= 1;
    }
    return true;
}
bool chk(int a, int b)
{
    while(a)
    {
        a >>= 1;
        if(a == b) return true;
    }
    return false;
}
int a,b;
void gao(int i, bool ba, bool bb)
{
//    cout << i << " " << ba << " " << bb << endl;
//    int l = v.SZ - 1;
//    FOR(i,l) printf("%d ", v[i]);
//    printf("%d\n",v[l]);
    if(ba && bb && a / 2 == i && b / 2 == i)
    {
        v.PB(i * 2);
        v.PB(i * 2 + 1);
        return;
    }
    if(a / 2 == i && !bb && ba)
    {
        v.PB(i * 2);
        v.PB(i * 2 + 1);
        return;
    }
    if(b / 2 == i && !ba && bb)
    {
        v.PB(i * 2);
        v.PB(i * 2 + 1);
        return;
    }
    if(a / 2 == i && bb && ba)
    {
        v.PB(a);
        gao(a / 2 * 2 + ((a & 1) ^ 1), false, true);
        return;
    }
    if(b / 2 == i && ba && bb)
    {
        v.PB(b);
        gao(b / 2 * 2 + ((b & 1) ^ 1), true, false);
        return;
    }
//    cout << "hi" << endl;
    bool la;
    if(ba) la = chk(a,i * 2);
    bool lb;
    if(bb) lb = chk(b,i * 2);
//    cout << "hi" << endl;
    if(ba && bb)
    {
        if(la && lb)
        {
            v.PB(i * 2 + 1);
            gao(i * 2, true, true);
            return;
        }
        if(!la && lb)
        {
            gao(i * 2 + 1, true, false);
            gao(i * 2, false, true);
            return;
        }
        if(la && !lb)
        {
            gao(i * 2, true, false);
            gao(i * 2 + 1, false, true);
            return;
        }
        if(!la && !lb)
        {
            v.PB(i * 2);
            gao(i * 2 + 1, true, true);
            return;
        }
    }
    int tmp = 0;
    if(ba && !bb)
    {
        if(la) tmp = 1;
        v.PB(i * 2 + tmp);
        gao(i * 2 + (tmp ^1), true, false);
        return;
    }
    if(bb && !ba)
    {
        if(lb) tmp = 1;
        v.PB(i * 2 + tmp);
        gao(i * 2 + (tmp ^1), false, true);
    }
    return;
}
int main()
{
    v.clear();
    cin >> a >> b;
    int da = getdeep(a);
    int db = getdeep(b);
    if(!chkans(a,b))
    {
        puts("-1");
        return 0;
    }
    gao(1,true,true);
    int l = v.SZ - 1;
    sort(all(v));
    FOR(i,l) printf("%d ", v[i]);
    printf("%d\n",v[l]);
}
