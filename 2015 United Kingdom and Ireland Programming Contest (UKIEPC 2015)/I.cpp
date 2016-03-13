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
#define dbg(x) cerr <<#x<<" = " << x << endl
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)

const int MAXN = 100000 + 5;

char s[500005];
char ans[50005];
int tot = 0;
void add(char ch)
{
    ans[tot++] = ch;
//    cout << "ADD*" << ch << "*" << (int) ch << endl;
}
char getfirst(char ch)
{
    if('A' <= ch && ch <= 'B') return 'B';
    if('C' <= ch && ch <= 'C') return 'C';
    if('D' <= ch && ch <= 'E') return 'D';
    if('F' <= ch && ch <= 'I') return 'G';
    if('J' <= ch && ch <= 'L') return 'K';
    if('M' <= ch && ch <= 'O') return 'N';
    if('P' <= ch && ch <= 'R') return 'P';
    if('S' <= ch && ch <= 'Z') return 'T';
    if('a' <= ch && ch <= 'b') return 'b';
    if('c' <= ch && ch <= 'c') return 'c';
    if('d' <= ch && ch <= 'e') return 'd';
    if('f' <= ch && ch <= 'i') return 'g';
    if('j' <= ch && ch <= 'l') return 'k';
    if('m' <= ch && ch <= 'o') return 'n';
    if('p' <= ch && ch <= 'r') return 'p';
    if('s' <= ch && ch <= 'z') return 't';
}
char getsecond(char ch)
{
//    cout << "GET 2 " << ch << endl;
    if(ch < 'a') ch = ch - 'A' + 'a';
    if('a' <= ch && ch <= 'h') return 'a';
    if('i' <= ch && ch <= 'r') return 'o';
    if('s' <= ch && ch <= 'z') return 'u';
}
bool gethard(char ch)
{
    if(ch == 'b') return true;
    if(ch == 'c') return true;
    if(ch == 'd') return true;
    if(ch == 'g') return true;
    if(ch == 'k') return true;
    if(ch == 'n') return true;
    if(ch == 'p') return true;
    if(ch == 't') return true;
    if(ch == 'B') return true;
    if(ch == 'C') return true;
    if(ch == 'D') return true;
    if(ch == 'G') return true;
    if(ch == 'K') return true;
    if(ch == 'N') return true;
    if(ch == 'P') return true;
    if(ch == 'T') return true;
    return false;
}
int main()
{
    tot = 0;
    s[0] = ' ';
    gets(s + 1);
    bool flag = false;
    char C;
    char tmp;
    int l = strlen(s);
//    dbg(l);
    FOR(i,l)
    {
        if(i == 0) continue;
        else if(s[i] == ' ')
        {
            add(' ');
            flag = false;
        }
        else if(s[i] == '-')
        {
            flag = true;
        }
        else if(s[i - 1] == ' ')
        {
            C = getfirst(s[i]);
            if(C < 'a') C = C - 'A' + 'a';
            add(getfirst(s[i]));
            s[i] = getfirst(s[i]);
        }
        else if(flag && gethard(s[i]))
        {
            add(C);
            s[i] = C;
        }
        else
        {
            add(s[i]);
        }
        if((s[i + 1] == ' ' || s[i + 1] == 0) && gethard(s[i]))
        {
//            cout << "GT HD " << s[i] << endl;
            add(getsecond(s[i]));
            add('h');
        }
    }
    add(0);
//    FOR(i,l) printf("%c",ans + i);
//    puts("");
    puts(ans);
    return 0;
}
