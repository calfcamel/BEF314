#include<iostream>
#include<sstream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

int n, w;
int dp[2][1 << 16], bc[1 << 16];
string in[130];

int main(){
    cin >> n >> w;
    rep(i, n) cin >> in[i];
    rep(i, 1 << w) bc[i] = __builtin_popcount(i);

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    int cur = 0, next = 1;
    rep(i, n) rep(j, w){
        memset(dp[next], -1, sizeof(dp[next]));
        rep(bit, 1 << w) if(dp[cur][bit] >= 0){
            int idx = bc[bit & (1 << j) - 1];
            if(idx < in[i].size()){
                int nxt = dp[cur][bit];
                if(j && (bit & 1 << (j - 1)) && in[i][idx - 1] == in[i][idx]) nxt++;
                if(i && (bit & 1 << j) && in[i][idx] == in[i - 1][in[i - 1].size() - bc[bit >> j]]) nxt++;
                dp[next][bit | 1 << j] = max(dp[next][bit | 1 << j], nxt);
            }
            if(idx + w - j > in[i].size()){
                dp[next][bit & ~(1 << j)] = max(dp[next][bit & ~(1 << j)], dp[cur][bit]);
            }
        }
        swap(cur, next);
    }
    cout << 2 * *max_element(dp[cur], dp[cur] + (1 << w)) << endl;
    return 0;
}
