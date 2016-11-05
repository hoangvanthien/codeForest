#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<(y); ++i)
#define pb push_back
#define maxN 200005

int n,type,h[maxN],a[5][5],Ans;

void init()
{
    freopen("xepgach.inp", "r", stdin);
    freopen("xepgach.out", "w", stdout);
    scanf("%d%d", &n, &type);
    FOR(i,0,n) scanf("%d", &h[i]);
}

int Look(int Spin, int Size)
{
    int ans = 0;
    FOR(i,0,n)
    {
        int Count = 0;
        int comp = h[i] - a[Spin][0];
        FOR(j,0,Size)
            if (i+j>=n) return ans;
            else
                if (comp == h[i+j]-a[Spin][j]) Count++;
                else break;

        if (Count == Size) ans++;
    }
    return ans;
}

int main()
{
    init();
    Ans = 0;
    switch (type)
    {
    case 1:
        {
            Ans += Look(0,4);
            Ans += Look(1,1);
            break;
        }
    case 2:
        {
            Ans += Look(0,2);
            break;
        }
    case 3:
        {
            a[0][2] = 1;
            a[1][0] = 1;
            Ans += Look(0,3);
            Ans += Look(1,2);
            break;
        }
    case 4:
        {
            a[0][0] = 1;
            a[1][1] = 1;
            Ans += Look(0,3);
            Ans += Look(1,2);
            break;
        }
    case 5:
        {
            a[1][1] = a[2][0] = a[2][2] = a[3][0] = 1;
            Ans += Look(0,3);
            Ans += Look(1,2);
            Ans += Look(2,3);
            Ans += Look(3,2);
            break;
        }
    case 6:
        {
            a[2][1] = a[2][2] = 1;
            a[3][0] = 2;
            Ans += Look(0,3) + Look(1,2) + Look(2,3) + Look(3,2);
            break;
        }
    case 7:
        {
            a[2][0] = a[2][1] = 1;
            a[1][1] = 2;
            Ans += Look(0,3) + Look(1,2) + Look(2,3) + Look(3,2);
            break;
        }

    }
    printf("%d", Ans);
}
