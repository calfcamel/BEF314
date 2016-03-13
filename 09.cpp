#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
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


const int MAXN = 10000 + 5;

const double eps = 1e-8;
struct P {
	double x,y;
	P(double x=0, double y=0):x(x),y(y){}
}a,b,c,m,o;
typedef struct P point;
typedef P V;
V operator + (V A,V B){return V(A.x+B.x,A.y+B.y);}
V operator - (P A,P B){return V(A.x-B.x,A.y-B.y);}
V operator * (V A,double p){return V(A.x*p,A.y*p);}
V operator / (V A,double p){return V(A.x/p,A.y/p);}
double Dot(V A,V B){return A.x*B.x+A.y*B.y;}
double Length(V A){return sqrt(Dot(A,A));}
double Length2(V A){return abs(Dot(A,A));}
double _distance(P A, P B)
{
    return Length(A - B);
}
double Angle(V A,V B){return acos(Dot(A,B)/Length(A)/Length(B));}
int dcmp(double x){if(fabs(x) < eps) return 0;else return x<0 ? -1 : 1;}

point intersection(point u1,point u2,point v1,point v2)
{
    point ret=u1;
    double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
             /((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
    ret.x+=(u2.x-u1.x)*t;
    ret.y+=(u2.y-u1.y)*t;
    return ret;
}

void intersection_line_circle(point c,double r,point l1,point l2,point& p1,point& p2)
{
    point p=c;
    double t;
    p.x+=l1.y-l2.y;
    p.y+=l2.x-l1.x;
    p=intersection(p,c,l1,l2);
    t=sqrt(r*r-_distance(p,c)*_distance(p,c))/_distance(l1,l2);
    p1.x=p.x+(l2.x-l1.x)*t;
    p1.y=p.y+(l2.y-l1.y)*t;
    p2.x=p.x-(l2.x-l1.x)*t;
    p2.y=p.y-(l2.y-l1.y)*t;
}
double xmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

double disptoline(point p,point l1,point l2)
{
    return fabs(xmult(p,l1,l2))/_distance(l1,l2);
}

int intersect_line_circle(point c,double r,point l1,point l2) // bu baokuo
{
    return disptoline(c,l1,l2)<r - eps;
}

int main()
{
    int _T;
    scanf("%d", &_T);
    int x,y;
    int n,A,B,L;
    point j1,j2;
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
        m.x = (b.x + c.x) / 2.0;
        m.y = (b.y + c.y) / 2.0;
        o.x = (a.x + b.x) / 2.0;
        o.y = (a.y + b.y) / 2.0;
        double ans = Length(a - m);
        double r = Length(a - b) / 2.0;
        double jiao;
        //cout << "r = " << r << endl;
        //if(dcmp(Length(b - m) - r) == -1)
        if(Length2(b - a) + Length2(c - a) > Length2(b - c))
        {
            intersection_line_circle(o,r,a,c,j1,j2);
            jiao = min(abs(Angle(j1 - o, m - o)), abs(Angle(j2 - o, m - o)));
//            cout << "jiao 1 = " << abs(Angle(j1 - o, j1 - m)) << endl;
//            cout << "jiao 2 = " << abs(Angle(j2 - o, j2 - m)) << endl;
            if(jiao > .5 * acos(-1.0)) jiao = acos(-1.0) - jiao;
            ans += Length(a - b) * jiao;
//            cout << "jiao = " << jiao << endl;
//            cout << "j1 = " << j1.x << " " << j1.y << endl;
//            cout << "j2 = " << j2.x << " " << j2.y << endl;
        }
        else
        {
            ans += Length(a - b) * abs(Angle(a - o, m - o));
        }
        printf("Case #%d: %.4f\n", CAS, ans);
    }
    return 0;
}
