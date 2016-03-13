#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define FOR(i,x) for(int i = 0, _END_ = (int)x; i < _END_; i++)
#define FORR(i,x) for(int i = 1, _END_ = (int)x; i <= _END_; i++)
#define REP(i,y,x) for(int i = (int)y, _END_ = (int)x; i <= _END_; i++)
#define REP_D(i,y,x) for(int i = (int)y, _END_ = (int)x; i >= _END_; i--)
#define clr(a,b) memset(a, b, sizeof(a))
#define cmin(a,b) a = std::min(a,b);
const int MAXL = 100000;
const int MAX = 10;
const int MAXTRIE = 3567708;
struct node1
{
    int l,r, arr[21000];
    void init(){clr(arr,0); l = r = 0;}
}a,b,c,d;

struct trienode
{
    int nxt[10];
    int w;
    void init(){clr(nxt, -1);}
}trie[MAXTRIE];
int totT;
int addl;
int adda[50];

void push(int p)
{
    int now = 0;
    FOR(i,addl)
    {
        if(~trie[now].nxt[adda[i]]) now = trie[now].nxt[adda[i]];
        else
        {
            trie[now].nxt[adda[i]] = totT;
            now = totT++;
            trie[now].w = p;
        }
    }
}
//int fj[8];
//int tmp;
//int fenjie(int k)
//{
//    tmp = MAX;
//    REP_D(i,7,0)
//    {
//        tmp /= 10;
//        fj[i] = b.arr[k] / tmp % 10;
//    }
//    REP_D(i,7,0) if(fj[i]) return i;
//}
void pushb(int p)
{
    addl = 0;
    int i = b.r;
//    int j = fenjie(i);
//    if(p == MAXL){
//    std::cout << "p:" << p << std::endl;
//    REP_D(i,b.r,b.l) std::cout << b.arr[i];
//    std::cout << std::endl;}
    while(1)
    {
//        while(j >= 0) {adda[addl++] = fj[j]; j--;}
        adda[addl++] = b.arr[i];
        i--;
        if(addl == 40) break;
        if(i < 0) break;
//        j = fenjie(i);
//        j = 7;
    }
    if(addl) push(p);
    if(p == MAXL - 1000){
    FOR(i,addl) std::cout << adda[i];
    std::cout << std::endl;}
}
void gaojing()
{
    a.init(); a.arr[0] = 1;
    b.init(); b.arr[0] = 1;
    c.init();
    pushb(0);
    REP(loop,3,MAXL)
    {
//        std::cout << loop << std::endl;
        REP(i,b.l,b.r) c.arr[i] = a.arr[i] + b.arr[i];
        c.l = b.l; c.r = b.r;
        REP(i,c.l,c.r - 1) if(c.arr[i] >= MAX) {c.arr[i] -= MAX; c.arr[i + 1] += 1;}
        if(c.arr[c.r] >= MAX) {c.arr[c.r] -= MAX; c.arr[++c.r] = 1;}
        c.l = std::max(0, c.r - 1000);
//        if(c.r > 20000) std::cout << c.r << std::endl;
//        std::swap(a,b);
//        std::swap(b,c);
        d = a;
        a = b;
        b = c;
        c = d;
        pushb(loop - 1);
    }
}

void inittrie()
{
    FOR(i,MAXTRIE) trie[i].init();
    totT = 1;
//    trie[0].init();
}
char str[48];

int query()
{
    int l = strlen(str);
    int now = 0;
    FOR(i,l)
    {
        if(~trie[now].nxt[str[i] - '0'])
            now = trie[now].nxt[str[i] - '0'];
        else return -1;
    }
    return trie[now].w;
}
int main()
{
    inittrie();
//    std::cout << " END 1" << std::endl;
    gaojing();
//    std::cout << "totT = " << totT << std::endl;
//    std::cout << " END 2" << std::endl;
    int _T;
    scanf("%d",&_T);
    FORR(CAS, _T)
    {
        scanf("%s",str);
        printf("Case #%d: %d\n", CAS, query());
    }
}
