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
const double eps = 1e-9;
const int MAXN = 100000 + 5;
int f[MAXN];
int tot;
struct edge
{
    int v;
    int next;
}e[MAXN];
int vis[MAXN];
void add(int u,int v)
{
    e[tot].v = v;
    e[tot].next = f[u];
    f[u] = tot;
    tot++;
}
int totdfs;
int arr[MAXN];
int dfstime;
int T[MAXN];
void dfs(int i)
{
    vis[i] = 1;
    T[i] = dfstime++;
    int next = f[i];
    while(next != -1)
    {
        if(!vis[e[next].v]) dfs(e[next].v);
        next = e[next].next;
    }
    arr[totdfs++] = i;
}
double K[MAXN];
double E[MAXN];
double A[MAXN];
double B[MAXN];
double C[MAXN];
int con[MAXN];
inline bool isLeave(int i)
{
    return con[i] == 1;
}
int main()
{
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        int n;
        scanf("%d",&n);
        int x,y;
        tot = 0;
        clr(f,-1);
        clr(con,0);
        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
            con[x]++;
            con[y]++;
        }
//        for(int i = 1; i <= n; i++)
//            cout << "con[" << i << "] = " << con[i] << endl;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d",&x,&y);
            K[i] = (double)x / 100.00;
            E[i] = (double)y / 100.00;
        }
        clr(vis,0);
        totdfs = 0;
        dfstime = 0;
        dfs(1);
        for(int ii = 0; ii < n; ii++)
        {
            int i = arr[ii];
//            cout << "NODE " << i << " :" << endl;
            if(isLeave(i))
            {
                A[i] = K[i];
                B[i] = C[i] = 1.0 - K[i] - E[i];
            }
            else
            {
                double p = (1.0 - K[i] - E[i]) / (double) con[i];
                A[i] = K[i];
                B[i] = p;
                C[i] = 1.0 - K[i] - E[i];
                double divB = 1.0;
                int next = f[i];
                while(next != -1)
                {
                    if(T[e[next].v] > T[i])
                    {
                        A[i] += p * A[e[next].v];
                        C[i] += p * C[e[next].v];
                        divB -= p * B[e[next].v];
                    }
                    next = e[next].next;
                }
//                cout << "\t" << "A[i] = " << A[i] << endl;
//                cout << "\t" << "B[i] = " << B[i] << endl;
//                cout << "\t" << "C[i] = " << C[i] << endl;
                if(divB > eps)
                {
                    A[i] /= divB;
                    B[i] /= divB;
                    C[i] /= divB;
                }
//                cout << "\t" << "p = " << p << endl;
//                cout << "\t" << "divB = " << divB << endl;
            }
//            cout << "\t" << "A[i] = " << A[i] << endl;
//            cout << "\t" << "B[i] = " << B[i] << endl;
//            cout << "\t" << "C[i] = " << C[i] << endl;
        }
        double divB = 1.0;
        double ans = 1.0;
        int next = f[1];
        double p = 1.0 / (double) con[1];
        while(next != -1)
        {
            ans += p * C[e[next].v];
            divB -= p * B[e[next].v];
            divB -= p * A[e[next].v];
            next = e[next].next;
        }
//        cout << "ans = " << ans << endl;
//        cout << "divB = " << divB << endl;
//        cout << "ans2 = " << C[1] / ( 1.0 - A[1]) << endl;
        printf("Case %d: ",CAS);
        if(divB < eps)
        {
            puts("impossible");
        }
        else
        {
            ans /= divB;
            printf("%.10lf\n",ans);
        }
    }
    return 0;
}
