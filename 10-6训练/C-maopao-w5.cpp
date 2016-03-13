#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>
#include <map>
using namespace std;
#define PII pair<int, int>
#define MP(a, b) make_pair(a, b)
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define PB(x) push_back(x)
#define SZ size()
#define LL long long
#define PB(x) push_back(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define u32 unsigned int
#define ONES(x) __builtin_popcount(x)

struct dice
{
    char str[10];
    int pos;
} d[10];
bool vis[10];
pair <dice,dice> p[3];
int nnn;
int main()
{
    freopen("cube.in","r",stdin);
    freopen("cube.out","w",stdout);
    for(int i=0; i<6; i++)
    {
        scanf("%s",d[i].str);
        sort(d[i].str+1,d[i].str+5);
    }
    for(int i=0; i<6; i++)
    {
        if(vis[i])
            continue;
        for(int j=0; j<6; j++)
        {
            if(i==j)
                continue;
            if(vis[j])
                continue;
            if(vis[i])
                break;
            if(strcmp(d[i].str+1,d[j].str+1)==0)
            {
//                printf("%d %d\n",i,j);
                vis[i]=1;
                vis[j]=1;
                p[nnn++]=make_pair(d[i],d[j]);
            }
        }
    }
//    printf("%d\n",nnn);
    if(nnn!=3)
    {
        printf("Impossible\n");
        return 0;
    }
    else
    {
//        for(int i=0;i<3;i++)
//        {
//            printf("%c %c\n",p[i].first.str[0],p[i].second.str[0]);
//        }

        for(int i=0; i<3; i++)
        {
            char tmp[10];
            int pos=0;
            for(int j=0; j<3; j++)
            {
                if(j==i)
                    continue;
//                printf("%d %d\n",i,j);
                tmp[pos++]=p[j].first.str[0];
                tmp[pos++]=p[j].second.str[0];
            }
            tmp[pos]='\0';
            sort(tmp,tmp+pos);
            if(strcmp(p[i].first.str+1,tmp)!=0)
            {
//                printf("%s %s\n",d[i].str,tmp);
                printf("Impossible\n");
                return 0;
            }
        }

        for(int i=0; i<3; i++)
        {
            if(p[i].first.str[0]==p[i].second.str[0])
            {
                printf("%c%c%c%c%c%c\n",p[0].first.str[0],p[1].first.str[0],p[2].first.str[0],p[1].second.str[0],p[2].second.str[0],p[0].second.str[0]);
                return 0;
            }
        }

        printf("%c%c%c%c%c%c\n",p[0].first.str[0],p[1].first.str[0],p[2].first.str[0],p[1].second.str[0],p[2].second.str[0],p[0].second.str[0]);
        printf("%c%c%c%c%c%c\n",p[0].first.str[0],p[2].first.str[0],p[1].first.str[0],p[2].second.str[0],p[1].second.str[0],p[0].second.str[0]);

    }
    return 0;
}
