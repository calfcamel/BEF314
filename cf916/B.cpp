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
typedef pair<int, int> PII;

const int MAXN = 10000 + 5;

vector<pair<int, PII> > V;
int ans[810];
int main()
{
    int n;
    int x;
    scanf("%d",&n);
    n *= 2;
    V.clear();
    for(int i = 2; i <= n; i++)
        for(int j = 1; j < i; j++)
        {
            scanf("%d",&x);
            V.push_back(MP(-x,MP(i,j)));
        }
    sort(V.begin(),V.end());
    clr(ans,0);
    for(vector<pair<int, PII> > ::iterator it = V.begin(); it != V.end(); it++)
    {
        if(ans[it->second.second] == 0 && ans[it->second.first] == 0)
        {
            ans[it->second.second] = it->second.first;
            ans[it->second.first] = it->second.second;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(i != 1) printf(" ");
        printf("%d",ans[i]);
    }
    puts("");
    return 0;
}
