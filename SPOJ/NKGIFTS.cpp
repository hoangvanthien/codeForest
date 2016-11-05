#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define maxN 100002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long
 
typedef string bigint;
int k;
LL p,q,u,v;
 
void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
    scanf("%d", &k);
    scanf("%lld%lld%lld%lld", &p, &q, &u, &v);
}
 
bigint strrev(bigint s)
{
    int t = s.length();
    FOR(i,0,t/2-1)
    {
        char temp = s[i];
        s[i] = s[t-i-1];
        s[t-i-1] = temp;
    }
    return s;
}
 
int val(char c)
{
    return c - '0';
}
 
char chr(int i)
{
    return i + '0';
}
 
char addChar(char a, char b, int &carry)
{
    int temp = val(a) + val(b) + carry;
    carry = temp/10;
    return chr(temp%10);
}
 
bigint Add(bigint a, bigint b)
{
    bigint c;
    a = strrev(a); b = strrev(b);
    int i = 0, carry = 0;
    while (i<min(a.length(), b.length()))
    {
        c += addChar(a[i], b[i], carry);
        i ++;
    }
    if (a[i])
        while (a[i]) c+=addChar(a[i++], '0', carry);
    else
        while (b[i]) c+=addChar(b[i++], '0', carry);
    if (carry) c+=chr(carry);
    c = strrev(c);
    return c;
}
 
char mulChar(char a, char b, int &carry)
{
    int temp = val(a) * val(b) +carry;
    carry = temp/10;
    return chr(temp%10);
}
 
bigint Multi(bigint a, bigint b)
{
    bigint c,temp;
    a = strrev(a); b = strrev(b);
    int jb = 0;
    do
    {
        int ja = 0, carry = 0;
        temp = "";
        do
        {
            temp += mulChar(a[ja], b[jb], carry);
            ja ++;
        } while (a[ja]);
        if (carry) temp+=chr(carry);
        temp = strrev(temp);
        if (jb == 0) c = temp;
        else
        {
            FOR(i,1,jb) temp += "0";
            c = Add(c, temp);
        }
        jb ++;
    } while (b[jb]);
    return c;
}
 
char subtChar(char a, char b, int &carry)
{
    int temp = 10 + val(a) - val(b) - carry;
    carry = 1 - temp/10;
    return chr(temp % 10);
}
 
bigint Subt(bigint a, bigint b)
{
    bigint c = "";
    a = strrev(a); b = strrev(b);
    //db(a); db(b);
    int i = 0, carry = 0;
    while (i < min(a.length(), b.length())) {c += subtChar(a[i], b[i], carry);
    i ++;
//    db(c);
    }
    if (a[i])
        while (a[i]) c += subtChar(a[i++], '0', carry);
    else
        while (b[i]) c+= subtChar(b[i++], '0', carry);
    while (c[c.length()-1] == '0') c.erase(c.length()-1, 1);
    c = strrev(c);
    return c;
}
 
void print()
{
 
}
 
int getPart(LL i, LL j, LL Size)
{
    i++; j++;
    if (i<=Size/2 && j<=Size/2) return 4;
    if (i<=Size/2 && j>Size/2) return 1;
    if (i>Size/2 && j<=Size/2) return 3;
    if (i>Size/2 && j>Size/2) return 2;
}
 
void Solve(LL x, LL y)
{
    bigint h = "1", hmax = "1";
    FOR(t,1,k)
    {
        LL S = llround(exp(log(2)*(k-t+1)));
        //db(S);
        switch (getPart(x,y,S))
        {
        case 1:
            {
                y = y - S/2;
                break;
            }
        case 2:
            {
                h = Add(Subt(Multi("2", hmax), h), "1");
                x = (S - x - 1);
                y = y-S/2;
                break;
            }
        case 3:
            {
                h = Add(Multi("2", hmax), h);
                x = S-x-1; y = S-y-1-S/2;
                break;
            }
        case 4:
            {
                h = Add(Subt(Multi("4", hmax), h), "1");
                y = S-y-1-S/2;
                break;
            }
        }
        hmax = Multi(hmax, "4");
    }
    cout<< Add(Subt(hmax,h),"1") << " ";
}
 
int main()
{
	init();
//	cout << Subt("7650035435430002526471232732", "19153500423021");
    Solve(p,q);
    Solve(u,v);
}
 