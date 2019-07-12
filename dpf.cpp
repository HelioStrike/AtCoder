#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 3010
using namespace std;

string s,t;
int sl,tl,dp[N][N];

int main()
{
    cin>>s>>t; sl=s.length(),tl=t.length();

    FOR(i,1,sl+1) 
    {
        FOR(j,1,tl+1)
        {
            dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
            if(s[i-1]==t[j-1]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    }

    int r=sl,c=tl;
    string ans="";
    while(r>0&&c>0)
    {
        if(s[r-1]==t[c-1]) { ans=s[r-1]+ans,r--,c--; }
        else if(dp[r-1][c]>dp[r][c-1]) r--;
        else c--;
    }

    cout<<ans<<'\n';

    return 0;
}