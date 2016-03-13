#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const double EPS = 1e-8;
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)
const int MAXN = 2005;
double pp[MAXN];
double dp[2][MAXN];
double c[MAXN];
int main()
{
    //cout << sizeof(dp) << endl;
    int n,m,k;
    double p1,p2,p3,p4;
    double ans;
    double temp;
    while(scanf("%d%d%d%lf%lf%lf%lf",&n,&m,&k,&p1,&p2,&p3,&p4)!= EOF)
    {
        if(p4 < EPS)
        {
            ans = 0;
        }
        else
        {
            p2 = p2/(1.0 - p1);
            p3 = p3/(1.0 - p1);
            p4 = p4/(1.0 - p1);
            dp[1][1] = p4/(1.0 - p2);
            cout << dp[1][1] << " **" << endl;
            pp[0] = 1.0;
            for(int i = 1; i <= n; i++)
                pp[i] = p2 * pp[i - 1];
            c[1] = p4;
            for(int ll = 2; ll <= n; ll++)
            {
                int l = ll & 1;
                for(int j = 2; j <= k; j++) c[j] = p3 * dp[l ^ 1][j - 1] + p4;
                for(int j = k + 1; j <= ll; j++) c[j] = p3 * dp[l ^ 1][j - 1];
                temp = c[1] * pp[ll - 1];
                FORR(j,ll) cout << "C " << j << " = " << c[j] << endl;
                for(int j = 2; j <= ll; j++) temp += c[j] * pp[ll - j];
                cout << temp << "tmp" << endl;
                dp[l][ll] = temp / (1.0 - pp[ll]);
                dp[l][1] = p2 * dp[l][ll] + c[1];
                for(int j = 2; j <= ll - 1; j++) dp[l][j] = p2 * dp[l][j - 1] + c[j];
            }
            ans = dp[n & 1][m];
        }
//        cout <<pp[3] << endl;
        printf("%.5f\n",ans);
    }
}
