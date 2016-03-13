#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
map<int, int>s;
int H[10];
int q[30000000];
int c[10];
int pos[10];
int e[10];
int cnt;
int n;
int hash(int *c)
{
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = ans * 10 + c[i];
    }
    return ans;
}
void cal(int x)
{
    for(int i = n - 1; i > -1; i--)
    {
        pos[i] = x % 10;
        x /= 10;
    }
    for(int i = 1; i <= n; i++) e[i] = n + 1;
    for(int i = 0; i < n; i++)
        e[pos[i]] = min(e[pos[i]], i);
}
void bfs(int x)
{
    s.clear();
    int l = 0, r = -1;
    q[++r] = x;
    s[x] = 0;
    while(l <= r)
    {
        cal(q[l]);
//        cout << q[l] << " ";
//        for(int i = 1; i <= n; i++) cout << e[i] << " "; cout << endl;
        int cnt = s[q[l]];
        l++;
        for(int i = 1; i <= n - 1; i++)
        {
            if(e[i] < e[i + 1])
            {
                pos[e[i]]++;
                int c = hash(pos);
                if(s.find(c) == s.end())
                {
                    s[c] = cnt + 1;
                    q[++r] = c;
                }
                pos[e[i]]--;
            }
        }
        for(int i = 2; i <= n; i++)
        {
            if(e[i] < e[i - 1])
            {
                pos[e[i]]--;
                int c = hash(pos);
                if(s.find(c) == s.end())
                {
                    s[c] = cnt + 1;
                    q[++r] = c;
                }
                pos[e[i]]++;
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    int _T; scanf("%d", &_T);
    while(_T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) pos[i] = i + 1;
        bfs(hash(pos));
        //printf("const int a%d[] = {", n);
        for(int i = 0; i < n; i++) pos[i] = i + 1;
        bool flg = false;
        do
        {
            int h = hash(pos);
            cout << h << endl;
            flg = true;
            if(s.find(h) != s.end()) printf("%d", s[h]);
            else printf("-1");
            cout << endl;
        } while(next_permutation(pos, pos + n));
        printf("};");
    }
    return 0;
}
