#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int Maxn = 500000 * 2;
#define clr(a,b) memset(a,b,sizeof(a))
struct node {
    int now;
    int pre;
}nodes[Maxn];
int pa[Maxn];
int pd[Maxn];
char s[10];
int x,y;
int tot;
void add(int x,int y)
{
    nodes[tot].now = y;
    nodes[tot].pre = pa[x];
    pa[x] = tot;
    tot++;
}
void del(int x,int y)
{
    nodes[tot].now = y;
    nodes[tot].pre = pd[x];
    pd[x] = tot;
    tot++;
}
int main() {
//    freopen("input.txt", "r", stdin);
    tot = 0;
    int n,m;
    scanf("%d%d", &n, &m);
    clr(pa, -1);
    clr(pd, -1);
    int totjq = 1;
    for(int iii = 0; iii < n; iii++)
    {
        scanf("%s",s);
        if(s[0] == 'l')//learn
        {
            scanf("%d%d",&x,&y);
            add(x,y);
            pd[x] = -1;
//            cout << "ADD" << x << y << endl;
        }
        if(s[0] == 'r' && s[1] == 'o')// rollback
        {
            scanf("%d",&x);
            if(pa[x] != -1)
            {
                int tmp = nodes[pa[x]].now;
                pa[x] = nodes[pa[x]].pre;
                del(x, tmp);
            }
        }
        if(s[0] == 'r' && s[1] == 'e')// relearn
        {
            scanf("%d",&x);
            if(pd[x] != -1)
            {
                add(x,nodes[pd[x]].now);
                pd[x] = nodes[pd[x]].pre;
            }
        }
        if(s[0] == 'c' && s[1] == 'h')// check
        {
            scanf("%d",&x);
            if(pa[x] == -1) puts("basic");
            else printf("%d\n", nodes[pa[x]].now);
        }
        if(s[0] == 'c' && s[1] == 'l')// clone
        {
            totjq++;
            scanf("%d",&x);
            pa[totjq] = pa[x];
            pd[totjq] = pd[x];
        }
    }
    return 0;
}
