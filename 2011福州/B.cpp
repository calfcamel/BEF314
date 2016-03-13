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
#include <iomanip>
//using namespace std;
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
#define dbg(x) std::cerr <<#x<<" = " << x << std::endl
#define all(x) x.begin(), x.end()
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
//typedef std::pair<LL, LL> PII;
typedef std::pair<LL, LL> PII;
#define FOR(i,x) for(LL i = 0, _END_ = (LL)(x); i < _END_ ; i++)
#define REP(i,x,y) for(LL i = x,  _END_ = (LL)(y); i <= _END_ ; i++)
#define REP_D(i,x,y) for(LL i = x,  _END_ = (LL)(y); i >= _END_ ; i--)
#define FORR(i,x) for(LL i = 1; i <= (LL) (x) ; i++)

LL isLeapYear(LL y)
{
    if(y % 400 == 0) return 1;
    if(y % 100 == 0) return 0;
    if(y % 4 == 0) return 1;
    return 0;
}
const LL days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
LL daysofyear[10000];
LL daysofmonth[13];
void init()
{
    clr(daysofyear, 0);
    REP(y, 2000, 9999)
        if(isLeapYear(y)) daysofyear[y] = 366; else daysofyear[y] = 365;
    REP(y, 2000, 9999) daysofyear[y] += daysofyear[y - 1];
    daysofmonth[0] = 0;
    REP(m, 1, 12) daysofmonth[m] = daysofmonth[m - 1] + days[m];
}
LL getdays(LL y, LL m, LL d)
{
    LL add = 0;
    if(m > 2 && isLeapYear(y)) add = 1;
    return daysofyear[y - 1] + daysofmonth[m - 1] + d - 1 + add;
}
LL gethours(LL y, LL m, LL d, LL h)
{
    if(y < 2000) return 0;
    return getdays(y,m,d) * 24 + h + 1;
}
char str[10];
LL getmonth()
{
    if(strcmp(str,"Jan") == 0) return 1;
    if(strcmp(str,"Feb") == 0) return 2;
    if(strcmp(str,"Mar") == 0) return 3;
    if(strcmp(str,"Apr") == 0) return 4;
    if(strcmp(str,"May") == 0) return 5;
    if(strcmp(str,"Jun") == 0) return 6;
    if(strcmp(str,"Jul") == 0) return 7;
    if(strcmp(str,"Aug") == 0) return 8;
    if(strcmp(str,"Sep") == 0) return 9;
    if(strcmp(str,"Oct") == 0) return 10;
    if(strcmp(str,"Nov") == 0) return 11;
    if(strcmp(str,"Dec") == 0) return 12;
}
LL a[25001];
LL b[25001];
LL cost[200005];
LL c[100005];
std::deque<PII> Q;
int main()
{
//    int tmpy;
//    while(~scanf("%d",&tmpy))
//    {
//        std::cout << isLeapYear(tmpy) << std::endl;
//    }
    init();
    LL N,M;
    while(~scanf("%I64d%I64d",&N,&M))
    {
        if(N == 0 && M == 0) return 0;
        LL d,y,h,cnt,m;
        bool flag = false;
        FOR(i,N)
        {
            scanf("%s%I64d%I64d%I64d%I64d", str, &d, &y, &h, &cnt);
            m = getmonth();
            a[i] = gethours(y,m,d,h);
            if(y < 2000) flag = true;
//            dbg(a[i]);
            b[i] = cnt;
        }
        LL T;
        LL S;
        scanf("%I64d%I64d",&T,&S);
        FORR(i,M) scanf("%I64d", &c[i]);
        FORR(i,M) c[i] -= S * i;
        cost[0] = 0;
        while(!Q.empty()) Q.pop_front();
        clr(cost,0);
        REP(i,1,M + T)
        {
            if(i <= M)
            {
                while(!Q.empty() && Q.back().AA >= c[i]) Q.pop_back();
                Q.push_back(std::MP(c[i],i));
            }
            while(!Q.empty() && Q.front().BB < i - T) Q.pop_front();
            cost[i] = c[Q.front().BB] + S * i;
//            std::cout << "COST " << i << " = " << cost[i] << std::endl;
        }
        LL ans = 0;
        FOR(i,N) //if(a[i] <= M + T && a[i] > 0)
            ans += b[i] * cost[a[i]];
//        FOR(i,N) std::cout << "A" << i << " = " << a[i] << std::endl;
//        dbg(ans);
//        if(flag) ans = 0;
//        FOR(i,N) if(a[i] > M) ans = 0;
        printf("%I64d\n", ans);
    }
}
