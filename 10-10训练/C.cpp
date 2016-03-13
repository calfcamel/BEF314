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
#define FOR(i,x) for(int i = 0; i < (int)(x); i++)
#define FORR(i,x) for(int i = 1; i <= (int)(x); i++)
#define dbg(x) cerr <<#x<<" = " << x << endl
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;


const int MAXN = 1000000 + 5;
typedef pair<int,int> pii;
vector<pii> V;
int n;
int a[MAXN];
int b[MAXN];
int f[MAXN];
LL ans[MAXN];
int quary,q;
int main()
{
    while(1)
    {
        scanf("%d",&n);
        if(n == 0) return 0;
        FOR(i,n) scanf("%d",&a[i]);
        clr(b, -1);
        clr(f, -1);
        V.clear();
        FOR(i,n)
        {
            if(~b[a[i]]) f[i] = i - b[a[i]];
            b[a[i]] = i;
        }
        for(int i = 0; i <= n; i++)
            cout << f[i] << " ";
        cout << endl;
        FOR(i,n) if(~f[i]) V.PB(MP(f[i],a[i]));
        sort(V.begin(),V.end());
        vector<pii>::iterator it = V.begin();
        LL dec = 0;
        LL sumdec = 0;
        FORR(i,n) ans[i] = (LL)i * (n - i + 1);

        for(int i = 0; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
        clr(b, -1);
        cout << "V:" << endl;
        FOR(i,V.SZ) cout << V[i].AA << " " << V[i].BB << endl;
        FORR(i,n)
        {
            //dec = 0;
            while(it != V.end() && (*it).AA == i - 1)
            {
                if(~b[(*it).BB])
                {
                    sumdec+=(*it).AA - b[(*it).BB];
                    b[(*it).BB] = (*it).AA;
                }
                else
                {
                    b[(*it).BB] = (*it).AA;
                    dec++;
                }
                it++;
            }
            dbg(dec);
            sumdec += dec;
            if(~f[i - 1]) dec--;
            ans[i] -= sumdec;
            cout << i << " " << dec << " " << sumdec << endl;
        }
        for(int i = 0; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
        scanf("%d",&q);
        FOR(i,q)
        {
            scanf("%d",&quary);
            printf("%d\n",ans[quary]);
        }
    }
    return 0;
}
