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
#include <assert.h>
#include <iomanip>
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
typedef pair<int, int> PII;
#define FOR(i,x) for(int i = 0, _END_ = (int)(x); i < _END_ ; i++)
#define REP(i,x,y) for(int i = x,  _END_ = (int)(y); i <= _END_ ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

char s1[55][55];
char s2[55][55];
char s3[55][55];
int n;
char s[4][55 * 55];
char get(int x, int y, int cnt)
{
//    cout << "GET" << x << y << cnt << endl;
    if(cnt == 0) return s1[x][y];
    return get(y, n - x - 1, cnt - 1);
}
int tots[4];
void init_s()
{
    clr(tots,0);
}
void add_s(int l, char ch)
{
    s[l][tots[l]++] = ch;
    s[l][tots[l]] = 0;
}
char ans[55 * 55];
char realans[55 * 55];
bool haveans;
int totans;
void init_ans()
{
    totans = 1;
    ans[0] = ' ';
    ans[1] = 0;
}
void add_ans(char ch)
{
    if(ch == '.') ch = ' ';
    if(ch == ' ' && ans[totans - 1] == ' ') return;
    ans[totans++] = ch;
    ans[totans] = 0;
}
void updans()
{
    if(haveans == false)
    {
        haveans = true;
        swap(ans, realans);
    }
    else
        if(strcmp(ans,realans) < 0) swap(ans, realans);
}
char word[105][25];
int m;
bool chk(int i, int ed)
{
//    printf("CHK %s %d %d\n",ans, i, ed);
    bool boo;
    FOR(k,m) if(strlen(word[k]) == ed - i)
    {
        boo = true;
        FOR(j,strlen(word[k]))
        {
            if(i + j > totans) {boo = false; break;}
            if(ans[i + j] != word[k][j]) boo = false;
        }
        if(boo) return true;
    }
    return false;
}
int main()
{
    int _T;
    scanf("%d",&_T);
    FORR(CAS,_T)
    {
        scanf("%d",&n);
        FOR(i,n) scanf("%s",&s1[i]);
        FOR(i,n) scanf("%s",&s2[i]);
        init_s();
        FOR(l,4)
        {
            FOR(i,n) FOR(j,n) if(s2[i][j] == '*') add_s(l,get(i,j,0));
            FOR(i,n) FOR(j,n) s3[j][n - 1 - i] = s2[i][j];
            swap(s2,s3);
        }
        scanf("%d",&m);
        FOR(i,m) scanf("%s",&word[i]);
        haveans = false;
        FOR(st,4)
        {
            init_ans();
            FOR(l,4)
            {
                int now = (st + l) % 4;
                FOR(i,tots[now]) add_ans(s[now][i]);
            }
            if(ans[totans - 1] == ' ')
            {
                totans --;
                ans[totans] = 0;
            }
            int pre = 0;
            for(int i = 1; i < totans; i++)
            {
                if(i == totans - 1 || ans[i] == ' ')
                {
                    if(!chk(pre + 1, (i == totans - 1)? totans: i)) break;
                    pre = i;
                }
                if(i == totans - 1) updans();
            }
//            puts(ans);
        }
        printf("Case #%d:", CAS);
        if(haveans) puts(realans); else puts(" FAIL TO DECRYPT");
    }
}
