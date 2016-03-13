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


const int MAXN = 100000 + 5;

char str[MAXN];
int a[MAXN];
int aa[MAXN];
int bb[MAXN];
int b[MAXN];
LL f[MAXN];
LL g[MAXN];
int n;
void getstr(int* a)
{
    scanf("%s",str);
    n = strlen(str);
    if(str[0] == '0') a[0] = 0;
    else if(str[0] == '1') a[0] = 1;
    else a[0] == 2;
    for(int i = 1; i < n; i++)
    {
        if(str[i] == '0')
        {
            if(a[i - 1] == 0) a[i] = 0;
            else if(a[i - 1] == 1) a[i] = 1;
            else a[i] = 3;
        }
        if(str[i] == '1')
        {
            if(a[i - 1] == 0) a[i] = 1;
            else if(a[i - 1] == 1) a[i] = 0;
            else a[i] = 4;
        }
        if(str[i] == '?')
        {
            a[i] == 2;
        }
    }
}
int main()
{
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        LL ans = 0;
        getstr(a);
        getstr(b);
        clr(f,0);
        clr(g,0);
        if(a[0] == b[0] || a[0] == 2 || b[0] == 2) f[0] = 1;
        if(a[0] == 2 && b[0] == 2) f[0] = 2;
        aa[0] = a[0];
        bb[0] = b[0];
        if(aa[0] == 2) aa[0] = bb[0];
        if(bb[0] == 2) bb[0] = aa[0];
        for(int i = 1; i < n; i++)
        {
            f[i - 1] = f[i - 1] % MOD;
            if(f[i - 1] == 0) break;
            if(a[i] == 0)
            {
                if(b[i] == 0) { f[i] = f[i - 1] * 1; aa[i] = 0; bb[i] = 0;}
                else if(b[i] == 1) { f[i] = 0;}
                else if(b[i] == 2) { f[i] = f[i - 1] * 1; aa[i] = 0; bb[i] = 0;}
                else if(b[i] == 3)
                {
                    if(bb[i - 1] == 0 || bb[i - 1] == 2) { f[i] = f[i - 1] * 1; aa[i] = 0; bb[i] = 0;}
                    else {f[i] = 0;}
                }
                else if(b[i] == 4)
                {
                    if(bb[i - 1] == 1 || bb[i - 1] == 2) { f[i] = f[i - 1] * 1; aa[i] = 0; bb[i] = 1;}
                    else {f[i] = 0;}
                }
            }
            else if(a[i] == 1)
            {
                if(b[i] == 1) { f[i] = f[i - 1] * 1; aa[i] = 1; bb[i] = 1;}
                else if(b[i] == 0) { f[i] = 0;}
                else if(b[i] == 2) { f[i] = f[i - 1] * 1; aa[i] = 1; bb[i] = 1;}
                else if(b[i] == 4)
                {
                    if(bb[i - 1] == 0 || bb[i - 1] == 2) { f[i] = f[i - 1] * 1; aa[i] = 0; bb[i] = 0;}
                    else {f[i] = 0;}
                }
                else if(b[i] == 3)
                {
                    if(bb[i - 1] == 1 || bb[i - 1] == 2) { f[i] = f[i - 1] * 1; aa[i] = 0; bb[i] = 1;}
                    else {f[i] = 0;}
                }
            }
            else if(a[i] == 2)
            {
                if(b[i] == 0) { f[i] = f[i - 1] * 1; aa[i] = 0; bb[i] = 0;}
                else if(b[i] == 1) { f[i] = f[i - 1] * 1; aa[i] = 1; bb[i] = 1;}
                else if(b[i] == 2)
                {
                    if(aa[i - 1] == bb[i - 1] && aa[i - 1] == 2) {f[i] = f[i - 1] * 2; aa[i] = 2; bb[i] = 2;}
                    else if(aa[i - 1] == bb[i - 1]) {f[i] = f[i - 1] * 2; aa[i] = aa[i - 1]; bb[i] = bb[i - 1];}
                    else if(aa[i - 1] == 1 && bb[i - 1] == 2) {f[i] = 0;}
                    else if(aa[i - 1] == 2 && bb[i - 1] == 1) {f[i] = 0;}
                    else if(aa[i - 1] == 2) {f[i] = f[i - 1]; aa[i] = bb[i - 1]; bb[i] = bb[i - 1];}
                    else if(bb[i - 1] == 2) {f[i] = f[i - 1]; aa[i] = aa[i - 1]; bb[i] = aa[i - 1];}
                }
                else if(b[i] == 3)
                {
                    bb[i] = bb[i - 1];
                    aa[i] = bb[i - 1];
                    if(bb[i - 1] == 2) f[i] = f[i - 1] * 2;
                    else f[i] = f[i - 1] * 1;
                }
                else if(b[i] == 4)
                {
                    if(bb[i - 1] == 2) {f[i] = f[i - 1] * 2; aa[i] = 2; bb[i] = 2;}
                    else {f[i] = f[i - 1]; aa[i] = bb[i - 1] ^ 1; bb[i] = bb[i - 1] ^ 1;}
                }
            }
            else if(a[i] == 3)
            {
                aa[i] = aa[i - 1];
                if(b[i] == 0)
                {
                    if(aa[i] == 1) f[i] = 0;
                    else {aa[i] = bb[i - 1]; f[i] = f[i - 1] * aa[i]; bb[i] = bb[i - 1];}
                }
                if(b[i] == 1)
                {
                    if(aa[i] == 0) f[i] = 0;
                    else {aa[i] = bb[i - 1]; f[i] = f[i - 1] * aa[i]; bb[i] = bb[i - 1];}
                }
                if(b[i] == 2)
                {
                    if(aa[i - 1] == 1 && bb[i - 1] == 0) f[i] = 0;
                    else if(aa[i - 1] == 0 && bb[i - 1] == 1) f[i] = 0;
                    else
                    {
                        aa[i] = bb[i - 1];
                        bb[i] = aa[i];
                        if(aa[i] == 2) f[i] = f[i - 1] * 2;
                        else f[i] = f[i - 1];
                    }
                }
                if(b[i] == 3)
                {
                    bb[i] = bb[i - 1];
                    aa[i]
                }
            }
            else if(a[i] == 4)
            {

            }
        }
        f[n - 1] = f[n - 1] % MOD;
        printf("Case #%d: %I64d\n",CAS,ans);
    }
    return 0;
}
