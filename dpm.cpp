#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define M 1000000007
#define N 105
#define K 100010
using namespace std;

ll n,k,a[N],cnt[K],dp[N][K];

int main()
{
    cin>>n>>k; FOR(i,1,n+1) cin>>a[i];
    dp[0][0]=1;
    FOR(i,1,n+1)
    {
        memset(cnt,0,sizeof(cnt));
        FOR(j,0,k+1) cnt[j]=dp[i-1][j];
        FOR(j,1,k+1) cnt[j]=(cnt[j]+cnt[j-1])%M;
        FOR(j,0,k+1) dp[i][j]=(j<=a[i])?cnt[j]:(cnt[j]-cnt[j-a[i]-1]+M)%M;
    }
    cout<<dp[n][k]<<'\n';

    return 0;
}