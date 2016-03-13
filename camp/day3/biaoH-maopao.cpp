#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
#define eps 1e-8

bool vis[50000005];
int n;
int solve(int x)
{
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=ans+x%i;
    return ans;
}
int main()
{
    int ans=0;
    scanf("%d",&n);
    for(int i=0;i<n*(n-1)/2;i++)
    {
        if(vis[i])
            continue;
        int slow=solve(i);
        int fast=solve(slow);
        int flag=0;
        while(slow!=fast)
        {
            slow=solve(slow);
            fast=solve(solve(fast));
        }
        int len=1;
        slow=solve(slow);
        fast=solve(solve(fast));
        while(slow!=fast)
        {
            slow=solve(slow);
            fast=solve(solve(fast));
            len++;
        }
            ans=max(ans,len);
    }
    printf("%d\n",ans);
    return 0;
}
