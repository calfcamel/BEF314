#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <stack>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <cassert>
#include <numeric>
#include <ctime>
using namespace std;
//#define Online_Judge
#define outstars cout << "***********************" << endl;
#define clr(a,b) memset(a,b,sizeof(a))
#define lson l , mid  , rt << 1
#define rson mid + 1 , r , rt << 1 | 1
#define mk make_pair
#define pb push_back
#define sz size()
#define AA first
#define BB second
#define eps 1e-10
#define deq(a , b) fabs(a - b) < eps

const int MAXN = 10000 + 50;
const int MAXE = 500000 + 50;
const int MAXQ = 1000000 + 50;
const int sigma_size = 26;

const int inf = 0x3f3f3f3f;
const int INF = ~0U >> 1;
const long long LLinf = 0x3FFFFFFFFFFFFFFFLL;
const long long LLINF = (1LL << 63) - 1;
const int IMIN = 0x80000000;


const long long MOD = (1LL << 31) - 1;
const int mod = 10007;
typedef long long LL;
const double PI = acos(-1.0);
typedef pair<int , int> pii;
typedef vector<pii> vec;
typedef vector<vec> mat;
#define Bug(s) cout << "s = " << s << endl;
///#pragma comment(linker, "/STACK:102400000,102400000")
LL gcd(LL a, LL b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
class fraction {
public:
    int above;         //分子
    int below;         //分母
    void reduction();            //约分
    fraction makeCommond(fraction); //通分


    fraction(int a=0,int b=1) {      //构造函数
        above=a;
        below=b;
    }
    fraction add(fraction);      //两分数相加
    fraction sub(fraction);      //本分数减去实参分数
    fraction mul(fraction);      //两分数相乘
    fraction div(fraction);      //本分数除以实参分数
    fraction reciprocal();       //求倒数
    bool equal(fraction);        //等于运算
    bool greaterThan(fraction);  //大于运算
    bool lessThan(fraction);     //小于运算
    void display();              //显示分数
    void input();                //输入分数
};

void fraction::reduction() {
//    int i,comdiv,small,max;
//    if(this->above<this->below) {
//        small=this->above;
//        max=this->below;
//    } else {
//        small=this->below;
//        max=this->above;
//    }
//
//    for(i=small; i>1; i--) {
//        if(small%i==0 &max%i==0 )
//            break;
//    }
//    comdiv=i;//最大公约数
    int i = __gcd(this->above , this->below);
    if(i!=0) {
        this->above/=i;
        this->below/=i;
    }
    int sign=this->above*this->below;
    if(sign<0)sign=-1;
    else sign= 1;
    if(this->above<0)this->above*=-1;
    if(this->below<0)this->below*=-1;
    this->above*=sign;
}
fraction fraction::makeCommond(fraction frac) {
    int b1=this->below,b2=frac.below, m,s;
    if(b1>b2) {
        m=b1%b2;
        s=b2;
    } else {
        m=b2%b1;
        s=b1;
    }

    while(m>0) {
        int res=s%m;
        s=m,m=res;
    }


    int small=(b1*b2)/s;
    this->above=this->above*(small/this->below);
    frac.above=frac.above*(small/frac.below);
    this->below=small;
    frac.below=small;
    return frac;
}

fraction fraction::add(fraction fr) {
    fraction myFraction;
    myFraction.above=this->above*fr.below+fr.above*this->below;
    myFraction.below=this->below*fr.below;

    myFraction.reduction();

    return myFraction;
}
fraction fraction::sub(fraction fr) {
    fraction myFraction;
    myFraction.above=this->above*fr.below-fr.above*this->below;
    myFraction.below=this->below*fr.below;

    myFraction.reduction();

    return myFraction;
}

fraction fraction::mul(fraction fr) {
    fraction myFraction;
    myFraction.above=this->above*fr.above;
    myFraction.below=this->below*fr.below;
    myFraction.reduction();

    return myFraction;
}
fraction fraction::div(fraction fr) {
    fraction myFraction;

    myFraction.above=this->above*fr.below;
    myFraction.below=this->below*fr.above;

    myFraction.reduction();

    return myFraction;
}

fraction fraction::reciprocal() {
    fraction myFraction(this->above,this->below);
    if(this->above!=0) {
        int temp=myFraction.above;
        myFraction.above=myFraction.below;
        myFraction.below=temp;
    }
    return myFraction;
}

bool fraction::equal(fraction frac) {     //等于运算
    bool result=false;
    if(this->sub(frac).above==0)
        result=true;

    return result;
}
bool fraction::greaterThan(fraction frac) { //大于运算
    bool result=false;
    if(this->sub(frac).above>0)
        result=true;
    return result;

}
bool fraction::lessThan(fraction frac) {   //小于运算
    bool result=false;

    if(this->sub(frac).above<0)
        result=true;

    return result;

}

void fraction::display() {
    cout<<this->above;
    if(this->below!=1)
        cout<<"/"<<this->below;
}

struct ax {
    fraction a,c;
    int k;
};

ax num[100000];

stack <int> sta;
int main() {
    //freopen("equation.in","r",stdin);
    //freopen("equation.out","w",stdout);
    string s;
    int t=0;
    fraction zero=fraction(0,1);
    fraction one =fraction(1,1);
    while(cin>>s) {
        if(s[0]<='9'&&s[0]>='0') {
            num[t].a=fraction(0,1);
            num[t].c=fraction(s[0]-'0',1);
            num[t].k=0;
            sta.push(t);
            t++;
        } else if(s[0]=='+') {
            int i=sta.top() ;
            sta.pop();
            int j=sta.top() ;
            sta.pop();
            num[j].a = num[j].a.add(num[i].a);
            num[j].c = num[j].c.add(num[i].c);
            sta.push(j);
        } else if(s[0]=='-') {
            int i=sta.top() ;
            sta.pop();
            int j=sta.top() ;
            sta.pop();
            num[j].a = num[j].a.sub(num[i].a);
            num[j].c = num[j].c.sub(num[i].c);
            sta.push(j);
        } else if(s[0]=='*') {
            int i=sta.top() ;
            sta.pop();
            int j=sta.top() ;
            sta.pop();
            if(num[i].a.equal(zero)) {
                num[j].a = num[j].a.mul(num[i].c);
                num[j].c = num[j].c.mul(num[i].c);
                sta.push(j);
            } else if(num[j].a.equal(zero)) {
                num[i].a = num[i].a.mul(num[j].c);
                num[i].c = num[i].c.mul(num[j].c);
                sta.push(i);
            }
        } else if(s[0]=='/') {
            int i=sta.top() ;
            sta.pop();
            int j=sta.top() ;
            sta.pop();
            if(num[i].c.equal(zero)) {
                num[i].a=num[j].c;
                num[i].k=1;
                num[i].c=zero;
                sta.push(i);
            } else {
                num[j].a = num[j].a.div(num[i].c);
                num[j].c = num[j].c.div(num[i].c);
                sta.push(j);
            }
        } else if(s[0]=='X') {
            num[t].a=fraction(1,1);
            num[t].c=fraction(0,1);
            num[t].k=0;
            sta.push(t);
            t++;
        } else if(s[0]=='E')break;
//        int q=sta.top();
//        num[q].a.display();
//        cout<<' ';
//        num[q].c.display();
//        cout<<endl;
    }
    int ans=sta.top();
    if(num[ans].k) {
        if(num[ans].a.equal(zero)&&num[ans].c.equal(zero)) {
            puts("MULTIPLE");
            return 0;
        }
        if(num[ans].a.equal(zero)||num[ans].c.equal(zero)) {
            puts("NONE");
            return 0;
        }
        fraction X = num[ans].a.mul(zero.sub(num[ans].c));
        X.display();
        cout<<endl;
        return 0;
    } else {
        if(num[ans].a.equal(zero)&&num[ans].c.equal(zero)) {
            puts("MULTIPLE");
            return 0;
        }
        if(num[ans].a.equal(zero)) {
            puts("NONE");
            return 0;
        }
        cout<<"X = ";
        fraction X=zero.sub(num[ans].c).mul(one.div(num[ans].a));
        X.display();
        cout<<endl;
        return 0;
    }
}
/*
4 X * 2 + 2 /
E

2 2 *
E

0 2 X / *
E
*/
