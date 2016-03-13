#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define FOR(i, n) for(int i = 0; i < n; i++)
#define AA first
#define BB second
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define ULL unsigned long long
#define LL long long
#define READ(x) scanf("%d", &x)
typedef pair<int, int> PII;

char s2[40010], s1[40010];
int n;


int MinimumRepresentation(char *s, int l)
{
	int i,j,k;
	i=0;j=1;k=0;
	while(i<l&&j<l)
	{
		k=0;
		while(s[i+k]==s[j+k]&&k<l) k++;
		if(k==l) return i;
		if(s[i+k]>s[j+k])
		 if(i+k+1>j) i=i+k+1;
		 else i=j+1;
		else if(j+k+1>i) j=j+k+1;
		else  j=i+1;
	}
	if(i<l) return i;
	else return j;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int _T; READ(_T);
	while(_T--)
	{
	    READ(n);
		scanf("%s", s1);
        strcpy(s2, s1);
        reverse(s2, s2 + n);
        for(int i = 0; i < n; i++) s1[i] = 'z' - s1[i] + 'a';
        for(int i = 0; i < n; i++) s2[i] = 'z' - s2[i] + 'a';
        for(int i = 0; i < n; i++) s1[i + n] = s1[i];
        for(int i = 0; i < n; i++) s2[i + n] = s2[i];

        int p1 = MinimumRepresentation(s1, n);
        int p2 = MinimumRepresentation(s2, n);
        int flg = 0;
        for(int i = 0; i < n; i++)
            if(s1[i + p1] < s2[i + p2]) { flg = 1; break; }
            else if(s1[i + p1] > s2[i + p2])  { flg = 2; break; }

        if(flg == 2) printf("%d 1\n", (n - p2));
        else if(flg == 1) printf("%d 0\n", p1 + 1);
        else
        {
            p1 = p1 + 1;
            p2 = n - p2;
            if(p1 <= p2) printf("%d 0\n", p1);
            else if(p2 < p1) printf("%d 1\n", p2);
        }
	}
	return 0;
}
