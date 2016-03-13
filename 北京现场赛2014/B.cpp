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

int a[10][10];
int p[30];
int b[30];
int num[30];
vector<int> v1,v2;
vector<pair<int, int> > V;
int main()
{
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i = 0; i < k; i++)
            scanf("%d",&p[i]);
        V.clear();
        for(int i = 0; i < k; i++)
            V.push_back(make_pair(p[i],i + 1));
        sort(V.begin(),V.end());
        for(int i = 0; i < k; i++)
        {
            p[i] = V[i].first;
            num[i] = V[i].second;
//            cout << "xxx " << p[i] << " " << num[i] << endl;
        }
        clr(b,0);
        int sum1 = 0;
        int sum2 = 0;
        for(int i = k - 1; i >= 0; i--)
        {
            if(sum1 > sum2)
            {
                sum2 += p[i];
                b[i] = 1;
            }
            else
            {
                sum1 += p[i];
            }
        }
        int mid = n * m / 2;
        mid += (n * m) & 1;
        if(p[k - 1] > mid)
        {
            printf("Case #%d:\n",CAS);
            puts("NO");
            continue;
        }
        v1.clear();
        v2.clear();
        int bbb;
        if(sum1 >= mid) bbb = 0; else bbb = 1;
//        cout << "B: ";
//        for(int i = 0; i < k; i++)
//            cout << b[i] << " ";
        for(int i = k - 1; i >= 0; i--)
        {
            if(bbb == b[i])
            {
                int x = v1.size();
                for(int j = 0; j < p[i]; j++)
                    if(x < mid)
                    {
                        x++;
                        v1.push_back(num[i]);
                        //cout << "push v1 " << num[i] << endl;
                    }
                    else
                    {
                        v2.insert(v2.begin(),num[i]);
                        //cout << "push v2 " << num[i] << endl;
                    }
            }
            else for(int j = 0; j < p[i]; j++)
            {
                v2.push_back(num[i]);
                //cout << "push v2 " << num[i] << endl;
            }
        }
//        cout << "mid = " << mid << endl;
//        cout << "v1.size = " << v1.size() << endl;
//        for(int i = 0; i < v1.size(); i++)
//            cout << v1[i] << " ";cout << endl;
//        cout << "v2.size = " << v2.size() << endl;
//        for(int i = 0; i < v2.size(); i++)
//            cout << v2[i] << " ";cout << endl;
        printf("Case #%d:\n",CAS);
        puts("YES");
        int cnt1 = 0;
        int cnt2 = 0;
        if(n > m)
        {
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if((i + j) & 1)
                    {
                        a[i][j] = v2[cnt2++];
                    }
                    else
                    {
                        a[i][j] = v1[cnt1++];
                    }
        }
        else
        {
            for(int j = 0; j < m; j++)
                for(int i = 0; i < n; i++)
                    if((i + j) & 1)
                    {
                        a[i][j] = v2[cnt2++];
                    }
                    else
                    {
                        a[i][j] = v1[cnt1++];
                    }
        }
//        for(int i = 0; i < n; i++)
//        {
//            for(int j = 0 ; j < m; j++)
//            {
//                if(j) printf(" ");
//                if((i + j) & 1)
//                {
//                    printf("%d",v2[cnt1]);
//                    cnt1++;
//                }
//                else
//                {
//                    printf("%d",v1[cnt2]);
//                    cnt2++;
//                }
//            }
//            puts("");
//        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(j) printf(" ");
                printf("%d",a[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
