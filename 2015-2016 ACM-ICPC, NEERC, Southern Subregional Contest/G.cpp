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
#define AAA first.first
#define AAB first.second
#define BB second
#define PB push_back
#define SZ size()
#define dbg(x) cerr <<#x<<" = " << x << endl
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
typedef pair< pii , int > piii;
const int MAXN = 1000000 + 5;
#define MP3(x,y,z) make_pair(make_pair(x,y),z)

struct node
{
    LL a[MAXN];
    void bitinit()
    {
        clr(a,0);
    }
    inline LL lowbit(LL x)
    {
        return x & (-x);
    }
    void bitinsert(LL p,LL add)
    {
        while(p < MAXN)
        {
            a[p] += add;
            p += lowbit(p);
        }
    }
    LL getcnt(LL p)
    {
        LL sum = 0;
        while(p > 0)
        {
            sum += a[p];
            p -= lowbit(p);
        }
        return sum;
    }
}bit1,bit2;


int ans[MAXN];
vector<pii> v1;
vector<piii> v2;
bool check(LL x,LL r,LL d)
{
    return (LL)bit1.getcnt(x) - (LL)bit2.getcnt(x) * (LL)d >= (LL)r;
}
int main()
{
    int n,m;
    int x,y;
    clr(ans,-1);
    bit1.bitinit();
    bit2.bitinit();
    v1.clear();
    v2.clear();
    scanf("%d%d",&n,&m);
    FOR(i,m)
    {
        scanf("%d",&x);
        v1.PB(MP(-x,i + 1));
    }
    sort(v1.begin(),v1.end());
    FOR(i,m) v1[i].AA *= -1;
    FOR(i,n)
    {
        scanf("%d%d",&x,&y);
        v2.PB(MP3(-x,y,i));
    }
    sort(v2.begin(),v2.end());
    FOR(i,n) v2[i].AAA *= -1;
    vector<pii>::iterator it = v1.begin();
    FOR(i,n)
    {
        while(it != v1.end() && (*it).AA > v2[i].AAA)
        {
            bit1.bitinsert((*it).BB,(*it).AA);
            bit2.bitinsert((*it).BB,1);
            it++;
        }
        int L = 1;
        int R = m;
//        cout << endl;
//        cout << "CAL " << v2[i].BB << endl;
//        cout << "d,r = " << v2[i].AAA << "," << v2[i].AAB << endl;
//        cout << "bit1:"; FOR(i,10) cout << " " << bit1.getcnt(i); cout << endl;
//        cout << "bit2:"; FOR(i,10) cout << " " << bit2.getcnt(i); cout << endl;
//        cout << "cha :"; FOR(i,10) cout << " " << (bit1.getcnt(i) - bit2.getcnt(i) * (v2[i].AAA)); cout << endl;
        if(check(m,v2[i].AAB,v2[i].AAA))
        while(L < R)
        {
//            cout << L << " " << R << endl;
            int mid = (L + R) / 2;
            if(check(mid,v2[i].AAB,v2[i].AAA)) R = mid;
            else L = mid + 1;
        }
        else L = 0;
        ans[v2[i].BB] = L;
//        cout << v2[i].BB << " " << L << endl;
    }
    ///display
    FOR(i,n)
    {
        if(i) printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}

