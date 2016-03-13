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
#define all(x) x.begin(),x.end()
const int MAXN = 100000 + 5;

vector<pii> vn,vm;
multiset<int> ST;
int main()
{
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        int ans = 0;
        int n,m;
        scanf("%d%d",&n,&m);
        vn.clear();
        vm.clear();
        ST.clear();
        int x,y;
        FOR(i,n)
        {
            scanf("%d%d",&x,&y);
            vn.PB(MP(-x,y));
        }
        FOR(i,m)
        {
            scanf("%d%d",&x,&y);
            vm.PB(MP(-y,x));
        }
        sort(all(vn));
        sort(all(vm));
        FOR(i,n) vn[i].AA = -vn[i].AA;
        FOR(i,m) vm[i].AA = -vm[i].AA;
        int atk,def;
        if(m > n) ans = -1;
        else
        {
            vector<pii>::iterator itvn = vn.begin();
            set<int>::iterator itST;
            FOR(i,m)
            {
                atk = vm[i].BB;
                def = vm[i].AA;
                while(itvn != vn.end() && (*itvn).AA > def)
                {
                    ST.insert((*itvn).BB);
//                    cout << "ADD " << (*itvn).BB << endl;
                    itvn++;
                }
                if(ST.empty()){ans = -1; break;}
                itST = ST.lower_bound(atk);
                if(itST != ST.end())
                {
                    ans ++;
//                    cout << "ERA " << (*itST) << endl;
                    ST.erase(itST);
                }
                else
                {
//                    cout << "ERA BEG " << (*ST.begin()) << endl;
                    ST.erase(ST.begin());
                }
            }
        }
        if(~ans) ans = ans + n - m;
        printf("Case #%d: %d\n",CAS,ans);
    }
    return 0;
}
