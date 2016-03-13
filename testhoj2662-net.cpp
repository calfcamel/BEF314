#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
long long n,m,k,dp[82][22][1<<9],ans,mm;
long long mark[1<<9],len;
using namespace std;
long long num(long long x)
{
    long long sum=0;
    while(x)
    {
        if(x&1==1) sum++;
        x=x>>1;
    }
    return sum;
}
bool judge(long long x)
{
    if(x&(x<<1)) return false;
    return true;
}
int main()
{
    while(scanf("%lld %lld %lld",&n,&m,&k)!=EOF)
    {
        ans=0;
        memset(dp,0,sizeof(dp));
        memset(mark,0,sizeof(mark));
        len = 0;
        long long tmpp = n > m ? n : m;
        m = n > m ? m : n;
        n = tmpp;
        for(long long i=0; i<(1<<m); i++) if(judge(i))
            {
                dp[1][num(i)][len]=1;
                mark[len ++] = i;
            }
        for(long long i=2; i<=n; i++) for(long long j=0; j<=k; j++) for(long long x = 0 ; x < len ; x ++)
                {
                    for(long long y = 0 ; y < len ; y ++)
                    {
                        long long tmp = num (mark[x]);
                        if(((mark[x] & mark[y]) == 0 ) && j >= tmp) dp[i][j][x] += dp[i - 1][j - tmp][y];
                    }
                }
        for(long long i=0; i< len; i++) ans += dp[n][k][i];
        printf("%lld\n",ans);
    }
    return 0;
}
