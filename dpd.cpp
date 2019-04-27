#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define ll long long
#define N 101
#define W 100010
using namespace std;

int n,w;
ll wi,vi,dp[N][W];

int main()
{
    cin>>n>>w;
    
    FOR(i,0,n)
    {
        cin>>wi>>vi;
        FOR(j,0,w+1)
        {
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            if(j+wi<=w) dp[i+1][j+wi]=max(dp[i+1][j+wi],dp[i][j]+vi); 
        }
    }
    cout<<*max_element(dp[n],dp[n]+w+1)<<'\n';

    return 0;
}