#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define M 1000000007
#define N 410
using namespace std;

ll n,k,a[N],dp[N][N];

int main()
{
    cin>>n; FOR(i,1,n+1) cin>>a[i],a[i]+=a[i-1],dp[i][i]=0;
    FOR(i,1,n)
    {
        FOR(j,1,n-i+1)
        {
            dp[j][j+i]=LONG_MAX;
            FOR(k,j,j+i)
            {
                dp[j][j+i]=min(dp[j][j+i],a[j+i]-a[j-1]+dp[j][k]+dp[k+1][j+i]);
            }
        }
    }
    cout<<dp[1][n]<<'\n';

    return 0;
}