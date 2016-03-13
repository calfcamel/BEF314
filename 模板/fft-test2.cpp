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

#define clr(a,b) memset(a,b,sizeof(a))
const int MAXN = 50000 + 5;
const LL MOD = 1000000000 + 7;

const double PI = acos(-1.0);
struct complex
{
    double r,i;
    complex(double _r = 0.0,double _i = 0.0)
    {
        r = _r; i = _i;
    }
    complex operator +(const complex &b)
    {
        return complex(r+b.r,i+b.i);
    }
    complex operator -(const complex &b)
    {
        return complex(r-b.r,i-b.i);
    }
    complex operator *(const complex &b)
    {
        return complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};
/*
 * 进行FFT和IFFT前的反转变换。
 * 位置i和 （i二进制反转后位置）互换
 * len必须去2的幂
 */
void change(complex y[],int len)
{
    int i,j,k;
    for(i = 1, j = len/2;i < len-1; i++)
    {
        if(i < j)swap(y[i],y[j]);
        //交换互为小标反转的元素，i<j保证交换一次
        //i做正常的+1，j左反转类型的+1,始终保持i和j是反转的
        k = len/2;
        while( j >= k)
        {
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    }
}
/*
 * 做FFT
 * len必须为2^k形式，
 * on==1时是DFT，on==-1时是IDFT
 */
void fft(complex y[],int len,int on)
{
    change(y,len);
    for(int h = 2; h <= len; h <<= 1)
    {
        complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j+=h)
        {
            complex w(1,0);
            for(int k = j;k < j+h/2;k++)
            {
                complex u = y[k];
                complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}
/*
struct complex
{
    double r,i;
    complex(double r = 0,double i = 0):r(r),i(i){};
    complex operator + (const complex &b){return complex(r + b.r, i + b.i);}
    complex operator - (const complex &b){return complex(r - b.r, i - b.i);}
    complex operator * (const complex &b){return complex(r * b.r - i * b.i, r * b.i + i * b.r);}
};

void change(complex y[],int len)
{
    int i,j,k;
    for(i = 1, j = len / 2; i < len - 1; i++)
    {
        if(i < j) swap(y[i], y[j]);
        k = len >> 1;
        while( j >= k)
        {
            j -= k;
            k >>= 1;
        }
        if(j < k)j += k;
    }
}

void fft(complex y[],int len,int on)
{
    change(y,len);
    for(int h = 2;h <= len;h <<= 1)
    {
        complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j += h)
        {
            complex w(1,0);
            for(int k = j;k < j+h/2;k++)
            {
                complex u = y[k];
                complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}*/
char s1[MAXN];
char s2[MAXN];
complex x1[MAXN << 2];
complex x2[MAXN << 2];
int ans[MAXN << 2];
int main()
{
    while(scanf("%s%s",&s1,&s2)!= EOF)
    {
        int l1 = strlen(s1);
        int l2 = strlen(s2);
        int l = 1;
        while(l < 2 * l1 || l < 2 * l2) l <<= 1;
        int i,j;
        for(i = 0, j = l1 - 1; j >= 0; j--, i++)
            x1[i] = complex(s1[j] - '0',0);
        for(; i < l; i++)
            x1[i] = complex(0,0);
        for(i = 0, j = l2 - 1; j >= 0; j--, i++)
            x2[i] = complex(s2[j] - '0',0);
        for(; i < l; i++)
            x2[i] = complex(0,0);

        fft(x1,l,1);
        fft(x2,l,1);
        for(i = 0; i < l; i++)
            x1[i] = x1[i] * x2[i];
        fft(x1,l,-1);

        clr(ans,0);
        for(i = 0; i < l; i++)
        {
            ans[i] += x1[i].r + .5;
            if(ans[i] > 9) {ans[i + 1] += ans[i] / 10; ans[i] %= 10;}
        }
        while(!ans[l] && l > 0) l--;
        for(;l >= 0; l--) printf("%d",ans[l]);
        puts("");
    }
}
