#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define ll long long
#define MOD 1000000007
using namespace std;

ll h,w,dp[1010][1010];
string m[1010];

int main()
{
    cin>>h>>w; FOR(i,0,h) cin>>m[i];
    FOR(i,1,h+1)
    {
        FOR(j,1,w+1)
        {
            if(i==1&&j==1) dp[i][j]=1;
            else if(m[i-1][j-1]=='#') dp[i][j]=0;
            else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
        }
    }

    cout<<dp[h][w]<<'\n';

    return 0;
}