#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define N 200010
using namespace std;

ll c,n,l,r,q[N],h[N],dp[N];

double calc(ll a,ll b)
{
    ll dy=dp[a]+h[a]*h[a]-dp[b]-h[b]*h[b];
    ll dx=h[a]-h[b];
    return (double)dy/dx;
}

int main()
{
    cin>>n>>c;
    FOR(i,0,n) cin>>h[i];
    FOR(i,1,n)
    {
        while(l<r && calc(q[l],q[l+1])<2*h[i]) l++;
        dp[i]=dp[q[l]]+(h[q[l]]-h[i])*(h[q[l]]-h[i])+c;
        while(l<r && calc(q[r-1],q[r])>calc(q[r-1],i)) r--;
        q[++r]=i;
    }
    cout<<dp[n-1]<<'\n';

    return 0;
}