#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
//#include <unordered_map>
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
#define dbg(x) cerr <<#x<<" = " << x << endl
#define all(x) x.begin(), x.end()
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int MAXN = 200000 + 5;
const int N = 60;
LL inv[N];
void init()
{
    inv[0] = inv[1] = 1;
    for(int i = 2; i < N; i++)
        inv[i] = ((MOD - MOD / i) * inv[MOD % i]) % MOD;
}
int n,m;
int x,y;
vector<int> v[N];
int q;

///temp

struct Mat{
    int mat[N][N];
}E;
//初始化单位矩阵
Mat init(){
    Mat E;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j)
            E.mat[i][i] = 1;
            else
            E.mat[i][j] = 0;
        }
    }
    return E;
}
//重载乘法
Mat operator *(Mat a,Mat b){
    Mat c;
    memset(c.mat,0,sizeof(Mat));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(a.mat[i][k] && b.mat[k][j]){
                    c.mat[i][j] += a.mat[i][k] * b.mat[k][j] % MOD;
                }
            }
        }
    }
    return c;
}
//重载加法
Mat operator +(Mat a,Mat b){
    Mat c;
    memset(c.mat,0,sizeof(Mat));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c.mat[i][j] = (a.mat[i][j] + b.mat[i][j]) % MOD;
        }
    }
    return c;
}
//矩阵快速幂
Mat operator ^(Mat A,int x){
    Mat c;
    c = init();
    for(; x ; x >>= 1){
        if(x&1){
            c = c*A;
        }
        A = A*A;
    }
    return c;
}

///end
int main()
{
    FOR(i,N) v[i].clear();
    init();
    scanf("%d%d",&n,&m);
    FOR(i,m)
    {
        scanf("%d%d",&x,&y);
        v[x].PB(y);
    }
    scanf("%d",&q);
    FOR(i,q)
    {
        scanf("%d%d",&x,&y);
        ///gao
        ///output
    }
}
