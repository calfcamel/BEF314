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
#define all(x) x.begin(),x.end()

const int MAXN = 100000 + 5;


map <int,int>mm;
vector <int> has;
vector <int> ans;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    int k = 0;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n*n;i++)
    {
        int t;
        k++;
        scanf("%d",&t);
        if(!mm[t])
            has.push_back(t);
        mm[t]++;
    }
    sort(all(has));
    reverse(all(has));
    for(int i=1;i*i<=mm[has[0]];i++)
    {
        ans.push_back(has[0]);
    }
    mm[has[0]]=0;
    for(int i=1;i<has.size();i++)
    {
        if(mm[has[i]]==0)
            continue;
        else
        {
            while(mm[has[i]]!=0)
            {

                for(int j=0;j<ans.size();j++)
                    mm[gcd(ans[j],has[i])]-=2;
                mm[has[i]]--;
                ans.push_back(has[i]);
            }
        }
    }
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    puts("");
    return 0;
}
