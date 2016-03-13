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


const int MAXN = 10000 + 5;

int sg[2005][2005];
int _hash[2];
void GETSG(int n)
{
    clr(sg,0);
    for(int i = 0; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(j == 0) continue;
            clr(_hash, 0);
            for(int k = 1; k <= i; k++)
                _hash[sg[i - k][j - k]] = 1;
            for(int k = 1; k <= i; k++)
                _hash[sg[i - k][j]] = 1;
            for(int k = 1; k <= j; k++)
                _hash[sg[i][j - k]] = 1;
            sg[i][j] = _hash[0];
            sg[j][i] = _hash[0];
//            for(int k = 0; 1; k++)
//            {
//                if(!_hash[k])
//                {
//                    sg[i][j] = k;
//                    sg[j][i] = k;
//                    if(k == 0)
//                        cout << i << " " << j << " " << k << endl;
//                    break;
//                }
//            }
        }
    }
}
int main()
{
    GETSG(2000);

    return 0;
}

