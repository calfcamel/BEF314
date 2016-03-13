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
using namespace std;
#define eps 1e-5
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define zero(x) ((fabs(x))<eps)
#define sign(x) ((x)<-eps?-1:((x)>eps))

struct point
{
    double num;
    int pos;
} p[10005];
bool cmp(point a,point b)
{
    return a.num<b.num;
}
bool cmp2(point a,point b)
{
    return a.pos<b.pos;
}
vector <point>ans;
vector <point>fu,fu2;
vector <point>f1;
int numf=0;
int main()
{
    freopen("E.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%lf",&p[i].num);
        p[i].pos=(i+1);
    }
    sort(p,p+n,cmp);
    for(int i=0; i<n; i++)
    {
        if(p[i].num<-1)
            fu.push_back(p[i]);
        else if(p[i].num>-1&&p[i].num<0)
            fu2.push_back(p[i]);
        if(p[i].num==-1)
        {
            f1.push_back(p[i]);
            numf++;
        }
        if(p[i].num>1)
            ans.push_back(p[i]);
    }

//    for(int i=0;i<ans.size();i++)
//        printf("%d ",ans[i].pos);
//        printf("\n");

    if(fu.size()%2==0)
    {
        for(int i=0; i<fu.size(); i++)
            ans.push_back(fu[i]);
    }
    else
    {
        if(numf>0)
        {
            for(int i=0; i<fu.size(); i++)
                ans.push_back(fu[i]);
            ans.push_back(f1[0]);
        }
        else
        {
            if(fu2.size()>0)
            {
                if(fu2[0].num*fu[fu.size()-1].num>1)
                {
                    for(int i=0; i<fu.size(); i++)
                        ans.push_back(fu[i]);
                    ans.push_back(fu2[0]);
                }
                else
                {
                    for(int i=0; i<fu.size()-1; i++)
                        ans.push_back(fu[i]);
                }
            }
            else
            {
                for(int i=0; i<fu.size()-1; i++)
                    ans.push_back(fu[i]);
            }

        }
    }
//    printf("!\n");
    if(ans.size()==0)
    {
        if(p[n-1].num==1)
            ans.push_back(p[n-1]);
        else if(p[n-1].num>=0)
        {
            if(numf>1)
            {
                ans.push_back(f1[0]);
                ans.push_back(f1[1]);
            }
            else if(numf==1&&fu2.size()>0)
            {
                if(fu2[0].num*-1.0>p[n-1].num)
                {
                    ans.push_back(fu2[0]);
                    ans.push_back(f1[0]);
                }
                else
                    ans.push_back(p[n-1]);
            }
            else if(numf==1&&fu2.size()==0)
                ans.push_back(p[n-1]);
            else if(numf==0)
            {

                if(fu.size()>0&&fu2.size()>0&&fu[0].num*fu2[0].num>p[n-1].num)
                {
                    ans.push_back(fu[0]);
                    ans.push_back(fu2[0]);
                }
                else if(fu.size()==0&&fu2.size()>1&&fu2[0].num*fu2[1].num>p[n-1].num)
                {
                    ans.push_back(fu2[0]);
                    ans.push_back(fu2[1]);
                }
                else
                    ans.push_back(p[n-1]);
            }
            else
                ans.push_back(p[n-1]);
        }
        else
        {
            if(numf>1)
            {
//                ans.push_back(fu2[0]);
                ans.push_back(f1[0]);
                ans.push_back(f1[1]);
            }
            else if(numf==1&&fu2.size()>0)
            {
                ans.push_back(fu2[0]);
                ans.push_back(f1[0]);
            }
            else if(numf==1&&fu2.size()==0)
            {
                ans.push_back(f1[0]);
            }
            else
            {
                if(fu2.size()>1)
                {
                    ans.push_back(fu2[1]);
                    ans.push_back(fu2[0]);
                }
                else
                    ans.push_back(fu2[fu2.size()-1]);
            }
        }
    }
    sort(ans.begin(),ans.end(),cmp2);
    printf("%d\n",ans.size());
    for(int i=0; i<ans.size(); i++)
        printf("%d ",ans[i].pos);
    printf("\n");
    return 0;

}
