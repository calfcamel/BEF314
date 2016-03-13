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
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;

int a[205];
int b[205];
int main()
{
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        int ans = 0;
        int n;
        int x;
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&x);
            ans += x;
        }
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
//        for(int i = 1; i <= n; i++)
//            ans += a[i] * 2;
//        ans -= a[n];
//        ans -= a[1];
        a[n + 1] = 0;
        a[0] = 0;
        clr(b,0);
        int maxn = 0;
        int maxi;
        int now;
        int j;
        int END;
        int tmp;
        int BEGIN;
        for(int k = 0; k < n; k++)
        {
            maxn = 0;
            j = n;
            while(b[j]) j--;
            END = j;
            j = 1;
            while(b[j]) j++;
            BEGIN = j;
            for(int i = 1; i <= n; i++)
            {
                tmp = a[i];
                if(i != END && i != BEGIN) tmp *= 2;
                if(!b[i] && tmp > maxn)
                {
                    maxn = tmp;
                    maxi = i;
                }

            }
//            b[maxi] = 1;
//            ans -= maxn;
            if(a[j] == maxn) maxi = j;
            now = 0;
            j = maxi - 1;
            while(b[j]) j--;
            now = a[j];
            j = maxi + 1;
            while(b[j]) j++;
            now += a[j];
            b[maxi] = 1;
            ans += now;
            cout << "del " << maxi << " now = " << now << endl;
        }
        printf("Case #%d: ",CAS);
        printf("%d\n",ans);
    }
    return 0;
}
