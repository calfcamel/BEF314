#include<stdio.h>
#include<vector>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define clr(a,b) memset(a,b,sizeof(a))
typedef struct point
{
    int x;
    int y;
    point(int x,int y):x(x),y(y){};
    point(){};
}P;
int m[10][9];
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};
int checki(int i, int l, int r)
{
    int ans = 0;
    for(int k = min(l,r) + 1; k < max(l,r); k++)
        if(m[i][k]) ans++;
    return ans;
}
int checkj(int j, int l, int r)
{
    int ans = 0;
    for(int k = min(l,r) + 1; k < max(l,r); k++)
        if(m[k][j]) ans++;
    return ans;
}
int main()
{
    int hx,hy;
    int x,y;
    int n;
    int xx,yy;
    bool ans;
    bool ok;
    char str[10];
    P black,red;
    vector<P> vec;
    while(1)
    {
        scanf("%d%d%d",&n,&x,&y);
        if(n == 0 && x == 0 && y == 0)
            return 0;
        x--;
        y--;
        black.x = x;
        black.y = y;
        vec.clear();
        clr(m,0);
        for(int i = 0; i < 4; i++)
        {
            xx = x + dx[i];
            yy = y + dy[i];
            if(xx <= 2 && xx >= 0 && yy <= 5 && yy >= 3)
                vec.push_back(P(xx,yy));
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%s%d%d",&str,&x,&y);
            x--;y--;
            m[x][y] = str[0];
            if(str[0] == 'G'){red.x = x; red.y = y;}
        }
        ans = false;
        if(black.y == red.y && checkj(black.y,black.x,red.x) == 0) ans = true;
        for(int k = 0; k < (int)vec.size(); k++)
        {
            xx = vec[k].x;
            yy = vec[k].y;
            ok = true;
            for(int i = 0; i < 10; i++)
                for(int j = 0; j < 9; j++)
                {
                    if(i == xx && j == yy) continue;
                    if(!m[i][j]) continue;
                    if(m[i][j] == 'G' && j == yy && checkj(yy,xx,i) == 0) ok = false;
                    if(m[i][j] == 'R' && j == yy && checkj(yy,xx,i) == 0) ok = false;
                    if(m[i][j] == 'R' && i == xx && checki(xx,yy,j) == 0) ok = false;
                    if(m[i][j] == 'C' && j == yy && checkj(yy,xx,i) == 1) ok = false;
                    if(m[i][j] == 'C' && i == xx && checki(xx,yy,j) == 1) ok = false;
                    if(m[i][j] == 'H' && abs((i - xx) * (j - yy)) == 2)
                    {
                        if(!m[i + (xx - i) / 2][j + (yy - j) / 2]) ok = false;
                    }
                }
            ans |= ok;
        }
        if(ans) puts("NO");
        else puts("YES");
    }
}
