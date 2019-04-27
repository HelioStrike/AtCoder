#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define ll long long
#define N 101
#define V 100010
using namespace std;

ll n,w,v,x;

int main()
{
    cin>>n>>w;
    ll its[n][2];
    FOR(i,0,n) cin>>its[i][0]>>its[i][1],v+=its[i][1];

    ll inf,dp[n+1][v+1];
    inf=1e14;
    FOR(i,0,n+1) FOR(j,0,v+1) dp[i][j]=inf;

    dp[0][0]=0;
    FOR(i,0,n)
    {
        FOR(j,0,v+1)
        {
            dp[i+1][j]=dp[i][j];
            if(its[i][1]<=j) dp[i+1][j]=min(dp[i+1][j],dp[i][j-its[i][1]]+its[i][0]);
        }
    }
    for(x=v;x>0;x--) if(dp[n][x]<=w) break;
    cout<<x<<'\n';

    return 0;
}