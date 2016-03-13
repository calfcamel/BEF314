#line 84 "CombiningSlimes.cpp"
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
class CombiningSlimes {
	public:
	int maxMascots(vector <int> a) {
        int n = a.SZ;
        int ret = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++) ret += a[i] * a[j];
        return ret;
    }
};
