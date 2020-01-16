#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

int n;
double dp[3010],x,ans;

int main()
{
    cin>>n; dp[0]=1;
    FOR(i,0,n)
    {
        cin>>x;
        for(int j=i+1;j>0;j--)
        {
            dp[j]=x*dp[j-1]+(1-x)*dp[j];
        }
        dp[0]=(1-x)*dp[0];
    }
    FOR(i,n/2+1,n+1) ans+=dp[i];
    cout << setprecision(10)<<ans<<'\n';

    return 0;
}