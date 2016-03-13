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
const LL mod = 20140518;


const int MAXN = 10000 + 5;

struct matrix
{
    long long num[10][10];
} m,E;
int n;
matrix mult(matrix a,matrix b)
{
    matrix c;
    memset(c.num,0,sizeof(c.num));
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                c.num[i][j]+=a.num[i][k]*b.num[k][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            c.num[i][j]%=mod;
    return c;
}
matrix qpow(matrix x,LL t)
{
    matrix b = E;
    while (t > 0)
    {
        if (t & 1)
            b = mult(b,x);
        t = t >> 1 ;
        x = mult(x,x);
    }
    return b;
}
void putmatrix(matrix a)
{
    for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                printf("%lld ",a.num[i][j]);
            puts("");
        }
}

int main()
{
    clr(E.num, 0);
    for(int i = 0; i < 10; i++)
        E.num[i][i] = 1;
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        LL ans = 0;
        LL N,k;
        matrix a;
        matrix b;
        scanf("%lld%lld",&N,&k);
        k ++;
        n = k - 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                if(i == j) a.num[i][j] = 1;
                else if(i < j) a.num[i][j] = 0;
                else a.num[i][j] = 1;
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(j == i + 1) a.num[i][j] = k - j;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                b.num[i][j] = 0;
        b.num[0][0] = k;
       // putmatrix(a);
        matrix c = qpow(a,N - 1);
        matrix d = mult(b,c);
       // putmatrix(c);
        for(int i = 0; i < n; i++)
            ans += d.num[0][i];
        //putmatrix(d);
        printf("Case #%d: %lld\n",CAS,ans % mod);
    }
    return 0;
}
