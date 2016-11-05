#include <bits/stdc++.h>

using namespace std;

#define fto(i,x,y) for (int i = (x); i < y; ++i)

bool check[26];
int a[6][6], row[6], col[6];

void print()
{
    for (int i=1; i<=5; ++i)
    {
        for (int j=1; j<=5; ++j)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void attemp(int i, int j)
{
    if (i==6)
    {
        /*for (int x = 1; x <= 5; ++x)
            if (row[x]!=0 || col[x]!=0) return;*/

        if (col[5] == 0) print();
        exit(0);
    }
    int low = max(row[i] - 25*(5-j), max(col[j] - 25*(5-i), 1));
    int high = min(row[i] - (5-j), min(col[j] - (5-i), 25));

    if (low > high || low > 25 || high < 1) return;
    if (j == 5)
    {
        low = row[i];
        high = row[i];
    }

    for (int x = low; (x <= high); ++x)
        //if (!(check[x]))
    {
        a[i][j] = x;
        row[i] -= x;
        col[j] -= x;
        //check[x] = true;
        if (row[i]>=0 && col[j]>=0)
        {
            if (j<5) attemp(i,j+1);
            else attemp(i+1,1);
        }
        //check[x] = false;
        a[i][j] = 0;
        row[i] += x;
        col[j] += x;
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    fto(i,0,5) scanf("%d", &row[i+1]);
    fto(i,0,5) scanf("%d", &col[i+1]);

    attemp(1,1);

    return 0;
}
