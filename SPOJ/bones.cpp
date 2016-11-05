#include <bits/stdc++.h>

using namespace std;

#define fto(i,x,y) for(int i = (x); i < y; ++i)

int s1,s2,s3;
int sum[81];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d",&s1,&s2,&s3);

    fto(i,1,s1+1)
    fto(j,1,s2+1)
    fto(k,1,s3+1)
        sum[i+j+k]++;

    int Max = 0;
    int ans = 0;
    fto(i,3,s1+s2+s3+1)
    {
        if (Max < sum[i])
        {
            Max = sum[i];
            ans = i;
        }
        if (Max == sum[i] && ans > i)
        {
            ans = i;
        }
    }

    printf("%d",ans);
}
