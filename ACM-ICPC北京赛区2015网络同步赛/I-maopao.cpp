#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define SIZE 100000005
#define MOD 5

int ans[515][2105];
int len[515];
void init1(int pos)
{

    for(int k=1; k<=pos; k++)
    {
        int num=k;
        for(int i=1; i<num; i++)
        {
            ans[2*num-1][len[2*num-1]++]=i;
            ans[2*num-1][len[2*num-1]++]=num;
        }
        ans[2*num-1][len[2*num-1]++]=num;
        ans[2*num-1][len[2*num-1]++]=num;
        for(int i=1; i<num; i++)
        {
            ans[2*num-1][len[2*num-1]++]=num;
            ans[2*num-1][len[2*num-1]++]=num-i;
        }
    }
}
void init2(int l,int r,int h,int num,int flag)
{
    while(num)
    {
        if(flag==0)
        {
            for(int i=1; i<=h; i++)
            {
                ans[num][len[num]++]=i;
                ans[num][len[num]++]=r;
            }
            for(int i=h; i>=1; i--)
            {
                ans[num][len[num]++]=i;
                ans[num][len[num]++]=r-1;
            }
            r-=2;
            num-=2;
            flag^=1;
        }
        else
        {
            for(int i=l; i<=r; i++)
            {
                ans[num][len[num]++]=h;
                ans[num][len[num]++]=i;
            }
            for(int i=r; i>=l; i--)
            {
                ans[num][len[num]++]=h-1;
                ans[num][len[num]++]=i;
            }
            h-=2;
            num-=2;
            flag^=1;
        }
    }
}
void solve(int n)
{
//    printf("%d %d %d\n",n,(n+1)/2,n/2+1);
    init1((n+1)/2);
    if(n%2==1)
        init2(n/2+2,n,n/2+1,n-1,1);
    else
        init2(n/2+1,n+1,n/2,n,0);
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(ans,0,sizeof(ans));
        memset(len,0,sizeof(len));
        solve(n);
//        for(int i=1;i<=n;i++)
//        printf("%d\n",len[i]);
        printf("%d %d\n",(n+1)/2,n*(n+1)/2/((n+1)/2));
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<len[i]; j++)
                printf("%d ",ans[i][j]);
            printf("\n");
        }
    }
}

