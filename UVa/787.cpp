#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define SSTR( x ) dynamic_cast< std::ostringstream & >( ( std::ostringstream() << std::dec << x ) ).str()
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define maxN 102
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long
#define z '0'

typedef string bigint;

int n, ar[maxN],p[maxN];
II m[maxN];

int val(char c) {return c - z;}
char chr(int x) {return x + z;}

//char compChar(char a, char b)
//{
//    if
//}

bigint pMax(bigint a, bigint b)
{
    if (a.length() > b.length()) return a;
    if (b.length() > a.length()) return b;
    int i = 0;
    while (val(a[i]) == val(b[i]) && i<a.length()) i++;
    if (val(a[i]) > val(b[i])) return a;
    if (val(b[i]) > val(a[i])) return b;
    return a;
}

bigint nMax(bigint a, bigint b)
{
    a[0] = '0'; b[0] = '0';
    bigint c = pMax(a, b);
    if (c==b)
    {
        a[0] = '-';
        return a;
    }
    else
    {
        b[0] = '-';
        return b;
    }
}

bigint iMax(bigint a, bigint b)
{
    if (a[0] == '-' && b[0] != '-') return b;
    if (b[0] == '-' && a[0] != '-') return a;
    if (a[0] == '-' && b[0] == '-') return nMax(a,b);
    return pMax(a,b);
}

bigint strrev(bigint t)
{
//    bigint t;
//    strcpy(t, s);
    int len = t.length();
    FOR(k,0,len/2-1)
    {
        char temp = t[k];
        t[k] = t[len-k-1];
        t[len-k-1] = temp;
        //debug(t);
    }
    return t;
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
    //debug(a); debug(b);
    int i = 0, carry = 0;
    //debug(c);
    while (i < min(a.length(), b.length()))
    {
        c+=addChar(a[i], b[i], carry);
        i++;
    }
    //debug(c);
    if (a[i])
        while (a[i]) c += addChar(a[i++], z, carry);
    else
        while (b[i]) c += addChar(b[i++], z, carry);
    if (carry) c += chr(carry);
    //c[i] = 0;
    c = strrev(c);
    return c;
}

char mulChar(char a, char b, int &carry)
{
    int temp = val(a) * val(b) + carry;
    carry = temp/10;
    return chr(temp%10);
}

bigint Multi(bigint a, bigint b)
{
    bigint temp, c;
//    reverse(a, a+strlen(a)); reverse(b, b+strlen(b));
    if (a == "0" || b == "0") return "0";
    char dau;
    if ((a[0] == '-' && b[0] == '-') || (a[0] != '-' && b[0] != '-')) dau = '+';
    else dau = '-';
    if (a[0] == '-') a.erase(0,1);
    if (b[0] == '-') b.erase(0,1);
    a = strrev(a); b = strrev(b);
    int jb = 0;
    //debug(c);
    do
    {
        int ja = 0, carry = 0;
        temp = "";
        do
        {
            temp += mulChar(a[ja], b[jb], carry);
            //debug(temp);
            ja ++;
        } while (a[ja]);

        if (carry) temp += chr(carry); //++ja;
        //temp[ja] = 0;
        //debug(temp);
        temp = strrev(temp);
        //debug(temp);
        if (jb==0) c = temp;
        else
        {
            FOR(i,1,jb) temp += "0";
            c = Add(c,temp);
        }
        //debug(temp);
        //debug(c);
        jb ++;
    } while (b[jb]);
    if (dau == '+') return c;
    else return "-"+c;
}


void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
}

void print()
{

}

int main()
{
	init();
	int i = 0;
	while (scanf("%d", &ar[i]) != EOF)
    {
        while (ar[i] != -999999) scanf("%d", &ar[++i]);
        int n = i;
        bigint Ans = SSTR(ar[0]);
        bigint temp = "1";
        //stringstream ss;
        FOR(j,0,n-1)
        {
//            ss << ar[j];
//            ss >> temp;
            temp = SSTR(ar[j]);
            Ans = iMax(Ans, temp);
            //debug(temp);
            FOR(k,j+1,n-1)
            {
                //ss << ar[k];
                string temp2 = SSTR(ar[k]);
                //debug(temp2);
//                temp = Multi(temp, ss.str());
                temp = Multi(temp, temp2);
                //debug(temp);
                //debug(Ans);
                Ans = iMax(Ans, temp);

                //debug(Ans);
            }
        }
        cout << Ans << endl;
        i = 0;
    }
    //cout << pMax("55558", "78");
    //cout << Multi("5", "-7");
}
