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


const int MAXN = 200000 + 5;

int aa[11][11][11];
int cc[11][11][11];
int bb[11][11];
void add(int x)
{
    int last = x % 10;
    int now;
    x = x / 10;
    for(int ii = 0; ii < 9; ii++)
    {
        now = x % 10;
        aa[ii][last][now] ++;
        bb[ii][now]++;
        x = x / 10;
        last = now;
    }
}

void display_aa()
{
    for(int k = 0; k < 8; k++)
    {
        cout << "ceng " << k << endl;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
                cout << aa[k][i][j] << " ";
            cout << endl;
        }
        cout << endl << endl;
    }
}
int a[MAXN];
LL ans;
void dfs(int i, int x, int ad)
{
//    cout << "dfs " << i << " " << x << " " << ad << endl;
    if(i >= 9) return;
    if(x == 0 && ad == 0) return;
    int need = 10 - x % 10 - ad;
    x = x / 10;
    int boo = 0;
//    for(int k = 0; k < need ; k++)
//        cout << "\tign " << i << " " << k << " " << bb[i][k] << endl;
    for(int k = 0; k < 10; k++)
        for(int j = 0; j < 10; j++)
            aa[i + 1][k][j] = 0;
    for(int k = need; k < 10; k++)
    {
//        cout << "\tadd " << i << " " << k << " " << bb[i][k] << endl;
        for(int j = 0; j < 10; j < ++)
        {
            ans += aa[i][k][j];
            boo |= aa[i][k][j];

        }
    }
    if(boo) dfs(i + 1, x, 1);
    int boo2 = 0;
    for(int k = 0; k < need; k++)
        boo2 |= bb[i][k];
    if(boo2) dfs(i + 1, x, 0);
}
int cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        clr(aa,0);
        clr(bb,0);
        clr(cc,0);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a + n, cmp);
        ans = 0;
        add(a[0]);
        for(int i = 1; i < n; i++)
        {
            //display_aa();
            dfs(0,a[i],0);
//            cout << "ans = " << ans << endl;
            add(a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
