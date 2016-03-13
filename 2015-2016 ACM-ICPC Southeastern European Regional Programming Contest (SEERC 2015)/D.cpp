
#include <cstdio>

using namespace std;

    int c;
    int x,y;
    int ans;
    int z;
int main()
{
    while(scanf("%d%d",&x,&y)!= EOF)
    {
        if(x == y) ans = 0;
        if(x > y)
        {
            c = x; x = y; y = c;
        }
        else if(x == 0 || y == 0) ans = 0;
        else if(y % x == 0) ans = 0;
        else
        {
            c = x - y;
            if(c < 0) c *= -1;
            z = x % c;
            if(z == 0)
            {
                ans = 0;
            }
            else
            {
                ans = c - z;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
