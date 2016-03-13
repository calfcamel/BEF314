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

#define clr(a,b) memset(a,b,sizeof(a))
const int MAXN = 50000 + 5;
const LL MOD = 1000000000 + 7;

int main()
{
    LL n;
    cin >> n;
    LL ans = 0;
    LL now = n;
    LL left = n;
    LL last = n;
    for(LL i = 1; i <= 1000000LL; i++)
    {
        LL tmp = n / (i + 1);
        ans = (ans + sigma( ,last))
    }
}
