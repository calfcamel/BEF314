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

const int N = 100000 + 5;
LL prime[N];
bool check[N];
void Eular()
{
    clr(check,false);
    int tot = 0;
    for (int i = 2; i < N; i++)
    {
        if (!check[i]) prime[tot++] = i;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] >= N) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int main()
{
    Eular();
    for(int i = 0 ; i <= 100; i++)
        cout << prime[i] % 7 << endl;
}
