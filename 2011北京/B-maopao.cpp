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
#define eps 1e-8

struct tri
{
    double tht[3];
} t[900];
int tnum;
struct point
{
    double x,y;
} p[20];
bool viss[303][303];
vector <point>p2;
int n2;
double cal(double x)
{
    return x*x;
}
double dist(point a,point b)
{
    return sqrt(cal(a.x-b.x)+cal(a.y-b.y));
}
int n;
double xmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
bool check2(tri a,tri b)
{
    if(fabs(a.tht[0]-b.tht[0])<=eps&&fabs(a.tht[1]-b.tht[1])<=eps)
        return true;
    return false;
}
bool vis[900];
int main()
{
    while(scanf("%d",&n),n)
    {
        memset(viss,0,sizeof(viss));
        p2.clear();
        tnum=0;
        for(int i=0; i<n; i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            if(viss[150+(int)p[i].x][150+(int)p[i].y])
                ;
            else
            {
                viss[150+(int)p[i].x][150+(int)p[i].y]=1;
                p2.push_back(p[i]);
            }
        }
        int n2=p2.size();
        for(int i=0; i<n2; i++)
        {
            for(int j=i+1; j<n2; j++)
            {
                for(int k=j+1; k<n2; k++)
                {
                    if(fabs(xmult(p[j],p[k],p[i]))<=eps)
                        continue;

                    double a=dist(p[i],p[j]);
                    double b=dist(p[i],p[k]);
                    double c=dist(p[j],p[k]);
                    t[tnum].tht[0]=(cal(b)+cal(c)-cal(a))/b/c;
                    t[tnum].tht[1]=(cal(b)+cal(a)-cal(c))/a/b;
                    t[tnum].tht[2]=(cal(a)+cal(c)-cal(b))/a/c;
                    sort(t[tnum].tht,t[tnum].tht+3);
                    tnum++;
                }
            }
        }
        int ans=0;
        for(int i=0; i<tnum; i++)
        {
            int tmp=0;
            for(int j=i; j<tnum; j++)
            {
                if(check2(t[i],t[j]))
                {
                    tmp++;
                    ans=max(ans,tmp);
                }
            }
            ans=max(ans,tmp);
        }
        printf("%d\n",ans);
    }
    return 0;
}
