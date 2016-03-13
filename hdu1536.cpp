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


//注意 S数组要按从小到大排序 SG函数要初始化为-1 对于每个集合只需初始化1遍
//n是集合s的大小 S[i]是定义的特殊取法规则的数组
int s[110],sg[10010],n;
int SG_dfs(int x)
{
    int i;
    if(sg[x]!=-1)
        return sg[x];
    bool vis[110];
    memset(vis,0,sizeof(vis));
    for(i=0;i<n;i++)
    {
        if(x>=s[i])
        {
            SG_dfs(x-s[i]);
            vis[sg[x-s[i]]]=1;
        }
    }
    int e;
    for(i=0;;i++)
        if(!vis[i])
        {
            e=i;
            break;
        }
    return sg[x]=e;
}
const int MAXN = 10000 + 5;

int main()
{
    int q,k,x;
    int ans;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0) return 0;
        for(int i = 0; i < n; i++) scanf("%d",&s[i]);
        sort(s,s + n);
        scanf("%d",&q);
        clr(sg,-1);
        for(int i = 0; i < q; i++)
        {
            ans = 0;
            scanf("%d",&k);
            for(int i = 0; i < k; i++)
            {
                scanf("%d",&x);
                ans ^= SG_dfs(x);
            }
            if(ans) printf("W");
            else printf("L");
        }
        printf("\n");
    }
    return 0;
}
