#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define M 1000000007
#define N 3010
using namespace std;

ll n,ans,dp[N][N];
string s;

int main()
{
    cin>>n>>s; 
    s="  "+s; 
    dp[1][1]=1;
    FOR(i,1,n+1)
    {
        if(s[i]=='<') FOR(j,2,i+1) dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%M;
        else if(s[i]=='>') for(int j=i;j>0;j--) dp[i][j]=(dp[i-1][j]+dp[i][j+1])%M;
    }
    FOR(i,1,n+1) ans=(ans+dp[n][i])%M;
    cout<<ans<<'\n';

    return 0;
}