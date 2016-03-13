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

set<long long> s;
const int dis = 2000;
const int MAXN = 20000000;
long long f[10000 + 1];
long long now,a,b,c;

int main()
{
    #ifdef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    now = 1;
    s.clear();
    cin >> a >> b >> c;
    f[0] = 1;
    s.insert(f[0]);
    for(int i = 1; i <= MAXN; i++)
    {
        now = (a * now + now % b) % c;
        if(s.find(now) != s.end())
        {
            dbg(i);
            int j;
            for(j = 0; j <= 10000; j++) if(f[j] == now) break;
            j--; if(j < 0) j = 0;
            LL tmp = f[j];
            for(int k = j * 2000; k <= (j + 1) * 2000; j++)
            {
                tmp = (a * tmp + tmp % b) % c;
                s.insert(tmp);
            }
            i = i - i % 2000;
            i = i / 2000;
            i = i - 1;
            if(i < 0) i = 0;
            now = f[i];
            i = i * 2000;
            while(1)
            {
                i++;
                now = (a * now + now % b) % c;
                if(s.find(now) != s.end())
                {
                    cout << i << endl;
                    return 0;
                }
            }
        }
        if(i % dis == 0)
        {
            f[i / dis] = now;
            s.insert(now);
        }
    }
    puts("-1");
    return 0;
}


