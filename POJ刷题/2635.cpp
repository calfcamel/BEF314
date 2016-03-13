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
const int SIZE = 1000000;
bool isprime[SIZE];
int prime[SIZE],prinum = 0;
void getprime()//prime
{
    isprime[0]=1;
    isprime[1]=1;
    for(int i=2; i<SIZE; i++)
    {
        if(!isprime[i])
        {
            prime[prinum++]=i;
//            if(i < 100) dbg(prime[prinum - 1]);
        }
        for(int j=0; j<prinum; j++)
        {
            if(i*prime[j]>SIZE)
                break;
            isprime[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
int init()
{
    getprime();
    prime[0] = 2;
//    FOR(i,10) cout << prime[i] << endl;
}
char str[105];
int L;
bool chk(LL mod)
{
    LL now = 0;
    for(int i = 96; i >= 0; i -= 4)
    {
        now *= 10000;
        if(str[i + 3]) now += 1000 * (str[i + 3] - '0');
        if(str[i + 2]) now += 100 * (str[i + 2] - '0');
        if(str[i + 1]) now += 10 * (str[i + 1] - '0');
        if(str[i]) now += 1 * (str[i] - '0');
//        dbg(now);
        now %= mod;
    }
    return now == 0;
}
void gao()
{
    FOR(i,prinum)
    {
        if(prime[i] >= L) break;
        if(chk(prime[i]))
        {
            printf("BAD %d\n",prime[i]);
            return;
        }
    }
    puts("GOOD");
}
int main()
{
    init();
    clr(str,0);
    while(~scanf("%s%d",str,&L))
    {
        int l = strlen(str);
        reverse(str, str + l);
        if(str[0] == '0' && L == 0) return 0;
        gao();
        clr(str,0);
    }
}
